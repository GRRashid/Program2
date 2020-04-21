#ifndef PROGRAMMING_PROCEDURING_H
#define PROGRAMMING_PROCEDURING_H

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


#endif //PROGRAMMING_PROCEDURING_H
