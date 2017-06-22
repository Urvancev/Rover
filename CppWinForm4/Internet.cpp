#include<stdio.h>
#include<winsock2.h>
#include <Ws2tcpip.h> 
#include <iostream>
#include <string>
#include <sstream>
#include "Internet.h"

//#include <thread>
//#include <mutex>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
//std::mutex mutex;

//using namespace std;
#define BUFLEN 512  //Max length of buffer
#define PORT 12345   //The port on which to listen for incoming data

//struct dvs_stat_t dvs_stat_t;
unsigned long nb = 1;
struct sync_t sync_t1;
struct dvs_stat_t dvs_stat_t1;
struct akb_stat_t akb_stat_t1;
struct acs_stat_t acs_stat_t1;
struct arms_stat_t arms_stat_t1;
struct navi_stat_t navi_stat_t1;
struct dvs_com_t dvs_com_t1;
struct telemtr_t telemtr_t1;
bool connceted = true;
bool i = true;
int I = 0;
bool sended = true;
bool closedform = false;
int threadFunction()
{
	SOCKET s;
	struct sockaddr_in server, si_other;
	int slen, recv_len;
	char buf[BUFLEN];
	WSADATA wsa;
	slen = sizeof(si_other);

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		system("pause");
		exit(EXIT_FAILURE);

	}
	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
		system("pause");
	}
	printf("Socket created.\n");

	//Prepare the sockaddr_in structure
	unsigned ip_address;
	inet_pton(AF_INET, "127.0.0.1", &ip_address);//192.168.1.100//127.0.0.1
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = ip_address;
	server.sin_port = htons(PORT);

	//Bind
	if (bind(s, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		system("pause");
		exit(EXIT_FAILURE);

	}
	puts("Bind done");






	//keep listening for data
	while (1)
	{
		//printf("Waiting for data...");
		//fflush(stdout);

		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);

		//try to receive some data, this is a blocking call
		if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
		{
			
			if ((I<=15)&&(I >= 10))
			{
				Sleep(1000);
				if (I == 15) {
					connceted = false;
				}

			}
			I++;
		}
		else
		{
			I = 0;
			connceted = true;
		}
		if (i == true)
		{

			
			if (ioctlsocket(s, FIONBIO, (unsigned long *)&nb) == SOCKET_ERROR)
			{
				printf("error 2\n");
				system("pause");
			}
			i = false;
		}

		switch (buf[0])
		{
		case 'S':
			memcpy((char *)&sync_t1, buf, sizeof(buf));
			sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);
			break;
		case 'D':
			memcpy((char *)&dvs_stat_t1, buf, sizeof(buf));
			sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);

			break;
		//case 'C':
			//memcpy((char *)&dvs_com_t1.index, buf, sizeof(buf));
			//sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);
//
			//break;
		case 'B':
			memcpy((char *)&akb_stat_t1, buf, sizeof(buf));
			sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);

			break;
		case 'A':
			memcpy((char *)&acs_stat_t1, buf, sizeof(buf));
			sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);

			break;
		case 'H':
			memcpy((char *)&arms_stat_t1, buf, sizeof(buf));
			sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);

			break;
		case 'N':
			memcpy((char *)&navi_stat_t1, buf, sizeof(buf));
			sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);

			break;
		case 'T':
			memcpy((char *)&telemtr_t1, buf, sizeof(buf));
			sendto(s, buf, 2, 0, (struct sockaddr*) &si_other, slen);

			break;
		}
		////”правление
		if(sended==false)
		{
			
			memcpy(buf, (char *)&dvs_com_t1,  sizeof(buf));
			sendto(s, buf, sizeof(dvs_com_t1), 0, (struct sockaddr*) &si_other, slen);
			sended = true;
			Sleep(5);
		}
		


		//print details of the client/peer and the data received
		//printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
		//printf("Data: %s\n", (char *)&sync_t1);

		//now reply the client with the same data
		//		if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
		//{
		//	//printf("sendto() failed with error code : %d", WSAGetLastError());
		//	//system("pause");
		//	//exit(EXIT_FAILURE);
		//}
		if (closedform == true) {
			break;
		}
	}
	
	closesocket(s);
	WSACleanup();

	return 0;
}