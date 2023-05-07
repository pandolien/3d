#ifndef __HMAT_H__
#define __HMAT_H__
/*
	make lee.hyen.soeng
	hantech lib
	Matrix lib
*/
//typedef bool BOOL;	
typedef bool BOOL;
#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)
class hMat{
	public:
		hMat();
		hMat(int,int);
		hMat(hMat &);
		hMat(const hMat &);
		~hMat();
	public:
		double *v;
		int Row ,Col;
	public:	
		BOOL temp;
		void Temp(){temp = true;}
		void NoTemp(){temp = false;}
		BOOL isTemp(){return temp;}
		void CloseTemp(){if(isTemp()){Close();}}
	public:
		void Initalization();
		void Init(int,int);
		void Close();
		BOOL In(int,int,double);
		double Out(int,int);
	public:
		//operation
		hMat Multiplication(hMat);
		hMat Addlition(hMat &);
		hMat Subtraction(hMat &);
		void Equal(hMat);
		hMat operator +(hMat &);
		hMat operator -(hMat &);
		hMat operator *(hMat );
		void operator =(hMat );
		void SVD(hMat &,hMat &,hMat &);
		hMat PInv();
		void Print();
};

#endif
