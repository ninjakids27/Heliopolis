//
// Created by Adami on 9/11/2026.
//
// The following will be applicable for matrix of type real numbers so doubles, mpz_class etc...

#include "Matrix.h"
#include "MatrixOPS.h"
#include <random>
namespace MatrixOPS {
    template <Numeric T>
    Matrix<T> static identityMatrix(const int n) {
        std::vector<T> data;
        data.reserve(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                data.push_back(i == j ? static_cast<T>(1) : static_cast<T>(0));
            }
        }
        return Matrix<T>(data, n, n);
    }


    /**
     *
     * @tparam T T is a generic Numeric Type meaning T has to support +,-,*,/ and be able to be passed through elementary functions
     * @param m
     */
    template <Numeric T>
    void static pivotizeMatrix(Matrix<T> &m) {
        int const range { std::min(m.cols, m.rows) };
        for (int col  = 0; col < range; col++) {
            T max = m.get(col, col);
            for (int row = col; row < m.rows; row++) {
                if (max < m.get(row, col)) {
                    max = m.get(row,col);
                    m.switchRows(col,row);
                }
            }
        }
    }

    template <Numeric T>
    void static randomizeMatrixINT(Matrix<T> &m, int low, int high) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<T> dis(low, high);

        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                m.set(dis(gen),i,j);
            }
        }
    }

    template <Numeric T>
    void randomizeMatrixDOUBLE(Matrix<T> &m, double low, double high) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<T> dis(low, high);

        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                m.set(dis(gen),i,j);
            }
        }
    }

    // TODO: Ints do not work for this
    /**
     * reduced row echelon form
     * @tparam T Type of numeric
     * @param m Matrix
     */
    template <Numeric T>
        void static rref(Matrix<T> &m) {

        for (int i = 0; i < m.cols; i++) {
            pivotizeMatrix(m);
            for (int j = i+1 ; j < m.rows; j++) {
                // gets it's pivot and eliminates it to get zero prob should check for zeros :/
                m.gaussianElimination(j,i,-1*m.get(j,i)/m.get(i,i));
            }
        }
    }
}
