#include "Patterns.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T> T maxTT(T& start, const T& stop) {
    T* count = &start;
    T maxRes = start;
    while (count != &stop) {
        if (*count > maxRes)
            maxRes = *count;
        count++;
    }
    return maxRes;
}

int main() {
    int a[] = {1, 5, 96, 34, 2};
    cout << maxTT(a[0], a[4]) << '\n';
    Stack<int> stack = Stack<int>();
    stack.Add(5);
    stack.Add(4);
    stack.Add(3);
    stack.Add(2);
    cout << stack() << '\n';
    stack.Pop();
    cout << stack() << '\n';
    return 0;
}
