#include <bits/stdc++.h>
#include "vec.cpp"
#include "ray.cpp"

using namespace std;
#define fst ios_base::sync_with_stdio(0); cin.tie(NULL);

Vec Color(const ray &r){
    Vec UnitDir = UnitVector(r.dir());
}

int main(){
    fst

    int Width, Height, r, g, b = 0.5 * 255.99; 
    cin>>Width>>Height;

    ofstream ppm("init.ppm", ios::out);
    ppm<<"P3\n"<<Width<<' '<<Height<<"\n255\n";

    for(float i = 0; i < Width; i++){
        for(float j = 0; j < Height; j++){
            r = 255.99 * (i / Width);
            g = 255.99 * (j / Height);
            ppm<<r<<' '<<g<<' '<<b<<'\n';
        }
    }

    ppm.close();
    return 0;
}