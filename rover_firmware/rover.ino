#include <Wire.h>
#include <math.h> 
#include <TroykaIMU.h>

// акселерометр 20,21 пин
// силовые ключи 50,51,52,53 пин
// потенциометры (ручки) А0,А1 пин
// двигатели 10,11,12,13 пин

Accelerometer accel;

// синхронизационное сообщение 2 bytes
struct sync_t {
    char index;                     // индекс сообщения 'S'
    unsigned char seq;              // циклический счетчик
} sync;

//структура состояния двигателей 50 bytes
struct dvs_stat_t {
    char index;                     // индекс сообщения 'D'
    unsigned char seq;              // циклический счетчик

    short rpm[4];                   // обороты двигателей [об/мин]
    short temp[4];                  // температуры двигателей [градусы цельсия]
    unsigned char enable[4];        // исправность двигателей

    short contrl_temp[4];           // температура контроллеров двигателей [градусы цельсия]
    unsigned short I[4];            // токи на контроллерах [ампер]

    short angl[4];                  // углы поворота сервоприводов [градусы]
    unsigned char enable_servo[4];  // исправность сервоприводов
} dvs_stat;

// команда на двигатели 20 bytes
struct dvs_com_t {
    char index;             // индекс сообщения 'C'
    unsigned char seq;      // циклический счетчик

    unsigned short com[4];  // команда на двигатели
    unsigned char r;        // Режим работы двигателей 0 - 1 ручка - 4 дв вперед, 1 - назад, 2,3 - тоже но по wifi

    short angl[4];          // команда на сервоприводы
} dvs_com;

// состояние АКБ 16 bytes
struct akb_stat_t {
    char index;             // индекс сообщения 'B'
    unsigned char seq;      // циклический счетчик

    unsigned char enable;   // исправность АКБ
    short temp;             // температура АКБ [градусы цельсия]
    unsigned char charge_level;   // уровень заряда в процентах

    unsigned char volt;     // текущее напряжение АКБ [вольт]
    unsigned int capasity;  // емкость АКБ [а*ч]
    unsigned char I;        // ток разряда [ампер]
} akb_stat;
// состояние акселерометров 26 bytes
struct acs_stat_t {
    char index;             // индекс сообщения 'A'
    unsigned char seq;      // циклический счетчик

    short angl[3];          // углы наклона ровера [градусы]
    short accel[3];         // ускорения про трем осям [м/с^2]

    unsigned char enable[4];       // исправность
    short temp[4];          // температуры акселерометров [градусы цельсия]
} acs_stat;
// состояние органов управления 8 bytes
struct arms_stat_t {
    char index;             // индекс сообщения 'H'
    unsigned char seq;      // циклический счетчик

    unsigned short sig[2];  // сигналы с ручек управления
    unsigned char enable[2];// состояние
} arms_stat;
// состояние навигации 88 bytes
struct navi_stat_t {
    char index;             // индекс сообщения 'N'
    unsigned char seq;      // циклический счетчик

    unsigned int distance; // пройденный путь
    unsigned int x[10];     // координата X
    unsigned int y[10];     // координата Y
} navi_stat;

// прочая телеметрия 122 bytes
struct telemtr_t {
    char index;             // индекс сообщения 'T'
    unsigned char seq;      // циклический счетчик

    unsigned short content[60]; // прочая телеметрия
} telemtr;

struct sys_t {
  int Sseq;
  int Dseq;
  int Aseq;
  int Bseq;
} sys;

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
  sync.index = 'S';
  dvs_stat.index = 'D';
  akb_stat.index = 'B';
  acs_stat.index = 'A';
  arms_stat.index = 'H';
  navi_stat.index = 'N';

  dvs_com.r = 0;

  for(int i = 0; i < 4; i++) {
    dvs_com.com[i] = 0;
  }

  accel.begin();
  // устанавливаем чувствительность акселерометра
  // 2g — по умолчанию, 4g, 8g
  accel.setRange(RANGE_2G);

  // задаем пины для переключения заднего или переднего хода
  pinMode(42,OUTPUT);
  pinMode(48,OUTPUT);
  pinMode(44,OUTPUT);
  pinMode(46,OUTPUT);
  // задаем пины для двигателей
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  
}


void acceleromer()
{
acs_stat.accel[0]=accel.readAX();
acs_stat.accel[1]=accel.readAY();
acs_stat.accel[2]=accel.readAZ();

acs_stat.angl[0]=180*(atan(acs_stat.accel[0]/(sqrt(sq(acs_stat.accel[1])+sq(acs_stat.accel[2])))))/M_PI;
acs_stat.angl[1]=180*(atan(acs_stat.accel[1]/(sqrt(sq(acs_stat.accel[0])+sq(acs_stat.accel[2])))))/M_PI;
acs_stat.angl[2]=180*(atan(acs_stat.accel[2]/(sqrt(sq(acs_stat.accel[0])+sq(acs_stat.accel[1])))))/M_PI;
}  

void send_mess(void* str,int len,unsigned char &seq) {
  char buf[len];
  memcpy(buf,str,len);
  Serial1.write('*');
  for (int i = 0; i < len; i++) {
    Serial1.write(buf[i]);
  }
  Serial1.write('#');
  seq++;
  if(seq >= 255) {
    seq = 0;
  }
}

