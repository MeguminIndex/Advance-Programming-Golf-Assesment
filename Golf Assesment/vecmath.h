/*------------------------------------------------------------------------
  Header for Some Vector Classes
  ------------------------------------------------------------------------*/
#ifndef vecmat_h_included
#define vecmat_h_included

#include <math.h>
#include "stdafx.h"

/*------------------------------------------------------------------------
	vec2 : 2d Vector
  ------------------------------------------------------------------------*/
class vec2
{
public:
	double 	elem[2];

public:
    vec2(){}
    vec2(double x, double y){elem[0]=x; elem[1]=y;}
    vec2(double x){elem[0]=elem[1]=x;}

    double operator()(int x) const {return elem[x];}
    double &operator()(int x) {return elem[x];}

    vec2 operator *(const double x) const {vec2 res(*this); res.elem[0]*=x; res.elem[1]*=x; return res;}
    vec2 operator /(const double x) const {vec2 res(*this); res.elem[0]/=x; res.elem[1]/=x; return res;}
    vec2 operator +(const vec2 &x) const {vec2 res(*this); res.elem[0]+=x.elem[0]; res.elem[1]+=x.elem[1]; return res;}
    vec2 operator -(const vec2 &x) const {vec2 res(*this); res.elem[0]-=x.elem[0]; res.elem[1]-=x.elem[1]; return res;}
    vec2 operator -() const {vec2 res(*this); res.elem[0] = - res.elem[0]; res.elem[1] = -res.elem[1]; return res;}
    vec2 &operator *=(const double x) {elem[0]*=x; elem[1]*=x; return (*this);}
    vec2 &operator /=(const double x) {elem[0]/=x; elem[1]/=x; return (*this);}
    vec2 &operator +=(const vec2 &x) {elem[0]+=x.elem[0]; elem[1]+=x.elem[1]; return (*this);}
    vec2 &operator -=(const vec2 &x) {elem[0]-=x.elem[0]; elem[1]-=x.elem[1]; return (*this);}
    bool operator ==(const vec2 &x) const {return((elem[0] == x.elem[0])&&(elem[1] == x.elem[1]));}

    double Magnitude(void) const {return(sqrt((elem[0]*elem[0])+(elem[1]*elem[1])));}
    double Magnitude2(void) const {return((elem[0]*elem[0])+(elem[1]*elem[1]));}
    double Normalise(void) { double x = Magnitude(); elem[0]/=x; elem[1]/=x; return x;}
    vec2 Normalised(void) const {vec2 res(*this); res.Normalise(); return res;}

    double Dot(const vec2 &x) const {return ( (elem[0]*x.elem[0]) + (elem[1]*x.elem[1]) );}


};

/*------------------------------------------------------------------------
	vec3 : 3d Vector
  ------------------------------------------------------------------------*/
class vec3
{
public:
	double 	elem[3];

public:
    vec3(){}
    vec3(double x, double y, double z){elem[0]=x; elem[1]=y;elem[2]=z;}
    vec3(double x){elem[0]=elem[1]=elem[2]=x;}

    double operator()(int x) const {return elem[x];}
    double &operator()(int x) {return elem[x];}

    vec3 operator *(const double x) const {vec3 res(*this); res.elem[0]*=x; res.elem[1]*=x; res.elem[2]*=x; return res;}
    vec3 operator /(const double x) const {vec3 res(*this); res.elem[0]/=x; res.elem[1]/=x; res.elem[2]/=x; return res;}
    vec3 operator +(const vec3 &x) const {vec3 res(*this); res.elem[0]+=x.elem[0]; res.elem[1]+=x.elem[1]; res.elem[2]+=x.elem[2]; return res;}
    vec3 operator -(const vec3 &x) const {vec3 res(*this); res.elem[0]-=x.elem[0]; res.elem[1]-=x.elem[1]; res.elem[2]-=x.elem[2]; return res;}
    vec3 &operator *=(const double x) {elem[0]*=x; elem[1]*=x; elem[2]*=x; return (*this);}
    vec3 &operator /=(const double x) {elem[0]/=x; elem[1]/=x; elem[2]/=x; return (*this);}
    vec3 &operator +=(const vec3 &x) {elem[0]+=x.elem[0]; elem[1]+=x.elem[1]; elem[2]+=x.elem[2]; return (*this);}
    vec3 &operator -=(const vec3 &x) {elem[0]-=x.elem[0]; elem[1]-=x.elem[1]; elem[2]-=x.elem[2]; return (*this);}

    double Magnitude(void) const {return(sqrt((elem[0]*elem[0])+(elem[1]*elem[1])+(elem[2]*elem[2])));}
    double Magnitude2(void) const {return((elem[0]*elem[0])+(elem[1]*elem[1])+(elem[2]*elem[2]));}
    double Normalise(void) { double x = Magnitude(); elem[0]/=x; elem[1]/=x; elem[2]/=x; return x;}
    vec3 Normalised(void) const {vec3 res(*this); res.Normalise(); return res;}

    double Dot(const vec3 &x) const {return ( (elem[0]*x.elem[0]) + (elem[1]*x.elem[1]) + (elem[2]*x.elem[2]) );}
    vec3 Cross(const vec3 &x) const
    {
    	vec3 res;
    	res.elem[0] = elem[1]*x.elem[2] - elem[2]*x.elem[1];
    	res.elem[1] = elem[2]*x.elem[0] - elem[0]*x.elem[2];
    	res.elem[2] = elem[0]*x.elem[1] - elem[1]*x.elem[0];
		return res;
    }


	vec3 Abs()
	{
		return vec3(fabs(elem[0]), fabs(elem[1]), fabs(elem[2]));
	};


	vec3 Clamp(vec3 lb, vec3 up)
	{
		vec3 returnedVec;

		returnedVec(0) = std::fmin(std::fmax(elem[0], lb(0)), up(0));
		returnedVec(1) = std::fmin(std::fmax(elem[1], lb(1)), up(1));
		returnedVec(2) = std::fmin(std::fmax(elem[2], lb (2)), up(2));

		return returnedVec;
	}

	//my clamp

	//vec3 Clamp(vec3 vec, vec3 min,vec3 max)
	//{
	//	return min(max(vec, min), max);

	//}


};

#endif