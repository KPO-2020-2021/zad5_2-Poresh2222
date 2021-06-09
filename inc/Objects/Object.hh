#pragma once

#include <iostream>
#include <fstream>

#include "../Vector/Vector3I.hh"
#include "../helpers/Size.hh"

template <unsigned int Size>

class Object {

    Vector3I lokCorners[Size];

    public:

        Object();

        Object(const Object &obj);

        Object(Vector3I objectCorners[Size]);


        Vector3I &operator [] (int index);

        const Vector3I &operator [] (int index) const;


        double &operator () (unsigned int row, unsigned int column);

        const double &operator () (unsigned int row, unsigned int column) const;


};


template <unsigned int Size>
std::ostream &operator << (std::ostream &out, const Object<Size> &Obj);


template <unsigned int Size>
Object<Size>::Object() {

    for (unsigned int i = 0; i < Size; ++i) {

        for (unsigned int j = 0; j < ROWS; ++j) {

            lokCorners[i][j] = 0;

        }

    }

}

template <unsigned int Size>
Object<Size>::Object(const Object<Size> &obj) {

    for (unsigned int i = 0; i < Size; ++i) {
        
        for (unsigned int j = 0; j < ROWS; ++j) {

            lokCorners[i][j] = obj(i, j);

        }
        
    }

}

template <unsigned int Size>
Object<Size>::Object(Vector3I tmp[Size]) {

    for (unsigned int i = 0; i < Size; ++i) {
            
        lokCorners[i] = tmp[i];

    }

}

template <unsigned int Size>
Vector3I &Object<Size>::operator[](int index) {

    return const_cast<Vector3I &>(const_cast<const Object<Size> *>(this)->operator[](index));

}

template <unsigned int Size>
const Vector3I &Object<Size>::operator [] (int index) const {

    if (index < 0 || index >= CUBE) {

        throw std::runtime_error("Error: Vec out of range!");

    }

    return lokCorners[index];

}

template <unsigned int Size>
double &Object<Size>::operator () (unsigned int row, unsigned int column) {

    if (row >= Size || column >= ROWS) {

        throw std::runtime_error("Error: The Matrix is out of range \n");

    }

    return lokCorners[row][column];

}

template <unsigned int Size>
const double &Object<Size>::operator () (unsigned int row, unsigned int column) const {

    if (row >= Size || column >= ROWS) {

        throw std::runtime_error("Error: The Matrix is out of range \n");
    
    }

    return lokCorners[row][column];

}

template <unsigned int Size>
std::ostream &operator<<(std::ostream &out, Object<Size> const &Obj) {
    
    for(unsigned int i = 0; i < Size; ++i) {

        for(unsigned int j = 0; j < ROWS; ++j) {

            out << std::fixed << std::setprecision(10) << Obj(i , j ) << "\t";
        
        }

        out << std::endl;
    
    }

  return out;

}