#ifndef PROGRAMMING_OVERLOADOPER_H
#define PROGRAMMING_OVERLOADOPER_H

#include <string>

struct Point {
    float x;
    float y;
};
struct Vector {
    float x;
    float y;
};

std::string PointToStr(Point);

class Triangle {
public:
    explicit Triangle(const Point&, const Point&, const Point&);
    float GetSquare();
    void SetPointA(const Point&);
    void SetPointB(const Point&);
    void SetPointC(const Point&);
    Point GetPointA();
    Point GetPointB();
    Point GetPointC();
    friend bool operator==(const Triangle&, const Triangle&);
    friend bool operator>=(const Triangle&, const Triangle&);
    friend bool operator<=(const Triangle&, const Triangle&);
    friend bool operator!=(const Triangle&, const Triangle&);
    friend bool operator< (const Triangle&, const Triangle&);
    friend bool operator> (const Triangle&, const Triangle&);
    Triangle operator+(const Vector&);
private:
    Point A{}, B{}, C{};
    float Square{};
};

class Array {
public:
    explicit Array(const unsigned int&);
    void resize(const unsigned int&);
    size_t GetSize();
    Array operator+(const Array&);
    friend bool operator==(const Array&, const Array&);
    friend bool operator>=(const Array&, const Array&);
    friend bool operator<=(const Array&, const Array&);
    friend bool operator!=(const Array&,const Array&);
    friend bool operator<(const Array&,const Array&);
    friend bool operator>(const Array&,const Array&);
private:
    int* array;
    size_t size;
};


#endif //PROGRAMMING_OVERLOADOPER_H
