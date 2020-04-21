#pragma once
struct Complex {
    float x;
    float y;
};

struct Vector {
    float x;
    float y;
};

struct Circule {
    Vector Center;
    float Radius;
};

void swap(int*, int*);

void swap(int&, int&);

void abss(float*);

void abss(float&);

void multy(Complex*, float);

void multy(Complex&, float);

void offsett(Circule*, Vector*);

void offsett(Circule&, Vector&);
