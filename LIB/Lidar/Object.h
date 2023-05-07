#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../3d/dhVector.h"
#include "../3d/dhMat.h"
/*
#ifdef _WIN32
#include <afxwin.h>
#endif
#ifdef _WIN64
#include <afxwin.h>
#endif
*/
class Object{
public:
	Object();
	~Object();
public:
	int *Line;
	int LineLen;
	dhVector *Ver;
	int VerLen;
	dhMat H;
public:
	void Initialzation();
	void Init(int, int);
	void Close();
	virtual void map();
	void T(dhMat);
};
#endif
