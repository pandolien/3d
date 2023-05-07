#include "hSocket.h"
hSocket::hSocket(){
	Initialzation();
}
hSocket::~hSocket(){
	Close();
}
void hSocket::Initialzation(){
	AcceptNum = 0;
	Mode = 0;
	ConnectCnt = 0;
	SocketCreate = false;
}
int hSocket::Init(int Mode,int Port,int AcceptNum){
	this->Mode = Mode;
	this->AcceptNum = AcceptNum;
	switch(Mode){
		case TCPIP_S://TCP Server
			TCPServerSet(Port);
		break;
		case TCPIP_C://TCP Clinet
			this->Mode = -1;
			SocketCreate = false;
			return 0;
		break;
		case UDP_S://UDP Server
			UDPServerSet(Port);
		break;
		case UDP_C://UDP Client
			this->Mode = -1;
			SocketCreate = false;
			return 0;
		break;
	}
	return 1;
}
int hSocket::Init(int Mode,char*IP,int Port){
	this->Mode = Mode;
	switch(Mode){
		case TCPIP_S://TCP Server
			return 0;
		break;
		case TCPIP_C://TCP Clinet
			TCPClientSet(IP,Port);
		break;
		case UDP_S://UDP Server
			return 0;
		break;
		case UDP_C://UDP Client
			UDPClientSet(IP,Port);
		break;
	}
	
	return 1;
}
void hSocket::Close(){
	if(SocketCreate){
		switch(Mode){
			case 1:
			hclilist.RemoveAll2();
			ThreadStop();
			break;
			case 2:
			#ifdef WIN32
				closesocket(sock);
				WSACloeanup();
			#else
				close(sock);
			#endif
			SocketCreate = false;
			break;
			case 3:
			break;
			case 4:
			break;		
		}
	}
}
int hSocket::TCPServerSet(int Port){
	#ifdef WIN32
		if(WSAStartup(MAKEWORD(2,2),&wsaData) != 0){
			SocketCreate = false;	
			return -1;
		}
	#endif
	sock = socket(PF_INET,SOCK_STREAM,0);
	if(sock < 0){
		#ifdef WIN32
			WSACloeanup();
		#endif
		SocketCreate = false;
		return -1;
	}
	memset(&sAddr,0,sizeof(SOCKADDR_IN));
	sAddr.sin_family = AF_INET;
	sAddr.sin_port = htons(Port);
	sAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sock,(SOCKADDR*)&sAddr,sizeof(sAddr)) != 0){
		Close();
		return -1;	
	}
	if(listen(sock,AcceptNum) != 0){
		Close();
		return -1;
	}
	SocketCreate = true;
	ThreadStart();
	return 0;
}
int hSocket::TCPClientSet(char *IP,int Port){
	return 0;
}
int hSocket::UDPServerSet(int Port){
	return 0;
}
int hSocket::UDPClientSet(char *IP,int Port){
	return 0;
}
#ifdef WIN32
void hSocket::Connecting(){
	SOCKET Cli;
	SOCKADDR_IN CAddr;
	hTCPClinet *Client;
	unsigned int size;
	if(AcceptNum > ConnectCnt){
		size = sizeof(SOCKADDR_IN);
		Cli = accept(sock,(SOCKADDR*)&CAddr,&size);
		Client = new hTCPClinet;
		Client->Initialzation();
		Client->Init(this,&Cli,&CAddr);
		Client->ThreadStart();
	}		
	return 0;
}
DWORD hSocket::run(){
	switch(Mode){
		case TCPIP_S://TCP Server
			Connecting();
		break;
		case TCPIP_C://TCP Clinet
		break;
		case UDP_S://UDP Server
		break;
		case UDP_C://UDP Client
		break;
	}
	return 0;
}
#else
void hSocket::Connecting(){
	SOCKET Cli;
	SOCKADDR_IN CAddr;
	hTCPClinet *Client;
	unsigned int size;
	if(AcceptNum > ConnectCnt){
		size = sizeof(SOCKADDR_IN);
		Cli = accept(sock,(SOCKADDR*)&CAddr,&size);
		printf("Accept");
		Client = new hTCPClinet;
		Client->Initialzation();
		Client->Init(this,&Cli,&CAddr);
		Client->ThreadStart();
		hclilist.AddTail(Client);
		ConnectCnt+=1;
	}
}
void hSocket::run(){
	switch(Mode){
		case TCPIP_S://TCP Server
			Connecting();
		break;
		case TCPIP_C://TCP Clinet
		break;
		case UDP_S://UDP Server
		break;
		case UDP_C://UDP Client
		break;
	}
	usleep(10000);
}
#endif
hClientList::hClientList(){
	Initialzation();
}
hClientList::~hClientList(){
	RemoveAll2();
}
void hClientList::Delete(BLOCK*block,bool Del){
	if(Del){
		hTCPClinet *Tep = (hTCPClinet*)block->Data;
		if(Tep){
			Tep->Close();
			delete(Tep);
		}
	}
}

