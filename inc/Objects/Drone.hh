#pragma once

#include <iostream>
#include <fstream>

#include "Object.hh"
#include "../Vector/Vector2I.hh"
#include "../Vector/Vector3I.hh"
#include "../Vector/Vector4I.hh"
#include "../Vector/Vector5I.hh"
#include "../helpers/Size.hh"

template <unsigned int Size>

class Drone: public Object<Size> {

    //Vector3I lokDroneCorners[CUBE];

    //int** lokDroneCorners[5];/

    public:

        Drone() : Drone::Object() {};

        Drone(Vector3I droneCorners[Size]) : Object<Size>(droneCorners) {};

};

class DroneCorpus: public Object<8> {

    public:

        DroneCorpus() {}

        DroneCorpus(Vector3I droneCorners[CUBE]) : Drone(droneCorners) {};

};

class DroneHeli: public Drone<16> {

    Vector3I lokDroneHeliCorners[HELI];

    public:

        DroneHeli() : DroneHeli::Drone() {};

        DroneHeli(Vector3I droneHeliCorners[HELI]) : DroneHeli::Drone(droneHeliCorners) {};

};