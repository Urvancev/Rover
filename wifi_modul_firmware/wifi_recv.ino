#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

/* данные сети ровера */
const char *ssid = "Rover";
const char *password = "12345678";

WiFiUDP Udp;
IPAddress Ip(192, 168, 1, 1);
IPAddress NMask(255, 255, 255, 0);
int port=9010;

SoftwareSerial mserial(D10,D11); // D10 - ; D11 - 

char buf[100];
int num;

void udp_trans()
{
  if( mserial.read() == '*')
    {
      num = 0;
      memset(buf,'\0',sizeof(buf));
      char b;
      while(b != '#')
      {
        if (mserial.available())
        {
          b = mserial.read();
          buf[num] = b;
          num++;
        }
      }
      Serial.print("buf = ");
      Udp.beginPacket("192.168.1.100", 12345);
      for (int i = 0; i < num - 1; i++)
      {
        Udp.write(buf[i]);
        Serial.write(buf[i]);
      }
      Udp.endPacket();
      Serial.println("");
    }
}

void setup() {
  Serial.begin(9600);
  mserial.begin(115200);
  WiFi.softAPConfig(Ip, Ip, NMask);
  WiFi.softAP(ssid, password);
  int i = Udp.begin(port);
  Serial.printf("\n i = %d Now listening at IP %s, UDP port %d\n",i, WiFi.softAPIP().toString().c_str(), 9010);
}

void loop() {
  if (mserial.available()) {
    udp_trans();
  }
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    int l = Udp.read(buf,packetSize);
    mserial.write('*');
    for (int i = 0; i <= packetSize; i++)
    {
      mserial.write(buf[i]);
    }
    mserial.write('#');
  }
  delay(1);
}
