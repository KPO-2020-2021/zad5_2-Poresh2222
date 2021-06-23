#pragma once

#include "../Vector/Vector.hh"
#include "../helpers/Size.hh"

#include <iostream>


template <unsigned int Size>

class Matrix {

    double value[Size][Size];

    public:

        Matrix();

        Matrix(double [Size][Size]);


        Vector<Size> operator * (const Vector<Size>& V) const;


        Matrix operator + (const Matrix tmp);

        Matrix operator * (const Matrix tmp);


        double &operator () (unsigned int row, unsigned int column);

        const double &operator () (unsigned int row, unsigned int column) const;


        bool operator == (const Matrix tmp);

};

template <unsigned int Size>

std::istream &operator>>(std::istream &in, Matrix<Size> &mat);


template <unsigned int Size>

std::ostream &operator<<(std::ostream &out, Matrix<Size> const &mat);


template <unsigned int Size>
Matrix<Size>::Matrix() {

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            value[i][j] = 0;

            if (i == j) {

                value[i][j] = 1;

            }

        }

    }

}

template <unsigned int Size>
Matrix<Size>::Matrix(double tmp[Size][Size]) {

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            value[i][j] = tmp[i][j];

        }

    }

}

template <unsigned int Size>
Vector<Size> Matrix<Size>::operator * (const Vector<Size>& V) const {
    Vector<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            result[i] += value[i][j] * V[j];

        }

    }

    return result;

}

template <unsigned int Size>
Matrix<Size> Matrix<Size>::operator + (Matrix<Size> tmp) {
    Matrix<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            result(i, j) = this->value[i][j] + tmp(i, j);

        }

    }

    return result;

}

template <unsigned int Size>
Matrix<Size> Matrix<Size>::operator * (const Matrix<Size> tmp) {
    Matrix<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            for (unsigned int k = 0; k < Size; ++k) {

                result.value[i][j] += value[i][k] * tmp.value[k][j];

            }

        }

    }

    return result;

}

template <unsigned int Size>
double &Matrix<Size>::operator()(unsigned int row, unsigned int column) {

    if (row >= Size) {
 
        std::runtime_error("Error: The Matrix is out of range");

    }

    if (column >= Size) {

        std::runtime_error("Error: The Matrix is out of range");

    }

    return value[row][column];

}

template <unsigned int Size>
const double &Matrix<Size>::operator () (unsigned int row, unsigned int column) const {

    if (row >= Size) {
        
        std::runtime_error("Error: The Matrix is out of range");

    }

    if (column >= Size) {
        
        std::runtime_error("Error: The Matrix is out of range");
        
    }

    return value[row][column];
}

template <unsigned int Size>
bool Matrix<Size>::operator == (const Matrix<Size> tmp) {

    for(unsigned int i = 0; i < Size; ++i) {

        for(unsigned int j = 0; j < Size; ++j) {

            if(!(value[i][j] >= tmp(i, j) - MAX_DIFF && value[i][j] <= tmp(i, j) + MAX_DIFF)) return false;

        }

    }

    return true;

}

template <unsigned int Size>
std::istream &operator>>(std::istream &in, Matrix<Size> &mat) {

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            in >> mat(i, j);

        }

    }

    return in;

}

template <unsigned int Size>
std::ostream &operator<<(std::ostream &out, const Matrix<Size> &mat) {

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < Size; ++j) {

            out << "| " << mat(i, j) << " | ";

        }

        std::cout << std::endl;

    }

    return out;

}