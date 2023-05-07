#include "pch.h"
#include "Object.h"
Object::Object() {
	Initialzation();
}
Object::~Object() {
	Close();
}
void Object::Initialzation() {
	Line = NULL;
	LineLen = 0;
	Ver = NULL;
	VerLen = 0;
}
void Object::Init(int Ln, int Vn) {
	Close();
	Line = new int[Ln];
	LineLen = Ln;
	Ver = new dhVector[Vn];
	VerLen = Vn;
}
void Object::Close() {
	if (Line) delete[](Line);
	Line = NULL;
	if (Ver) delete[](Ver);
	Ver = NULL;
	LineLen = 0;
	VerLen = 0;
}
void Object::map() {
	Init(4*2, 4);
	Ver[0] = dhVector(-20, -20);
	Ver[1] = dhVector(-20, 20);
	Ver[2] = dhVector(20, 20);
	Ver[3] = dhVector(20, -20);

	Line[0] = 0;
	Line[1] = 1;

	Line[2] = 1;
	Line[3] = 2;

	Line[4] = 2;
	Line[5] = 3;

	Line[6] = 3;
	Line[7] = 0;
}
void Object::T(dhMat h) {
	int i;
	for (i = 0; i < VerLen; i++) {
		Ver[i] = h * Ver[i];
	}
}
/*
#ifdef _WIN32
void Object::Draw(CDC* pDC) {
	int i;
	for (i = 0; i < LineLen / 2; i++) {
		pDC->MoveTo(Ver[Line[i * 2 + 0]].x, Ver[Line[i * 2 + 0]].y);
		pDC->LineTo(Ver[Line[i * 2 + 1]].x, Ver[Line[i * 2 + 1]].y);
	}
}
void Object::Draw(CDC* pDC,float Size) {
	int i;
	for (i = 0; i < LineLen / 2; i++) {
		pDC->MoveTo(Ver[Line[i * 2 + 0]].x, Ver[Line[i * 2 + 0]].y);
		pDC->LineTo(Ver[Line[i * 2 + 1]].x, Ver[Line[i * 2 + 1]].y);
	}
}
#endif
*/