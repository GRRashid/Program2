#include "proceduring.h"

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void abss(float* a) {
    int b = (int)*a;
    *a = (float)b;
}

void abss(float& a) {
    int b = (int)a;
    a = (float)b;
}

void multy(Complex* a, float b) {
    *a = {(*a).x * b , (*a).y};
}

void multy(Complex& a, float b) {
    a = {a.x*b, a.y};
}

void offsett(Circule* a, Vector* b) {
    *a = {Vector {(*a).Center.x + (*b).x, (*a).Center.y + (*b).y}, (*a).Radius};
}

void offsett(Circule& a, Vector& b) {
    a = {Vector {a.Center.x + b.x, a.Center.y + b.y}, a.Radius};
}
