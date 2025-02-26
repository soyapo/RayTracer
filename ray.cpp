#include "Vec.cpp"

class ray{
public:
    ray(){}
    ray(const Vec &a, const Vec &b){A = a, B = b;}
    
    Vec org() const {return A;}
    Vec dir() const {return B;}
    Vec point(double t) const {return A + B * t;}

    Vec A, B;
};
