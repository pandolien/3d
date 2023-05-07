	#ifndef __LPTRLIST_H__
#define __LPTRLIST_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _BLOCK{
	_BLOCK *nPerv;
	_BLOCK *nNext;
	void *Data;
}BLOCK;
class lPTRList{
public:
	lPTRList();
	lPTRList(void *);
	~lPTRList();
public:
	BLOCK *pHead;
	BLOCK *pTail;
	BLOCK *pFind;
	int Len;
	int FindNum;
public:
	void Init(void *);
	void Initialzation();
	void RemoveAll();
	void RemoveAll2();
	void RemoveTail();
	void RemoveTail2();
	void RemoveHead();
	void RemoveHead2();
	void Remove(int);
public:
	void AddTail(void *);
	void AddHead(void *);
	void* GetAt(int);
	void* GetAt(void*);
	int GetSize();
	///Data Finding///
};

#endif
