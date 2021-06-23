#pragma once

#include <iostream>
#include <fstream>

#include "../Vector/Vector3I.hh"
#include "../Matrix/Matrix3x3.hh"
#include "../helpers/Size.hh"

template <unsigned int Size>

class Object {

    protected:

        Vector3I lokCorners[Size];

        Vector3I pivot;

        Vector3I direction;

        std::vector<int> indices;

    public:

        Object();

        Object(Vector3I objectCorners[Size], Vector3I pivot);


        Vector3I &operator [] (int index);

        const Vector3I &operator [] (int index) const;


        double &operator () (unsigned int row, unsigned int column);

        const double &operator () (unsigned int row, unsigned int column) const;

        void Translate(Vector3I v) {

            for (uint i = 0; i < Size; i++) {

                lokCorners[i] += v;

            }

            pivot += v;

        }

        void Rotate(const Matrix3D& m) {

            Rotate(m, pivot);

        }

        void Rotate(const Matrix3D& m, Vector3I center) {
            
            for (uint i = 0; i < Size; i++) {

                Vector3I v = lokCorners[i] - center;

                v = m * v;

                lokCorners[i] = v + center;

            }

            Vector3I v = pivot - center;
            v = m * v;
            pivot = v + center;

            direction = m * direction;

        }

        Vector3I GetPivot() const {

            return pivot;

        }

        Vector3I GetDirection() const {

            return direction;

        }

        void SaveToFile(const std::string& filename) {

            std::ofstream f(filename);

            for (int index : indices) {

                f << lokCorners[index] << std::endl;

            }

        }

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
Object<Size>::Object(Vector3I tmp[Size], Vector3I pivot) {

    for (unsigned int i = 0; i < Size; ++i) {
            
        lokCorners[i] = tmp[i];

    }

    this->pivot = pivot;

    this->direction = {0, 1, 0};

}

template <unsigned int Size>
Vector3I &Object<Size>::operator[](int index) {

    return const_cast<Vector3I &>(const_cast<const Object<Size> *>(this)->operator[](index));

}

template <unsigned int Size>
const Vector3I &Object<Size>::operator [] (int index) const {

    if (index < 0 || index >= (int)Size) {

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