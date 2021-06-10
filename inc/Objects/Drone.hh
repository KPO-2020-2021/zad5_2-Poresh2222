#pragma once

#include <iostream>
#include <fstream>

#include "Object.hh"
#include "../Vector/Vector2I.hh"
#include "../Vector/Vector3I.hh"
#include "../Vector/Vector4I.hh"
#include "../helpers/Size.hh"


class Drone: public Object<8> {

    //Vector3I lokDroneCorners[CUBE];

    public:

        Drone() : Drone::Object() {};

        Drone(Vector3I droneCorners[CUBE]) : Object(droneCorners) {



        };

};

class DroneCorpus: public Drone {

    Vector3I lokDroneCorpusCorners[CUBE];

    public:

        DroneCorpus() : Drone() {};

        DroneCorpus(Vector3I droneCorners[CUBE]) : Drone(droneCorners) {};

};

class DroneHeli: public Object<16> {

    Vector3I lokDroneHeliCorners[HELI];

    public:

        DroneHeli() : DroneHeli::Object() {};

        DroneHeli(Vector3I droneHeliCorners[HELI]) : DroneHeli::Object(droneHeliCorners) {};

};