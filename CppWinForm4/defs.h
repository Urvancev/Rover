#pragma once

/*
* ����� �������������� �� ��������� UDP
* �� �������� ������ - �����
*
* ����������������� ���������:
*      sync_t
* ������������ ������ ��� � ���� ������, ������������ ��� �������������
* ������� �������� ������ ���������� ���������
* ���� ����� �����������, ��������� �����������
* ���� ������ �������� ����������� �� ���������� 5 ������ ������ ����� ��������� ����������
*
* ���������:
*      dvs_stat_t
*      akb_stat_t
*      acs_stat_t
*      arms_stat_t
*      navi_stat_t
* ������������ ������ �� ���������� (��� ��������� ����������), ����������� ��� � ���� ������ ����������,
* ������� �� ��������� �������� ������ ��������� + ������� (2 �����)
* ���� ����� �����������, ��������� �����������
* ���� ������ �������� ����������� �� ���������� 5 ������ ������ ����� ��������� ����������
*
* ��������� dvs_com_t �������� ��������� ���������� (�� �������� �����)
* � ������ ������������ � �������� ��� ������������� ����������
* ���������� �� ���������� (��� ��������� ���������� ���������),
* �� ���� ��� ��� � ���� ������ ���������� (���������������� 100 ���)
* ������� �� ��������� �������� ������ ��������� + ������� (2 �����)
* ���� ����� �����������, ��������� �����������
* ���� ������ �������� ����������� �� ���������� 500 ��� ����� ��������� ����������
*
* ��������� telemtr_t ���������� �� �������(������ � �������� �� �����)
* �������� �������� ������ � ����� ��������
*/

// ����������������� ��������� 2 bytes
struct sync_t {
	char index;                     // ������ ��������� 'S'
	unsigned char seq;              // ����������� �������
};

//��������� ��������� ���������� 50 bytes
struct dvs_stat_t {
	char index;                     // ������ ��������� 'D'
	unsigned char seq;              // ����������� �������

	short rpm[4];                   // ������� ����������
	short temp[4];                  // ����������� ����������
	unsigned char enable[4];        // ����������� ����������

	short contrl_temp[4];           // ����������� ������������ ����������
	unsigned short I[4];            // ���� �� ������������

	short angl[4];                  // ���� �������� �������������
	unsigned char enable_servo[4];  // ����������� �������������
};

// ������� �� ��������� 20 bytes
struct dvs_com_t {
	char index;             // ������ ��������� 'C'
	unsigned char seq;      // ����������� �������

	unsigned short com[4];  // ������� �� ���������
	unsigned char r;        // ����� ������ ����������

	short angl[4];          // ������� �� ������������
};

// ��������� ��� 16 bytes
struct akb_stat_t {
	char index;             // ������ ��������� 'B'
	unsigned char seq;      // ����������� �������

	unsigned char enable;   // ����������� ���
	short temp;             // ����������� ���
	unsigned char charge_level;   // ������� ������ � ���������

	unsigned char volt;     // ������� ���������� ���
	unsigned int capasity;  // ������� ���
	unsigned char I;        // ��� �������
};
// ��������� �������������� 26 bytes
struct acs_stat_t {
	char index;             // ������ ��������� 'A'
	unsigned char seq;      // ����������� �������

	short angl[3];          // ���� ������� ������
	short accel[3];         // ��������� ��� ���� ����

	unsigned char enable[4];       // �����������
	short temp[4];          // ����������� ��������������
};
// ��������� ������� ���������� 8 bytes
struct arms_stat_t {
	char index;             // ������ ��������� 'H'
	unsigned char seq;      // ����������� �������

	unsigned short sig[2];  // ������� � ����� ����������
	unsigned char enable[2];// ���������
};
// ��������� ��������� 88 bytes
struct navi_stat_t {
	char index;             // ������ ��������� 'N'
	unsigned char seq;      // ����������� �������

	unsigned int distance; // ���������� ����
	unsigned int x[10];     // ���������� X
	unsigned int y[10];     // ���������� Y
};

// ������ ���������� 122 bytes
struct telemtr_t {
	char index;             // ������ ��������� 'T'
	unsigned char seq;      // ����������� �������

	unsigned short content[60]; // ������ ����������
};
