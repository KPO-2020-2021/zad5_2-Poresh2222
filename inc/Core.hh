#pragma once

#include <cstdlib>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <cmath>

#include "./helpers/Size.hh"
#include "./Objects/Drone.hh"


class Core {

    std::vector <Vector3I> Vec;

    std::vector <Drone> Dro;

    std::vector <DroneHeli> Drh;

    public:

        void NewDrone(

            const Vector3I,

            const Vector3I

            //const int

        );

};