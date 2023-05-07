#ifndef __HPTRLIST_H__
#define __HPTRLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/***
	writer 	: Hyenseong LEE
	content 	: basic List
	
		_|-|_
		(0 0)
		 |v|	hi hi hi hi hi hi hi hi 
		  - 
		--|-- 
		  |
		  ^
		 / |
***/
typedef struct _BLOCK{
	_BLOCK * pNext;
	_BLOCK * pPerv;
	void *Data;
}BLOCK;
class hPTRList{
public:
	hPTRList();
	virtual ~hPTRList();
public:
	BLOCK *pHead;
	BLOCK *pTail;
	int N;
public:
	void Initialzation();
	virtual void Delete(BLOCK*,bool);
	void RemoveAll();
	void RemoveAll2();
	void DeleteNum(int,bool);
	void DeleteTail(bool);
	void DeleteHead(bool);
	void AddTail(void *);
	void* GetAt(int n);
};
#endif
