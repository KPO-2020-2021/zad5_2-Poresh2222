#pragma once

#include <iostream>
#include <iomanip>

#include "../helpers/Size.hh"


template <unsigned int Size>

class Vector {

    double size[Size];

    public:

        Vector<Size>();

        Vector<Size>(double [Size]);


        Vector<Size> operator + (const Vector<Size> &V);

        Vector<Size> operator - (const Vector<Size> &V);

        Vector<Size> operator * (const double &tmp);

        Vector<Size> operator / (const double &tmp);

        Vector<Size> operator = (const double &tmp);

        //Vector<Size> operator -- (const double *tmp);


        const double &operator [] (unsigned int index) const;

        double &operator [] (unsigned int index);


        bool operator == (const Vector& tmp);

};

template <unsigned int Size>

std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp);


template <unsigned int Size>

std::istream &operator >> (std::istream &in, Vector<Size> &tmp);




template <unsigned int Size>
Vector<Size>::Vector() {

    for (unsigned int i = 0; i < Size; ++i) {

        size[i] = 0;

    }

}

template <unsigned int Size>
Vector<Size>::Vector(double tmp[Size]) {

    for (unsigned int i = 0; i < Size; ++i) {

        size[i] = tmp[i];

    }

}

//template <unsigned int Size>
//Vector<Size>::Vector(Vector<Size> tmp[Size]) {

//    std::cout << "***" << std::endl;

//    Vector<Size> result = tmp;

//    for (unsigned int i = 0; i < Size; ++i) {

//        size[i] = result[i];

//    }

//}

template <unsigned int Size>
Vector<Size> Vector<Size>::operator + (const Vector<Size> &V) {
    Vector<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        result[i] = size[i] += V[i];

    }

    return result;

}

template <unsigned int Size>
Vector<Size> Vector<Size>::operator - (const Vector<Size> &V) {
    Vector<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        result[i] = size[i] -= V[i];

    }

    return result;

}

template <unsigned int Size>
Vector<Size> Vector<Size>::operator * (const double &tmp) {
    Vector<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        result[i] = size[i] *= tmp;

    }

    return result;

}

template <unsigned int Size>
Vector<Size> Vector<Size>::operator / (const double &tmp) {
    Vector<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        result[i] = size[i] / tmp;

    }

    return result;

}

template <unsigned int Size>
Vector<Size> Vector<Size>::operator = (const double &tmp) {
    Vector<Size> result;

    for (unsigned int i = 0; i < Size; ++i) {

        result[i] = size[i] = tmp;

    }

    return result;

}

//template <unsigned int Size>
//Vector<Size> Vector<Size>::operator -- (const double *tmp) {
//    Vector<Size> result;

//    for (unsigned int i = 0; i < Size; ++i) {

//        result[i] = size[i] = tmp;

//    }

//    return result;

//}

template <unsigned int Size>
const double &Vector<Size>::operator [] (unsigned int index) const {

    if (index < 0 || index >= Size) {

        std::runtime_error("Error: The Vector is out of range");

    }

    return size[index];

}

template <unsigned int Size>
double &Vector<Size>::operator[](unsigned int index) {

    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));

}

template <unsigned int Size>
std::ostream &operator << (std::ostream &out, Vector<Size> const &tmp) {

    for (unsigned int i = 0; i < Size; ++i) {

        out << "[ " << tmp[i] << " ]\n";

    }

    return out;

}

template <unsigned int Size>
std::istream &operator >> (std::istream &in, Vector<Size> &tmp) {

    for (unsigned int i = 0; i < Size; ++i) {

        in >> tmp[i];

    }

    std::cout << std::endl;

    return in;

}

template <unsigned int Size>
bool Vector<Size>::operator == (const Vector<Size>& tmp) {

    for(unsigned int i = 0; i < Size; ++i) {
        
        if(!(size[i] >= tmp[i] - MAX_DIFF && size[i] <= tmp[i] + MAX_DIFF)) return false;
        
    }

    return true;

}