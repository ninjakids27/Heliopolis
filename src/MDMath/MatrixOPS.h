//
// Created by Adami on 9/11/2026.
//

#pragma once
#include "Matrix.h"
namespace MatrixOPS {
    template  <Numeric T>
    Matrix<T> static identityMatrix(const int n);


    template  <Numeric T>
    void static rref(Matrix<T> &m);
}


#include "MatrixOPS.cpp"