#include "pch.h"
#include "uCam.h"
uCam::uCam() {
    int i, j, cnt = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) v[cnt++] = 1;
            else v[cnt++] = 0;
        }
    }
    Set();
}
uCam::~uCam() {
	
}

void uCam::Set()
{
    n = 1;
    f = 65535;
    l = -1;
    r = 1;
    t = 1;
    b = -1;
    v[0] = 1;
    v[5] = 1;
    v[10] = (n + f) /( n - f);
    v[11] = -1;
    v[14] = (2 * n * f) / (n - f);
    v[15] = 0;
}


