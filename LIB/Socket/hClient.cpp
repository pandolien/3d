#include "hClient.h"
hTCPClinet::hTCPClinet(){
}
hTCPClinet::~hTCPClinet(){
}
void hTCPClinet::Initialzation(){
	Server = NULL;
	Error = false;
	memset(&sAddr,0,sizeof(SOCKADDR_IN));
	memset(&sock,0,sizeof(SOCKET));
}
void hTCPClinet::Init(hThread* Sv,SOCKET* Clinet,SOCKADDR_IN* Addr){
	Server = Sv;
	memmove(&sock,Clinet,sizeof(SOCKET));
	memmove(&sAddr,Addr,sizeof(SOCKADDR_IN));
}
void hTCPClinet::Close(){
	#ifdef WIN32
		closesocket(sock);
		WSACloeanup();
	#else
		close(sock);
	#endif
	ThreadStop();
}
#ifdef WIN32
DWORD hTCPClinet::run(){
	Recv();
	Send();
}

DWORD hTCPClinet::Recv(){
	return 0;
}
DWORD hTCPClinet::Send(){
	return 0;
}
#else
void hTCPClinet::run(){
	Recv();
	Send();
}
int hTCPClinet::Recv(){
	char buf[1024];
	memset(buf,0,sizeof(char)*1024);
	return read(sock,buf,1024);
}
int hTCPClinet::Send(){
	char buf[1024];
	memset(buf,0,sizeof(char)*1024);
	return write(sock,buf,1024);
}

#endif
