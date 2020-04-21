#include <iostream>
#include <algorithm>
#include "Circuit_Buffer.h"
using namespace std;


int main() {
    CircuitBuffer<int> CB(5);
    cout << "Start size is " << CB.capacity() << '\n';
    CB.Resize(3);
    cout << "Size with no changes is " << CB.capacity() << '\n';
    CB.Resize(5);
    cout << "New size is " << CB.capacity() << '\n';
    CB.AddEnd(5);
    CB.AddEnd(3);
    CB.AddStart(4);
    CB.AddStart(2);
    CB.Resize(3);
    cout << "Size with changes is " << CB.capacity() << '\n';
    for (int i = 0; i < CB.size();i++)
        cout << CB[i] << " ";
    cout << '\n';
    for (auto i : CB)
        cout << i << " ";
    cout << '\n';
    std::sort(CB.begin(), CB.end());
    for (auto i : CB)
        cout << i << " ";
    cout << '\n';
    return 0;
}