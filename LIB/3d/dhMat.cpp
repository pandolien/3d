#include "pch.h"
#include "dhMat.h"
dhMat::dhMat()
{
    int i,j,cnt = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i == j) v[cnt++] = 1;
            else v[cnt++] = 0;
        }
    }
}


dhMat::~dhMat()
{

}




dhMat dhMat::operator*(dhMat h)
{
    dhMat Out;
    int i, j, k, cnt = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            float val = 0;
            for (k = 0; k < 4; k++) {val += v[k * 4 + j] * h.v[i * 4 + k];}
            Out.v[cnt++] = val;
        }
    }
    return Out;
}

dhVector dhMat::operator*(dhVector l)
{
    dhVector V;
    V.x = l.x * v[0] + l.y * v[4] + l.z * v[8] + 1 * v[12];
    V.y = l.x * v[1] + l.y * v[5] + l.z * v[9] + 1 * v[13];
    V.z = l.x * v[2] + l.y * v[6] + l.z * v[10] + 1 * v[14];
    return V;
}

dhMat dhMat::Trans(float x, float y,float z)
{
    dhMat h;
    h.v[12] = x;
    h.v[13] = y;
    h.v[14] = z;
    return h;
}
//angle is Radian
dhMat dhMat::RotX(float angle)
{
    dhMat h;
    float s, c;
    s = sin(angle);
    c = cos(angle);
    h.v[5] = c;
    h.v[9] = -s;
    h.v[6] = s;
    h.v[10] = c;
    return h;
}

dhMat dhMat::RotY(float angle)
{
    dhMat h;
    float s, c;
    s = sin(angle);
    c = cos(angle);
    h.v[0] = c;
    h.v[8] = s;
    h.v[2] = -s;
    h.v[10] = c;
    return h;
}


dhMat dhMat::RotZ(float angle)
{
    dhMat h;
    float s, c;
    s = sin(angle);
    c = cos(angle);
    h.v[0] = c;
    h.v[4] = -s;
    h.v[1] = s;
    h.v[5] = c;
    return h;
}

dhMat dhMat::Inv()
{
    dhMat ret;
    ret.v[0] = v[0];
    ret.v[1] = v[4];
    ret.v[2] = v[8];

    ret.v[4] = v[1];
    ret.v[5] = v[5];
    ret.v[6] = v[9];

    ret.v[8] = v[2];
    ret.v[9] = v[6];
    ret.v[10] = v[10];
    dhVector Vt = O()*-1.0;
    dhVector Vt2 = ret * Vt;
    ret.v[12] = Vt2.x;
    ret.v[13] = Vt2.y;
    ret.v[14] = Vt2.z;
    return ret;
}

_RPY dhMat::RPY()
{
    _RPY abr;
    float cr31;
    abr.b = atan2(-v[2], sqrt(v[0] * v[0] + v[1] * v[1]));
    cr31 = cos(abr.b);
    abr.a = atan2(v[1] / cr31, v[0] / cr31);
    abr.r = atan2(v[6] / cr31, v[10] / cr31);
    return abr;
}
void dhMat::Hmatrix(float x, float y, float z, float a, float b, float r)
{
    dhMat h;
    h	 = h.Trans(x,y,z)*h.RotZ(a)*h.RotY(b)*h.RotX(r);
    memmove(v, h.v, sizeof(float) * 16);
}

dhVector dhMat::O()
{
    dhVector h;
    h.x = v[12];
    h.y = v[13];
    h.z = v[14];
    return h;
}


