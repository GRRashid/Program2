#include "OverloadOper.h"
#include <cmath>

Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
    this->A = A, this->B = B, this->C = C;
}

std::string PointToStr(const Point& A) {
    std::string text = "(";
    char* b = new char[10];
    sprintf(b, "%f", A.x);
    text += b;
    text += ", ";
    sprintf(b, "%f", A.y);
    text += b;
    text += ")";
    return text;
}

float Triangle::GetSquare() {
    float AB = std::sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    float AC = std::sqrt((A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y));
    float CB = std::sqrt((C.x - B.x) * (C.x - B.x) + (C.y - B.y) * (C.y - B.y));
    float Per2 = (AB + AC + CB)/2;
    this->Square = std::sqrt(Per2 * (Per2 - AB) * (Per2 - AC) * (Per2 - CB));
    return this->Square;
}

void Triangle::SetPointA(const Point& PointA) {
    this->A = PointA;
}
void Triangle::SetPointB(const Point& PointB) {
    this->B = PointB;
}
void Triangle::SetPointC(const Point& PointC) {
    this->C = PointC;
}
Point Triangle::GetPointA() {
    return this->A;
}
Point Triangle::GetPointB() {
    return this->B;
}
Point Triangle::GetPointC() {
    return this->C;
}

bool operator==(const Triangle& First,const Triangle& Second) {
    return First.Square == Second.Square;
}
bool operator>=(const Triangle& First, const Triangle& Second) {
    return First.Square >= Second.Square;
}
bool operator<=(const Triangle& First, const Triangle& Second) {
    return First.Square <= Second.Square;
}
bool operator!=(const Triangle& First, const Triangle& Second) {
    return First.Square != Second.Square;
}
bool operator<(const Triangle& First, const Triangle& Second) {
    return First.Square < Second.Square;
}
bool operator>(const Triangle& First, const Triangle& Second) {
    return First.Square > Second.Square;
}

Triangle Triangle::operator+(const Vector& Vec) {
    this->A.x += Vec.x;
    this->A.y += Vec.y;

    this->B.x += Vec.x;
    this->B.y += Vec.y;
    this->C.x += Vec.x;
    this->C.y += Vec.y;
    return Triangle(this->A, this->B, this->C);
}

Array::Array(const unsigned int& size) {
    this->array = new int[size];
    this->size = size;
}

void Array::resize(const unsigned int& newSize) {
    int* a = new int[newSize];
    for (int i = 0; i < fmin(this->size, newSize); i++) {
        a[i] = this->array[i];
    }
    delete[] this->array;
    this->array = a;
    this->size = newSize;
}
Array Array::operator+(const Array& B) {
    int tmp = this->size;
    this->resize(this->size + B.size);
    for (int i = 0; i < B.size; i++) {
        this->array[tmp + i] = B.array[i];
    }
    return *this;
}

bool operator==(const Array& A, const Array& B) {
    return A.size == B.size;
}
bool operator>=(const Array& A, const Array& B) {
    return A.size >= B.size;
}
bool operator<=(const Array& A, const Array& B) {
    return A.size <= B.size;
}
bool operator!=(const Array& A,const Array& B) {
    return A.size != B.size;
}
bool operator<(const Array& A,const Array& B) {
    return A.size < B.size;
}
bool operator>(const Array& A,const Array& B) {
    return A.size > B.size;
}

size_t Array::GetSize() {
    return this->size;
}
