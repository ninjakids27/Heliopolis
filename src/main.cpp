#include <iostream>
#include <gmpxx.h>
#include "MDMath/MatrixOPS.h"
#include <vector>

int main() {
    int const row {10};
    int const col {10};
    const std::vector<double> a(row*col, 0.0);

    Matrix A(a, row,col);
    MatrixOPS::randomizeMatrixDOUBLE(A, 0,10);
    // std::cout << A << "\n" << "\n";
    MatrixOPS::rref(A);
    std::cout << A;
    return 0;
};
