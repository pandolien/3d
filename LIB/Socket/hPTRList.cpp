#include "hPTRList.h"
hPTRList::hPTRList(){
	Initialzation();
}
hPTRList::~hPTRList(){
	RemoveAll2();
}
void hPTRList::Initialzation(){
	pHead = NULL;
	pTail = NULL;
	N = 0;
}
void hPTRList::Delete(BLOCK* block,bool Del){
	if(Del){if(block->Data) delete(block->Data);}
}
void hPTRList::RemoveAll(){
	BLOCK *Tep = NULL;
	if(pHead == NULL&&pTail == NULL) return;	
	while(1){
		Tep = pHead->pNext;
		Delete(pHead,false);
		pHead->Data = NULL;
		if(pHead) delete(pHead);
		pHead = Tep;
		if(Tep == NULL)break;
	}
	pTail = NULL;
	N = 0;	
}
void hPTRList::RemoveAll2(){
	BLOCK *Tep = NULL;
	if(pHead == NULL&&pTail == NULL) return;	
	while(1){
		Tep = pHead->pNext;
		if(Tep)Tep->pPerv = NULL;
		Delete(pHead,true);
		
		pHead->Data = NULL;
		if(pHead) delete(pHead);
		pHead = Tep;
		if(Tep == NULL)break;
	}
	pTail = NULL;
	N = 0;	
}
void hPTRList::DeleteNum(int n,bool Del){
	if(pHead == NULL&&pTail == NULL) return;
	
	if(n == 0)DeleteHead(Del);
	else if(n == N-1) DeleteTail(Del);
	else if(n < 0)return;
	else if(n >= N)return;
	else{
		int i = 1;
		BLOCK *L,*R;
		BLOCK *Tep = pHead->pNext;
		while(1){
			if(i == n) break;
			Tep = Tep->pNext;
			if(Tep == NULL) return;
		}
		L = Tep->pPerv;
		R = Tep->pNext;
		Delete(Tep,Del);
		Tep->Data = NULL;
		Tep->pPerv = NULL;
		Tep->pNext = NULL;
		delete(Tep);
		L->pNext = R;
		R->pPerv = L;
	}
	n -=1;
}
void hPTRList::DeleteTail(bool Del){
	BLOCK *Tep;
	if(pHead == NULL&&pTail == NULL) return;
	if(N == 1){
		pHead = NULL;
		Delete(pTail,Del);
		pTail->Data = NULL;
		delete(pTail);
		pTail = NULL;
	}
	else{
		Tep = pTail->pPerv;
		Delete(pTail,Del);
		pTail->Data = NULL;
		pTail->pPerv = NULL;
		Tep->pNext = NULL;
		delete(pTail);
		pTail = Tep;
	}
	N -=1;
	
}
void hPTRList::DeleteHead(bool Del){
	BLOCK *Tep;
	if(pHead == NULL&&pTail == NULL) return;
	if(N == 1){
		pHead = NULL;
		Delete(pTail,Del);
		pTail->Data = NULL;
		delete(pTail);
		pTail = NULL;
	}
	else{
		Tep = pHead->pNext;
		Delete(pHead,Del);
		pHead->Data = NULL;
		pHead->pNext = NULL;
		Tep->pPerv = NULL;
		delete(pHead);
		pHead = Tep;
		
	}
}
void hPTRList::AddTail(void *D){
	BLOCK *New = new BLOCK;
	New->pNext = NULL;
	New->pPerv = NULL;
	New->Data = D;
	if(pTail){ 
		pTail->pNext = New;
		New->pPerv = pTail;
		pTail = New;
	}
	else	pTail = New;
	if(pHead == NULL) pHead = New;
	N +=1;
}
void *hPTRList::GetAt(int n){
	BLOCK *Tep = NULL;
	int cnt = 1;
	if(pHead == NULL&&pTail == NULL) return NULL;
	if(n < 0)	return NULL;
	if(n > N-1) 	return NULL;
	if(n == 0)	return pHead->Data;
	if(n == N-1) 	return pTail->Data;
	Tep = pHead->pNext;
	while(1){
		if(cnt == n) return Tep->Data; 
		Tep = Tep->pNext;
		cnt +=1;
	}
}
