#include "OverloadOper.h"
#include <iostream>
using namespace std;


int main() {
    Triangle tri1 = Triangle({0,0}, {0,4}, {3,0});
cout << "Треугольник A: " << PointToStr(tri1.GetPointA()) << " " << PointToStr(tri1.GetPointB()) << " " << PointToStr(tri1.GetPointC()) << "\nWith Square:" << tri1.GetSquare() << '\n';
Triangle tri2 = Triangle({2,10}, {5,10}, {5,6});
cout << "Треугольник B: " << PointToStr(tri2.GetPointA()) << " " << PointToStr(tri2.GetPointB()) << " " << PointToStr(tri2.GetPointC()) << "\nWith Square:" << tri2.GetSquare() << '\n';

cout << "Sa == Sb: " << ((tri1 == tri2)? "True": "False") << '\n';
cout << "Sa != Sb: " << ((tri1 != tri2)? "True": "False") << '\n';
cout << "Sa > Sb: " << ((tri1 > tri2)? "True": "False") << '\n';
cout << "Sa < Sb: " << ((tri1 < tri2)? "True": "False") << '\n';
cout << "Sa >= Sb: " << ((tri1 >= tri2)? "True": "False") << '\n';
cout << "Sa <= Sb: " << ((tri1 <= tri2)? "True": "False") << '\n';

Vector vec = {15,3};
cout << "Треульник А на вектор " << vec.x << " " << vec.y << "\n";
tri1 = tri1 + vec;
cout << "Треугольник A: " << PointToStr(tri1.GetPointA()) << " " << PointToStr(tri1.GetPointB()) << " " << PointToStr(tri1.GetPointC()) << "\nWith Square:" << tri1.GetSquare() << '\n';

Array a = Array(100);
Array b = Array(50);

cout << "A == B: " << ((a==b)? "True":"False") << '\n';
a = a + b;
cout << a.GetSize();

    return 0;
}
