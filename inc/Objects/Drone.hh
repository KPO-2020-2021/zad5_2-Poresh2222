#pragma once

#include <iostream>
#include <fstream>

#include "Object.hh"
#include "../Vector/Vector3I.hh"
#include "../helpers/Size.hh"


class Drone: public Object<8> {

    Vector3I lokDroneCorners[CUBE];

    public:

        Drone() : Drone::Object() {};

        Drone(Vector3I droneCorners[CUBE]) : Drone::Object(droneCorners) {
            
            for (int i = 0; i < CUBE; ++i) {
            
                this -> lokDroneCorners[i] = droneCorners[i];

                std::cout << lokDroneCorners[i] << std::endl;

            }
            
        };

        void StartCornersHeli();

};

class DroneHeli: public Object<16> {

    Vector3I lokDroneHeliCorners[DRONH];

    public:

        DroneHeli() : DroneHeli::Object() {};

        DroneHeli(Vector3I droneHeliCorners[DRONH]) : DroneHeli::Object(droneHeliCorners) {};

};