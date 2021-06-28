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
#include "./Objects/Obstacle.hh"
#include "./Matrix/Matrix3x3.hh"


class Core {
    
    public:

    std::vector <Drone> Dro;
    std::vector <Obstacle> Obstacles;


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

        void NewObstacle(

            const Vector3I,

            const Vector3I,

            PzG::LaczeDoGNUPlota& Lacze

        );

        void Update(float dt);

};