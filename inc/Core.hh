#pragma once

#include <cstdlib>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <cmath>

#include "./helpers/Size.hh"
#include "./Objects/Drone.hh"
#include "./Matrix/Matrix3x3.hh"


class Core {

    std::vector <Drone> Dro;

    std::vector <Matrix3D> MatrixOne;

    std::vector <Matrix3D> MatrixDro;

    std::vector <Matrix3D> MatrixHel;

    public:

        void NewDrone(

            const Vector3I,

            const Vector3I,

            const int

        );

        void GetDrone(

            const int

        );

        void DelDrone(

            const int

        );

        void FlyControl(

            const int,

            bool

        );

        ///void FlySettings();

};