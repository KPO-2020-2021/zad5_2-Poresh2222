#pragma once

#include "Matrix.hh"
#include <math.h>


class Matrix3D : public Matrix<3>
{
    public:


static Matrix3D Rotate_X(const double angle) {
    Matrix3D tmp;

    tmp(0, 0) = 1;
    tmp(0, 1) = 0;
    tmp(0, 2) = 0;
    tmp(1, 0) = 0;
    tmp(1, 1) = cos(angle*M_PI/180);
    tmp(1, 2) = -sin(angle*M_PI/180);
    tmp(2, 0) = 0;
    tmp(2, 1) = sin(angle*M_PI/180);
    tmp(2, 2) = cos(angle*M_PI/180);

    return tmp;

}

static Matrix3D Rotate_Y(const double angle) {
    Matrix3D tmp;

    tmp(0, 0) = cos(angle*M_PI/180);
    tmp(0, 1) = 0;
    tmp(0, 2) = sin(angle*M_PI/180);
    tmp(1, 0) = 0;
    tmp(1, 1) = 1;
    tmp(1, 2) = 0;
    tmp(2, 0) = -sin(angle*M_PI/180);
    tmp(2, 1) = 0;
    tmp(2, 2) = cos(angle*M_PI/180);

    return tmp;

}

static Matrix3D Rotate_Z(const double angle) {
    Matrix3D tmp;

    tmp(0, 0) = cos(angle*M_PI/180);
    tmp(0, 1) = -sin(angle*M_PI/180);
    tmp(0, 2) = 0;
    tmp(1, 0) = sin(angle*M_PI/180);
    tmp(1, 1) = cos(angle*M_PI/180);
    tmp(1, 2) = 0;
    tmp(2, 0) = 0;
    tmp(2, 1) = 0;
    tmp(2, 2) = 1;

    return tmp;
    
} 


};