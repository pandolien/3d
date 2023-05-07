#ifndef __HSOCKET_H__
#define __HSOCKET_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32
	#include <windows.h>
	#include <winsock2.h>
	#pragma comment(lib,"ws2_32.lib")
#else
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	typedef int SOCKET;
	typedef struct sockaddr_in SOCKADDR_IN;
	typedef struct sockaddr SOCKADDR;
	typedef unsigned int DWORD;
	typedef unsigned short WORD;
	typedef unsigned char BYTE;
#endif
	
#include "hThread.h"
#include "hClient.h"
#include "hPTRList.h"
#define TCPIP_S 	1
#define TCPIP_C 	2
#define UDP_S		3
#define UDP_C		4
/***
	writer 	: Hyenseong LEE
	content 	: Continuous connection type code (window and Linux)
	add to cmakelists.txt
	->find_package(Threads)
	->target_link_libraries(filename ${CMAKE_THREAD_LIBS_INIT})
		  
		_|-|_
		<0v0>	hi hi hi hi hi hi hi hi hi hi hi hi hi hi
		--|-- 
		  |  
		  ^
		 / |
	Mode < 0
		ERROR
	Mode == -1
		no ip specified
	Mode == -2
		net Connect Count
		
***/

class hClientList:public hPTRList{
public:
	hClientList();
	~hClientList();
public:
	void Delete(BLOCK*,bool);
};
class hSocket:public hThread{
public:
	hSocket();
	virtual ~hSocket();
public:
	#ifdef WIN32
		WSADATA wsaData;
	#endif
	SOCKET sock;
	SOCKADDR_IN sAddr;
	hClientList hclilist;
	int AcceptNum,Mode;
	int ConnectCnt;
	bool SocketCreate;
public:
	virtual void Initialzation();
	int Init(int,int,int);
	int Init(int,char*,int);
	void Close();
protected:
	int TCPServerSet(int);
	int TCPClientSet(char*,int);
	int UDPServerSet(int);
	int UDPClientSet(char*,int);
public:
#ifdef WIN32
	virtual void Connecting();
	DWORD run();
#else
	virtual void Connecting();
	void run();
#endif
public:
	int Send(BYTE *);
	int Recv(BYTE *);
};


#endif
