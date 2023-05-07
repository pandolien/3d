#include "pch.h"
#include "Lidar2D.h"
#include "../Random/lRand.h"
Lidar2d::Lidar2d(){
	Initalzation();
}
Lidar2d::~Lidar2d(){
	Close();
}
void Lidar2d::Close(){
	if(Line)delete[](Line);
	Line = NULL;
	if(OutDistance)delete[](OutDistance);
	OutDistance = NULL;
}
void Lidar2d::DeleteFloat(){
	if(OutDistance)delete[](OutDistance);
	OutDistance = NULL;
}
void Lidar2d::Initalzation(){
	Line = NULL;
	OutDistance = NULL;
	noise = 1;
}
void Lidar2d::Noise(float N) {
	noise = N;
}
void Lidar2d::Init(float MaxL,float MinAngle,float MaxAngle){
	Close();
	this->M = MaxL;
	this->MaxAngle = MaxAngle;
	this->MinAngle = MinAngle;
	this->LineLen = (int)(MaxAngle-MinAngle);
	this->Line = new dhVector[this->LineLen];
	this->OutDistance = new float[this->LineLen];
	memset(this->OutDistance,0,sizeof(float)*this->LineLen);
	for(int i = 0; i< this->LineLen;i++){
		this->Line[i].x = cos((MinAngle+i)/(180/PI));
		this->Line[i].y = sin((MinAngle+i)/(180/PI));
		this->Line[i].z = 0;
		this->OutDistance[i] = MaxL;
	}
}
void Lidar2d::Trans(float x,float y,float q){
	dhMat h;
	H01 = h.Trans(x,y,0)*h.RotZ(q);
}
void Lidar2d::T(dhMat Mat){
	//memset(this->OutDistance,this->M,sizeof(float)*this->LineLen);
	H = Mat*H01;
}
void Lidar2d::Sensing(Object *Obj){
	int i,j,F,S;
	dhVector O,Oend,f,s,point;
	O.x = H.v[12];
	O.y = H.v[13];
	for(i = 0; i< LineLen;i++){
		Oend = H*(Line[i]*this->M);
		for(j = 0; j< Obj->LineLen/2;j++){
			F = Obj->Line[j*2];
			S = Obj->Line[j*2+1];
			f = Obj->Ver[F];
			s = Obj->Ver[S];
			point = Intersection(O,Oend,f,s);
			if(Box(O,Oend,point)){
				point = O - point;
				OutDistance[i] = MIN(OutDistance[i],point.Norm());
			}
		}
	}
}
bool Lidar2d::Box(dhVector A,dhVector B,dhVector intersection){
	float xmin,xmax,ymin,ymax;
	bool X,Y;
	xmin = MIN(A.x,B.x);
	xmax = MAX(A.x,B.x);
	ymin = MIN(A.y,B.y);
	ymax = MAX(A.y,B.y);
	if(intersection.x >= xmin&&intersection.x <= xmax){X = true;}
	else {X = false;}
	if(intersection.y >= ymin&&intersection.y <= ymax){Y = true;}
	else {Y = false;}
	return X&Y;
}
dhVector Lidar2d::Intersection(dhVector x1,dhVector x2,dhVector x3,dhVector x4){
	dhVector X = dhVector(0,0);
	float px,py,D;
	px = (x1.x*x2.y-x1.y*x2.x)*(x3.x-x4.x)-(x1.x-x2.x)*(x3.x*x4.y-x3.y*x4.x);
	py = (x1.x*x2.y-x1.y*x2.x)*(x3.y-x4.y)-(x1.y-x2.y)*(x3.x*x4.y-x3.y*x4.x);
	D = (x1.x-x2.x)*(x3.y-x4.y) - (x1.y-x2.y)*(x3.x-x4.x);
	X.x = px/D;
	X.y = py/D;
	return X;
}
float* Lidar2d::SenserData(){
	for (int i = 0; i < LineLen; i++) {

	}
	return OutDistance;
}
int Lidar2d::GetSize(){
	return this->LineLen;
}
/*
#ifdef _WIN32
void Lidar2d::Draw(CDC* pDC) {
	dhVector O = dhVector(H.v[12],H.v[13]),x;
	int i;
	for (i = 0; i < GetSize(); i++) {
		float D = this->OutDistance[i];
		x = Line[i] * D;
		x = H * x;
		pDC->MoveTo(O.x, O.y);
		pDC->LineTo(x.x, x.y);
	}
}

void Lidar2d::Draw(CDC* pDC,float Size) {
	dhVector O = dhVector(H.v[12], H.v[13]), x;
	int i;
	for (i = 0; i < GetSize(); i++) {
		x = Line[i] * (this->M*Size);
		x = H * x;
		pDC->MoveTo(O.x, O.y);
		pDC->LineTo(x.x, x.y);
	}
}
#endif
#ifdef _WIN64
void Lidar2d::Draw(CDC* pDC) {
	dhVector O = dhVector(H.v[12], H.v[13]), x;
	int i;
	for (i = 0; i < GetSize(); i++) {
		float D = this->OutDistance[i];
		x = Line[i] * D;
		x = H * x;
		pDC->MoveTo(O.x, O.y);
		pDC->LineTo(x.x, x.y);
	}
}

void Lidar2d::Draw(CDC* pDC, float Size) {
	dhVector O = dhVector(H.v[12], H.v[13]), x;
	int i;
	for (i = 0; i < GetSize(); i++) {
		x = Line[i] * (this->M * Size);
		x = H * x;
		pDC->MoveTo(O.x, O.y);
		pDC->LineTo(x.x, x.y);
	}
}
#endif
*/