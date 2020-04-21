#include <iostream>
#include "proceduring.h"
using namespace std;


int main() {
    float a = 5.16f;
    int b = 3;
    int c = 16;
    Complex d = {5, 15};
    Circule e = {{13.0f, 17.0f}, 13.0f};
    Vector f = {6.25f, 7.24f};

    abss(a);
    swap(b, c);
    multy(d, a);
    offsett(e, f);


    cout << a << endl;
    cout << b << "  " << c << endl;
    cout << d.x << "+" << d.y << endl;
    cout << e.Center.x << ", " << e.Center.y << "\n R:" << e.Radius << endl;

    return 0;
}
