#include "virtual.h"
#include <iostream>
#include <vector>
using namespace std;


int main() {
        Array arr;
    arr.Add(new Parallelogram({0, 0}, {1, 0}, {1, 1}, 4));
    arr.Add(new Circle({0, 0}, 5, 8));
    char com;
    while (true) {
        cout << "-------===MENU===-------\n"
                "Available commands:\n"
                "1. Add new Figure\n"
                "2. Square of N's Figure\n"
                "3. Perimeter of N's Figure\n"
                "4. Mass of N's Figure\n"
                "5. Center Of Mass of N's Figure\n"
                "6. Information of array\n"
                "7. Compare N's Figure and M's Figure\n"
                "0. Exit\n"
                "Enter number: ";
        cin >> com;
        switch (com) {
            case '1':
                cout << "What of Figure?\n"
                        "1. Parallelogram\n"
                        "2. Circle\n"
                        "Enter number: ";
                cin >> com;
                switch (com) {
                    case '2':
                        cout << "Enter Center:\nX: ";
                        float x1, y1, r1, massC;
                        cin >> x1;
                        cout << "Y: ";
                        cin >> y1;
                        cout << "Enter Radius: ";
                        cin >> r1;
                        cout << "Enter mass: ";
                        cin >> massC;
                        arr.Add(new Circle({x1, y1}, r1, massC));
                        break;
                    default:
                        float x2, y2, mas2;
                        CVector2D A, B, C;
                        cout << "Enter 1 Point:\nX: ";
                        cin >> x2;
                        cout << "Y: ";
                        cin >> y2;
                        A = {x2, y2};
                        cout << "Enter 2 Point:\nX: ";
                        cin >> x2;
                        cout << "Y: ";
                        cin >> y2;
                        B = {x2, y2};
                        cout << "Enter 3 Point:\nX: ";
                        cin >> x2;
                        cout << "Y: ";
                        cin >> y2;
                        C = {x2, y2};
                        cout << "Enter mass: ";
                        cin >> mas2;
                        arr.Add(new Parallelogram(A, B, C, mas2));
                        break;
                }
                cout << "Successful\n";
                break;
            case '2':
                unsigned numS;
                cout << "Enter N: ";
                cin >> numS;
                cout << "Square of " << --numS << "'s Figure is " << arr[numS]->square() << '\n';
                break;
            case '3':
                unsigned numR;
                cout << "Enter N: ";
                cin >> numR;
                cout << "Perimeter of " << --numR<< "'s Figure is " << arr[numR]->perimeter() << '\n';
                break;
            case '4':
                unsigned numM;
                cout << "Enter N: ";
                cin >> numM;
                cout << "Mass of " << --numM << "'s Figure is " << arr[numM]->mass() << '\n';
                break;
            case '5':
                unsigned numCM;
                cout << "Enter N: ";
                cin >> numCM;
                cout << "Center of Mass of " << --numCM << "'s Figure is (" << arr[numCM]->position().x << ", " << arr[numCM]->position().y << ")\n";
                break;
            case '6':
                cout << "Sum of Squares is " << arr.square() << "\nSum of Perimeters is " << arr.perimeter() << "\nSum of mass is " << arr.mass() << "\nCenter of mass is (" << arr.position().x << ", " << arr.position().y << ")\n";
                break;
            case '7':
                unsigned numEC1, numEC2;
                cout << "Enter N: ";
                cin >> numEC1;
                cout << "Enter M: ";
                cin >> numEC2;
                cout << "N's Figure " << (*arr[--numEC1] == *arr[--numEC2]? "equal": ((*arr[numEC2] < *arr[numEC1]) ? "bigger that" : "smaller that")) << " M's Figure.\n";;
                break;
            case '0':
                goto exit;
            default:
                break;
        }
    }
    exit:
    return 0;
}