int mess_back() {
  if (Serial1.available()){
    if (Serial1.read() == '*') {
      int n = 0;
      char b;
      char buf[100];
      Serial.print("buf = ");
      while(b != '#') {
        if (Serial1.available()) {
          b = Serial1.read();
          if (b != '#'){
            buf[n] = b;
            n++;
            Serial.write(b);
          }
        }
      }
      Serial.println("");
      Serial.print("buf 0 = ");
      Serial.println(buf[0]);
      switch(buf[0]) {
        case 'S':
          sys.Sseq = 0;
          Serial.println("S");
          break;
        case 'D':
          sys.Dseq = 0;
          Serial.println("D");
          break;
        case 'B':
          sys.Bseq = 0;
          break;
        case 'C':
          send_mess(buf,2,dvs_com.seq);
          memcpy(&dvs_com, buf, sizeof(dvs_com));
          break;
      }
    }
  }
}
int cicle;
void connection() {

  cicle++;
  if (cicle >= 2){
    cicle = 0;
    
    sys.Sseq++;
    send_mess(&sync,sizeof(sync),sync.seq);
    delay(10);
    mess_back();
    
    if (sys.Sseq <= 5) {
      /*sys.Dseq++;
      send_mess(&dvs_stat,sizeof(dvs_stat),dvs_stat.seq);
      delay(10);
      mess_back();*/

      /*sys.Bseq++;
      send_mess(&akb_stat,sizeof(akb_stat),akb_stat.seq);
      delay(10);
      mess_back();*/

      sys.Aseq++;
      send_mess(&acs_stat,sizeof(acs_stat),acs_stat.seq);
      delay(10);
      mess_back();

      //for (int i = 0; i < 4; i++) {
      //  dvs_com.com[i] = 0;
      //}
    }else {
      if (dvs_com.r > 1) {
        for (int i = 0; i < 4; i++) {
          dvs_com.com[i] = 0;
        }
      }
    }
  }
  mess_back();
  delay(1);
  mess_back();
  delay(1);
  mess_back();
  delay(1);
  mess_back();
  delay(1);
  mess_back();
  delay(1);
  mess_back();
  delay(1);
  mess_back();
  delay(1);
  mess_back();
  delay(1);
  mess_back();
}
double revK1 = 0;
double revK2 = 0;
void change_r() {
  if ( dvs_com.r%2 == 0) {
    digitalWrite(42, HIGH);
    digitalWrite(48, LOW);
    digitalWrite(46, HIGH);
    digitalWrite(44, LOW);
    revK1 = 1/5;
    revK2 = 0;
  } else if (dvs_com.r%2 == 1) {
      digitalWrite(42, LOW);
      digitalWrite(48, HIGH);
      digitalWrite(46, LOW);
      digitalWrite(44, HIGH);
      revK1 = 0;
      revK2 = 1/5;
  }
}

void read_hands() { // читаем данные с потенциометров
  if (dvs_com.r == 0 || dvs_com.r == 1) {
    int c = analogRead(A0);
    for (int i = 0; i < 4; i++) {
      dvs_com.com[i] = c;
    }
    c = analogRead(A1);
    if (c > 600) {
      dvs_com.com[0] -= c - 600;
      dvs_com.com[1] += c - 600;
      dvs_com.com[2] -= c - 600;
      dvs_com.com[3] += c - 600;
    }else if(c < 400) {
      dvs_com.com[0] += 400 - c;
      dvs_com.com[1] -= 400 - c;
      dvs_com.com[2] += 400 - c;
      dvs_com.com[3] -= 400 - c;
    }
  }
}

unsigned short command[4];

void engine0 (){      //пишем данные на двигатели
 int n = 1023/35;
 int k;
 if (dvs_com.com[0] >= 10) {
  k = 70;
 } else {
  k = 0;
 }
   if (dvs_com.com[0]<716){
  command[0]= k + dvs_com.com[0]/n + (dvs_com.com[0]/n)*revK2;
   } else command[0]=k + 716/n;
   
   if (dvs_com.com[1]<716){
  command[1]= k + dvs_com.com[1]/n + (dvs_com.com[1]/n)*revK1;
   } else command[1]=k + 716/n;
   
   if (dvs_com.com[2]<716){
  command[2]= k + dvs_com.com[2]/n;
   } else command[2]=k + 716/n;

   if (dvs_com.com[3]<716){
  command[3]= k + dvs_com.com[3]/n;
   } else command[3]=k + 716/n;
   
   analogWrite(13,command[0]);
   analogWrite(12,command[1]);
   analogWrite(11,command[2]);
   analogWrite(10,command[3]);
}

void loop() {
  connection();
  acceleromer();
  change_r();
  read_hands();
  Serial.print("com     0 = ");
  Serial.println(dvs_com.com[0]);
  Serial.print("command 0 = ");
  Serial.println(command[0]);
  Serial.print("r = ");
  Serial.println(dvs_com.r);
  engine0();
  //Serial.print("X angl = ");
  //Serial.println(acs_stat.angl[0]);
  delay(100);
}
