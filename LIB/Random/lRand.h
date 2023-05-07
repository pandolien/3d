#include <math.h>
#include <stdio.h>
#include <stdlib.h>
extern double Rand(){
	return rand()/RAND_MAX;
}
extern double Randn(){
	double u,v,r;
	while(1){
		u = 2*(rand()/(double)RAND_MAX)-1;
		v = 2*(rand()/(double)RAND_MAX)-1;
		r = u*u+v*v;
		if(r  == 0|| r >1)continue;
		break;
	}
	r = sqrt(-2*log(r)/r);
	r = u*r;
	return r;
}
