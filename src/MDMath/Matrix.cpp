//
// Created by Adami on 9/1/2026.
//

#include "Matrix.h"
#include "../ANSI_COLORS.h"


template <Numeric T>
Matrix<T>::Matrix(const std::vector<T>& data, int rows, int cols) : data(data), rows(rows), cols(cols) {
    if (data.size() != rows * cols) {
        throw std::invalid_argument(
            ansi::formats::error("data length does not match to the amount of entries in matrix"));
    }
}

template <Numeric T>
T Matrix<T>::get(int const row, int const col) const {
    int const entry { row * this->cols + col};
    if (this->data.size() < entry) {
        throw std::invalid_argument("Entry goes out of bounds for data provided");
    }
    return data[entry];
}

template <Numeric T>
T* Matrix<T>::getPtr(int const row, int const col) {
    int const entry { row * this->cols + col};
    if (this->data.size() < entry) {
        throw std::invalid_argument("Entry goes out of bounds for data provided");
    }
    return &data[entry];
}

template <Numeric T>
T& Matrix<T>::getRef(int const row, int const col) {
    T& result = data[row * cols + col];
    return result;
}

template <Numeric T>
void Matrix<T>::set(T element, int row, int col) {
    data[row * cols + col] = element;
}

template <Numeric T>
void Matrix<T>::set(const std::vector<T>& data) {
    if (data.size() != this->rows * this->cols) {
        throw std::invalid_argument(ansi::formats::error("Vector length does not match to the amount of entries in the matrix"));
    }
    this->data = data;
}

template <Numeric T>
void Matrix<T>::pushBack(T element) {
    this->data.push_back(element);
}


template <Numeric T>
Matrix<T>::~Matrix() {
     data.clear();
}

template <Numeric T>
void Matrix<T>::switchRows(int const row1,  int const row2) {
    for (int i = 0; i < this->cols; i++) {
        std::swap(this->getRef(row1, i), this->getRef(row2, i));
    }
};

template <Numeric T>
void Matrix<T>::scalingRow(int const row, int const factor) {
    for (int i = 0; i < this->cols; i++) {
        this->set(this->get(row,i)*factor, row, i);
    }
};

template <Numeric T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++)
            os << matrix.get(i, j) << " ";
        os << "\n";
    }
    return os;
}