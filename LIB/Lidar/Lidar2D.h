#ifndef __LIDAR_2D_H__
#define __LIDAR_2D_H__
#include <math.h>
#include <string.h>
/*
#ifdef _WIN32
#include <afxwin.h>
#endif
#ifdef _WIN64
#include <afxwin.h>
#endif
*/
#include "../3d/dhVector.h"
#include "../3d/dhMat.h"
#include "Object.h"

#define PI 3.141592

class Lidar2d{
public:
	Lidar2d();
	~Lidar2d();
public:
	dhMat H01;
	dhMat H;
	dhVector *Line;
	int LineLen;
	float MinAngle;
	float MaxAngle;
	float M;
	float *OutDistance;
	float noise;
public:
	void Close();
	void DeleteFloat();
	void Initalzation();
	void Init(float,float,float);
	void Trans(float,float,float);
	void Noise(float);
public:
	void T(dhMat);
	void Sensing(Object *);
	bool Box(dhVector,dhVector,dhVector);
	dhVector Intersection(dhVector,dhVector,dhVector,dhVector);
	float* SenserData();
	int GetSize();
	/*
#ifdef _WIN32
	void Draw(CDC*);
	void Draw(CDC*,float);
#endif
#ifdef _WIN64
	void Draw(CDC*);
	void Draw(CDC*, float);
#endif
	*/
};
#endif	
