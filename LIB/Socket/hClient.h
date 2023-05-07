#ifndef __HCLIENT_H__
#define __HCLIENT_H__

#include "Socket/hThread.h"
#include "hSocket.h"
#include "hPTRList.h"


class hTCPClinet:public hThread{
public:
	hTCPClinet();
	virtual ~hTCPClinet();
public:
	SOCKET sock;
	SOCKADDR_IN sAddr;
	bool Error;
	hThread *Server;
public:
	void Initialzation();
	void Init(hThread*,SOCKET*,SOCKADDR_IN*);
	virtual void Close();
#ifdef WIN32
	DWORD run();
	virtual DWORD Recv();
	virtual DWORD Send();	 
#else
	void run();
	virtual int Recv();
	virtual int Send();

#endif
};


#endif
