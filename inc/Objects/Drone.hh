#pragma once

#include <iostream>
#include <fstream>

#include "Object.hh"
#include "../Vector/Vector2I.hh"
#include "../Vector/Vector3I.hh"
#include "../Vector/Vector4I.hh"
#include "../Vector/Vector5I.hh"
#include "../Matrix/Matrix3x3.hh"
#include "../helpers/Size.hh"

class DroneCorpus: public Object<8> {

    public:

        DroneCorpus(Vector3I pos, Vector3I size)
        {
            Vector3I half_size = size / 2;
            DroneCorpus& self = *this;

            int l = 0;
            for (double i = -1; i <= 1; ++i)
                for (double j = -1; j <= 1; ++j)
                    for (double k = -1; k <= 1; ++k)
                        if (i != 0 && j != 0 && k != 0)
                            self[l++] = pos + Vector3I{k, j, i}.mult(half_size);
        }

};

class DroneHeli: public Object<16> {

    Vector3I pos;

    public:

        DroneHeli(Vector3I pos, double r, [[maybe_unused]]double h) 
        {
            Matrix3D m = Matrix3D::Rotate_Z(45);
            Matrix3D m2 = Matrix3D::Rotate_Z(-22.5);
            Vector3I v = m2 * Vector3I{0, r, 0};
            for (int i = 0; i < 8; i++)
            {
                v = m * v;
                (*this)[i] = pos + v;
                (*this)[i+8] = pos + v + Vector3I{0, 0, h};
            }

            this->pos = pos;
        }

};

class Drone {

    public:

        Vector3I droPosition;

        DroneCorpus droCorpus;

        DroneHeli droHelis[4];
    

        Drone(Vector3I droPosition, Vector3I size)

            : droCorpus(droPosition, size), 
            
              droHelis {
                
                DroneHeli(droCorpus[4], size[0] * 0.66, size[2] * 0.33), 
                DroneHeli(droCorpus[5], size[0] * 0.66, size[2] * 0.33),
                DroneHeli(droCorpus[6], size[0] * 0.66, size[2] * 0.33),
                DroneHeli(droCorpus[7], size[0] * 0.66, size[2] * 0.33)
                
            } {
            
                this->droPosition = droPosition;
            
            }
};

std::ostream &operator<<(std::ostream &out, Drone const &drone);