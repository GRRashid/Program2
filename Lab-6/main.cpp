#include <iostream>
#include "Predicats.h"
using namespace std;

bool F(int& A) {
    return A > 9;
}

bool sort(int& A, int& B) {
    return A > B;
}

bool find(int& A) {
    return A == 8;
}

class Edges {
public:
    int x, y, len;
};

bool FE(Edges& a) {
    return a.len < 5;
}

bool Esort(Edges& A, Edges& B) {
    return A.len > B.len;
}

bool Efind(Edges& A) {
    return A.len == 8;
}


int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << none_of(A[0], A[7], F) << '\n'
         << is_sorted(&A[0], &A[7], sort) << '\n'
         << (find_backward(A[0], A[7], find) - &A[0]) << '\n';
    Edges B[] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}};
    cout << none_of(B[0], B[7], FE) << '\n'
         << is_sorted(&B[0], &B[5], Esort) << '\n'
         << (find_backward(B[0], B[7], Efind) - &B[0]) << '\n';
    return 0;
}
