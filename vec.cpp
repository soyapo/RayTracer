#include <iostream>
#include <math.h>
#include <stdlib.h>

class Vec{
public:
    Vec() {}
    Vec(double x, double y, double z){e[0] = x, e[1] = y, e[2] = z;}
        
    inline float x() const {return e[0];}
    inline float y() const {return e[1];}
    inline float z() const {return e[2];}
    inline float r() const {return e[0];}
    inline float g() const {return e[1];}
    inline float b() const {return e[2];}

    inline const Vec& operator + () const {return *this;}
    inline Vec operator-() const {return Vec(-e[0], -e[1], -e[2]);}
    inline double  operator[](int i) const {return e[i];}
    inline double& operator[](int i) {return e[i];}

    inline Vec& operator += (const Vec &v);
    inline Vec& operator -= (const Vec &v);
    inline Vec& operator *= (const Vec &v);
    inline Vec& operator /= (const Vec &v);
    inline Vec& operator *= (const double n);
    inline Vec& operator /= (const double n);

    friend inline Vec operator + (const Vec &v1, const Vec &v2){
        return Vec(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
    }
    friend inline Vec operator - (const Vec &v1, const Vec &v2){
        return Vec(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
    }
    friend inline Vec operator * (const Vec &v1, const Vec &v2){
        return Vec(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
    }
    friend inline Vec operator / (const Vec &v1, const Vec &v2){
        return Vec(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
    }
    friend inline Vec operator * (const Vec &v1, double d){
        return Vec(v1.e[0] * d, v1.e[1] * d, v1.e[2] * d);
    }
    friend inline Vec operator / (const Vec &v1, double d){
        return Vec(v1.e[0] / d, v1.e[1] / d, v1.e[2] / d);
    }

    inline double Length() const {return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);}
    inline double Squared() const {return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];}

    inline double Dot(const Vec &v1, const Vec &v2){
        return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
    }
    inline Vec Cross(const Vec &v1, const Vec &v2){
        return Vec( (v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
                  (-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
                    (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
    }

    double e[3];
};

inline Vec UnitVector(const Vec &v){
        return v / v.Length();
}