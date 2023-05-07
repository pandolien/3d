#ifndef __UCAM_H__
#define __UCAM_H__
#include "3d/dhMat.h"
class uCam:public dhMat
{
public:
	uCam();
	~uCam();
public:
	int n, f;
	int l, r, t, b;
public:
	void Set();
	
};
#endif

