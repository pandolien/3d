#include "pch.h"
#include "lPTRList.h"
lPTRList::lPTRList(){
	Initialzation();
}
lPTRList::lPTRList(void *D){
	Initialzation();
	Init(D);
}
lPTRList::~lPTRList(){
	RemoveAll2();
}
void lPTRList::Initialzation(){
	this->pHead = NULL;
	this->pTail = NULL;
	this->pFind = NULL;
	this->Len = 0;
	this->FindNum = -1;
}
void lPTRList::Init(void *Dt){
	pHead = new BLOCK;
	pHead->nPerv = NULL;
	pHead->nNext = NULL;
	pHead->Data = Dt;
	pTail = pHead;
	Len = 1;
}
void lPTRList::RemoveAll(){
	BLOCK *Tep;
	if(pHead == NULL &&pTail == NULL) return;
	while(1){
		Tep = pHead->nNext;
		pHead->Data = NULL;
		pHead->nNext = NULL;
		delete(pHead);
		pHead = Tep;
		if(pHead == NULL) break;
		Tep->nPerv = NULL;
	}
	pTail = NULL;
	pFind = NULL;
	Len = 0;
	FindNum = -1;
}

void lPTRList::RemoveAll2(){
	BLOCK *Tep;
	if(pHead == NULL &&pTail == NULL) return;
	while(1){
		Tep = pHead->nNext;
		if(pHead->Data)delete(pHead->Data);
		pHead->Data = NULL;
		pHead->nNext = NULL;
		delete(pHead);
		pHead = Tep;
		if(pHead == NULL) break;
		Tep->nPerv = NULL;
	}
	pTail = NULL;
	pFind = NULL;
	Len = 0;
	FindNum = -1;
}
void lPTRList::RemoveTail(){	
	if(pHead == NULL &&pTail == NULL) return;
	
	if(pHead == pTail){
		pTail = NULL;
		pTail->Data = NULL;
		delete(pHead);
		pHead = NULL;
	}
	else{
		BLOCK *Tep;
		Tep = pTail->nPerv;
		Tep->nNext = NULL;
		pTail->nPerv = NULL;
		pTail->Data = NULL;
		delete(pTail);
		pTail = Tep;
		Tep= NULL;
	}
	Len -=1;
}
void lPTRList::RemoveTail2(){	
	if(pHead == NULL &&pTail == NULL) return;
	
	if(pHead == pTail){
		pTail = NULL;
		pTail->Data = NULL;
		delete(pHead);
		pHead = NULL;
	}
	else{
		BLOCK *Tep;
		Tep = pTail->nPerv;
		Tep->nNext = NULL;
		pTail->nPerv = NULL;
		if(pTail->Data)delete(pTail->Data);
		pTail->Data = NULL;
		delete(pTail);
		pTail = Tep;
		Tep= NULL;
	}
	Len -=1;
}
void lPTRList::RemoveHead(){
	if(pHead == NULL &&pTail == NULL) return;
	
	if(pHead == pTail){
		pTail = NULL;
		pTail->Data = NULL;
		delete(pHead);
		pHead = NULL;
	}
	else{
		BLOCK *Tep;
		Tep = pHead->nNext;
		Tep->nPerv = NULL;
		pHead->nNext = NULL;
		//if(pHead->Data)delete(pHead->Data);
		pHead->Data = NULL;
		delete(pHead);
		pHead = Tep;
		Tep= NULL;
	}
	Len -=1;
}

void lPTRList::RemoveHead2(){
	if(pHead == NULL &&pTail == NULL) return;
	
	if(pHead == pTail){
		pTail = NULL;
		pTail->Data = NULL;
		delete(pHead);
		pHead = NULL;
	}
	else{
		BLOCK *Tep;
		Tep = pHead->nNext;
		Tep->nPerv = NULL;
		pHead->nNext = NULL;
		if(pHead->Data)delete(pHead->Data);
		pHead->Data = NULL;
		delete(pHead);
		pHead = Tep;
		Tep= NULL;
	}
	Len -=1;
}
void lPTRList::AddTail(void *Dt){
	BLOCK *ND = new BLOCK;
	ND->Data = Dt;
	ND->nNext = NULL;
	ND->nPerv = NULL;
	if(pHead == NULL) pHead = ND;
	if(pTail){
		pTail->nNext = ND;
		ND->nPerv = pTail;
	}
	pTail = ND;	
	Len+=1;
}
void lPTRList::AddHead(void* Dt){
	BLOCK *ND = new BLOCK;
	ND->Data = Dt;
	ND->nNext = NULL;
	ND->nPerv = NULL;
	if(pTail == NULL) pTail = ND;
	if(pHead){
		pHead->nPerv = ND;
		ND->nNext = pHead;
	}
	pHead = ND;
	Len+=1;
}
void* lPTRList::GetAt(void *Dt){
	BLOCK *Tep;
	if(pHead == NULL &&pTail == NULL) return NULL;
	Tep = pHead;
	while(1){
		if(Tep->Data == Dt) return Tep->Data;
		Tep = Tep->nNext;
		if(Tep = NULL) return NULL;
	}
}
void* lPTRList::GetAt(int i){
	BLOCK *Tep;
	int n = 0;
	if(pHead == NULL &&pTail == NULL) return NULL;
	if(i < 0) return NULL;
	if(i >= Len) return NULL;
	Tep = pHead;
	while(1){
		if(i == n) return Tep->Data;
		Tep = Tep->nNext;
		n +=1;
		if(Tep == NULL) return NULL;
	}
}
int lPTRList::GetSize(){
	return Len;
}
