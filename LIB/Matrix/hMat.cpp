//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hMat.h"
	

hMat::hMat(){
	Initalization();
	NoTemp();
}
hMat::hMat(int r,int c){
	Initalization();
	Init(r,c);
}
hMat::hMat(hMat &h){
	Initalization();
	Close();
	Init(h.Row,h.Col);
	memmove(v,h.v,sizeof(float)*Row*Col);
	NoTemp();
	if(h.isTemp()) h.CloseTemp();
	
}
hMat::hMat(const hMat &h){
	Initalization();
	Close();
	Init(h.Row,h.Col);
	memmove(v,h.v,sizeof(float)*Row*Col);
	NoTemp();
	
	//if(h.isTemp()) h.CloseTemp();
}
hMat::~hMat(){
	if(isTemp())return;
	Close();
}
void hMat::Initalization(){
	v = NULL;
	Row = 0;
	Col = 0;
}
void hMat::Init(int r,int c){
	Close();
	Row = r;
	Col = c;
	v = new double[r*c];
}
void hMat::Close(){
	if(v) delete(v);
	v = NULL;
	Row = 0;
	Col = 0;
}

BOOL hMat::In(int r,int c,double D){
	if(r >= Row) return false;
	if(c >= Col) return false;
	v[c*Row+r] = D;
	NoTemp();
	return true;	
}

double hMat::Out(int r,int c){
	NoTemp();
	return v[c*Row+r];
}
hMat hMat::Multiplication(hMat h){
	int i,j,k,cnt = 0;
	hMat Mat;
	if(Col == h.Row){
		Mat.Init(Row,h.Col);
		for(i = 0;i<h.Col;i++){
			for(j = 0; j < Row;j++){
				double Sum = 0;
				for(k = 0; k< Col;k++) Sum+= v[k*Row+j]*h.v[i*h.Row+k];
				Mat.v[cnt++] = Sum;
			}
		}
	}
	NoTemp();
	//Mat.Temp();
	if(h.isTemp()) h.CloseTemp();
	return Mat;
}
hMat hMat::Addlition(hMat &h){
	int i;
	hMat Mat;
	if(Row == h.Row&&Col == h.Col){
		Mat.Init(Row,Col);
		for(i = 0; i< Row*Col;i++) Mat.v[i] = v[i] + h.v[i];
	}
	NoTemp();
	//Mat.Temp();
	if(h.isTemp()) h.CloseTemp();
	return Mat;
}
hMat hMat::Subtraction(hMat &h){
	int i;
	hMat Mat;
	if(Row == h.Row&&Col == h.Col){
		Mat.Init(Row,Col);
		for(i = 0; i< Row*Col;i++) Mat.v[i] = v[i] - h.v[i];
	}
	NoTemp();
	//Mat.Temp();
	if(h.isTemp()) h.CloseTemp();
	return Mat;
}
void hMat::Equal(hMat h){
	Close();
	Initalization();
	Init(h.Row,h.Col);
	memmove(v,h.v,sizeof(double)*Row*Col);
	NoTemp();
	if(h.isTemp()) h.CloseTemp();
}


hMat hMat::operator *(hMat h){
	hMat Mat = Multiplication(h);
	//Mat.Temp();
	if (h.isTemp()) h.CloseTemp();
	return Mat;
}

hMat hMat::operator +(hMat &h){
	return Addlition(h);
}
hMat hMat::operator -(hMat &h){
	return Subtraction(h);
}
void hMat::operator =(hMat h){
	Equal(h);
}

void hMat::SVD(hMat &U,hMat &S,hMat& Vt){
	int m,n;
	
}

void hMat::Print(){
	int i,j,cnt = 0;
	printf("\n");
	for(i = 0; i < Col;i++){
		for(j = 0;j < Row;j++){
			printf("%f \t",v[j*Col+i]);
			//printf("%f \t",v[cnt++]);
		}
		printf("\n");
	}
	NoTemp();
}


