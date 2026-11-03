//
// Created by Adami on 9/1/2026.
//

#pragma once
#include <vector>
#include <iostream>
#include <concepts>

template <typename T>
concept Numeric = requires(T a, T b) {
    { a + b } -> std::convertible_to<T>;
    { a - b } -> std::convertible_to<T>;
    { a * b } -> std::convertible_to<T>;
    { a / b } -> std::convertible_to<T>;
};

template <Numeric T>
class Matrix{
private:
    std::vector<T> data;

    public:
    const int rows;
    const int cols;

    ~Matrix();

    Matrix(const std::vector<T>& data, int rows, int cols);

    T get(int row, int col) const;

    T* getPtr(int row, int col);

    T& getRef(int row, int col);

    void set(T element, int row, int col);

    void set(const std::vector<T>& data);

    void pushBack(T element);

    void switchRows(int const row1,  int const row2);

    void scalingRow(int const row, int const factor);

    template <Numeric U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
};

#include "Matrix.cpp"