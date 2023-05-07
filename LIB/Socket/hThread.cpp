#include "hThread.h"
hThread::hThread(){
}
hThread::~hThread(){
}
#ifdef WIN32
	DWORD hThread::run(){
		ThreadPlag = false;
		return 0;
	}
	DWORD WINAPI run_(void *hthread){
		hThread *This = (hThread*)hthread;
		while(This->ThreadPlag){
			This->run();
		}
		return 0;
	}
#else
	void hThread::run(){
	}
	void* hThread::run_(void* hthread){
		hThread *This = (hThread*)hthread;
		while(This->ThreadPlag){
			This->run(); 
		}
		return NULL;
	}
#endif
void hThread::ThreadStart(){
	
		ThreadPlag = true;
	#ifdef WIN32
		trd = CreateThread(NULL,0,run_,this,0,&trdID);
		GetExitCodeThread(trd,&trdID);
	#else
		pthread_create(&trd,0,&hThread::run_,(void*)this);
	#endif
}
void hThread::ThreadStop(){
	if(ThreadPlag){
		ThreadPlag = false;
		#ifdef WIN32
			CloseHandle(trd);
		#else
			pthread_join(trd,NULL);
		#endif
	}	
}
