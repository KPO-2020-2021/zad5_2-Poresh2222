#pragma once

#include <cstdlib>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <fstream>

#include "./helpers/Size.hh"
#include "./helpers/lacze_do_gnuplota.hh"
#include "./Objects/Drone.hh"
#include "./Matrix/Matrix3x3.hh"


class Core {

    std::vector <Drone> Dro;

    public:

        void NewDrone(

            const Vector3I,

            const Vector3I,

            PzG::LaczeDoGNUPlota& Lacze

        );

        Drone& GetDrone(

            const int

        );

        void DelDrone(

            const int

        );

        void Update(float dt);

};