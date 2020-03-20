#include <cmath>
#include "virtual.h"
#include <iostream>
Circle::Circle(CVector2D Cen, double R, double mass) {
    Center = Cen;
    Radius = R;
    mass_ = mass;
}
double Circle::square() {
    return M_PI * Radius * Radius;
}
double Circle::perimeter() {
    return M_PI * Radius * 2;
}

double Circle::mass() const {
    return mass_;
}

CVector2D Circle::position() {
    return Center;
}

bool Circle::operator==(const IPhysObject& ob) const {
    return this->mass() == ob.mass();
}
bool Circle::operator<(const IPhysObject& ob) const {
    return this->mass() < ob.mass();
}

void Circle::draw() {
    std::cout << "Center is (" << Center.x << ", " << Center.y << ")\nRadius: " << Radius << "\nMass is " << mass_ << '\n';
}

const char *Circle::classname() {
    return "Circle";
}

Parallelogram::Parallelogram(CVector2D A_, CVector2D B_, CVector2D C_, double mass) {
    A = A_;
    B = B_;
    C = C_;
    mass_ = mass;
}
double Parallelogram::square() {
    float AB = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    float BC = sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y));
    float AC = sqrt((C.x - A.x) * (C.x - A.x) + (C.y - A.y) * (C.y - A.y));
    float P2 = perimeter() / 2;
    return 2 * sqrt(P2 * (P2 - AB) * (P2 - BC) * (P2 - AC));
}
double Parallelogram::perimeter() {
    float AB = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    float BC = sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y));
    return 2 * (AB + BC);
}
double Parallelogram::mass() const {
    return mass_;
}
void Parallelogram::draw() {
    std::cout << "A is (" << A.x << ", " << A.y << ")\nB is (" << B.x << ", " << B.y << ")\nMass is " << mass_ << '\n';
}

CVector2D Parallelogram::position() {
    CVector2D BA = {B.x - A.x, B.y - A.y};
    CVector2D D = {C.x - BA.x, C.y - BA.y};
    return CVector2D{(A.x + B.x + C.x + D.x)/4, (A.y + B.y + C.y + D.y)/4};
}

bool Parallelogram::operator==(const IPhysObject& ob) const {
    return this->mass() == ob.mass();
}
bool Parallelogram::operator<(const IPhysObject& ob) const {
    return (this->mass() < ob.mass());
}

const char *Parallelogram::classname() {
    return "Parallelogram";
}

const char *Parallelogram::size() {
    char* b;
    return itoa(sizeof(Parallelogram), b, 10);
}

const char *Circle::size() {
    char* b;
    return itoa(sizeof(Parallelogram), b, 10);
}

double Array::square() {
    float s = 0;
    for (unsigned i = 0; i < capasity_; i++)
        s+= arr[i]->square();
    return s;
}
double Array::perimeter() {
    float s = 0;
    for (unsigned i = 0; i < capasity_; i++)
        s+= arr[i]->perimeter();
    return s;
}

double Array::mass() const {
    float s = 0;
    for (unsigned i = 0; i < capasity_; i++)
        s+= arr[i]->mass();
    return s;
}
bool Array::operator==(const IPhysObject &ob) const {
    return false;
}
bool Array::operator<(const IPhysObject &ob) const {
    return true;
}
void Array::Add(IPhysObject* fig) {
    if (capasity_ + 1 >= size_)
        Resize(size_ * 2);
    arr[capasity_] = fig;
    capasity_++;
}
void Array::Resize(unsigned n) {
    IPhysObject** b = new IPhysObject*[n];
    for (unsigned i = 0; i < (n > size_? n: size_); i++) {
        b[i] = arr[i];
    }
    arr = b;
    size_ = n;
}

void Array::Remove(unsigned n) {
    for (unsigned i = n - 1; i < (capasity_ - 1); i++)
        arr[i] = arr[i + 1];
    capasity_--;
    arr[capasity_] = nullptr;
}

IPhysObject * Array::operator[](unsigned n) {
    if (n < capasity_)
        return arr[n];
    else return nullptr;
}

CVector2D Array::position() {
    float x = 0, y = 0;
    for (unsigned i = 0; i < capasity_; i++) {
        x+= arr[i]->position().x;
        y+= arr[i]->position().y;
    }
    return CVector2D{x/capasity_, y/capasity_};
}

