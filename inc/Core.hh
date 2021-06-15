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

    std::vector <DroneCorpus> Drc;

    std::vector <DroneHeli> Drh;

    //template <unsigned int Size>
    //std::vector <Drone<Size>> Drone;

    public:

        void NewDrone(

            const Vector3I,

            const Vector3I

            //const int

        );

};