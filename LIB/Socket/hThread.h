#ifndef __HTHREAD_H__
#define __HTHREAD_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN32
	#include <windows.h>
#else
	#include <pthread.h>
#endif
/***
	writer 	: Hyenseong LEE
	content 	: Inherited Thread Class
	add to cmakelists.txt
	->find_package(Threads)
	->target_link_libraries(filename ${CMAKE_THREAD_LIBS_INIT})
		_|-|_
		<0v0>
		--|--
		  |  
		  ^
		 / |
***/
class hThread{
public:
	hThread();
	virtual ~hThread();
public:
	#ifdef WIN32
		HANDLE trd;
		DWORD trdID;
	#else
		pthread_t trd;
	#endif
	bool ThreadPlag;
public:
	#ifdef WIN32
		virtual DWORD run();
		static DWORD WINAPI run_(void*);
	#else
		virtual void run();
		static void* run_(void*);
	#endif
	void ThreadStart();
	void ThreadStop();
};
#endif
