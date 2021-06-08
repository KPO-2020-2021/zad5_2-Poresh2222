#pragma once

#include <iostream>
#include <fstream>

#include "./Vector/Vector3I.hh"

template <unsigned int Size>

class Object {

    Vector3I lokCorners[Size];

    public:

        Object();

        Object(const Object &obj);

        Object(Vector3I objectCorners[Size]);

};

template <unsigned int Size>

class Drone: public Object<Size> {

    

};