#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>

#include "Object.hh"
#include "../inc/Objects/Box.hh"
#include "../Vector/Vector2I.hh"
#include "../Vector/Vector3I.hh"
#include "../Vector/Vector4I.hh"
#include "../Vector/Vector5I.hh"
#include "../Matrix/Matrix3x3.hh"
#include "../helpers/Size.hh"

class Core;

class DroneCorpus: public Object<8> {

    public:

        DroneCorpus(Vector3I droPosition, Vector3I droSize) {
            
            Vector3I halfSize = droSize / 2;

            DroneCorpus& self = *this;

            int l = 0;

            for (double i = 0; i <= 1; ++i) {

                for (double j = -1; j <= 1; ++j) {

                    for (double k = -1; k <= 1; ++k) {

                        if (j != 0 && k != 0) {

                            self[l++] = droPosition + Vector3I{k, j, 2*i}.mult(halfSize);

                        }

                    }

                }

            }

            pivot = droPosition;

            indices = std::vector<int>{0, 1, 3, 2, 0, 4, 5, 7, 6, 4, 7, 3, 2, 6, 5, 1};

        }

    void UpDate(float dt);

};

class DroneHeli: public Object<16> {

    constexpr static const float ROTATION_SPEED = 45.0f;

    public:

        bool enabled = false;
    
        DroneHeli() : Object() {}

        DroneHeli(Vector3I heliPosition, double R, double H) { //[[maybe_unused]]

            Matrix3D M1 = Matrix3D::Rotate_Z(45);

            Matrix3D M2 = Matrix3D::Rotate_Z(-22.5);

            Vector3I V = M2 * Vector3I{0, R, 0};


            for (int i = 0; i < 8; i++) {
                V = M1 * V;

                (*this)[i] = heliPosition + V;
                (*this)[i+8] = heliPosition + V + Vector3I{0, 0, H};

            }

            pivot = heliPosition;
            indices = std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 0, 8, 9, 10 ,11, 12, 13, 14, 15, 8};

        }

    void UpDate(float dt, int index);

};

class Drone {

        constexpr static const float MAX_VELOCITY = 10.0f;
        constexpr static const float FLIGHT_HEIGHT = 140.0f;
        constexpr static const float FLIGHT_ROTATION = 40.0f;

    public:

        DroneCorpus droCorpus;

        DroneHeli droHelis[4];

        Vector3I targetPosition;
    
        Box boundingBox;

        Drone(Vector3I droPosition, Vector3I droSize)

            : droCorpus(droPosition, droSize), 
            
              droHelis {
                
                DroneHeli(droCorpus[4], droSize[0] * 0.45, droSize[2] * 0.33), 
                DroneHeli(droCorpus[5], droSize[0] * 0.45, droSize[2] * 0.33),
                DroneHeli(droCorpus[6], droSize[0] * 0.45, droSize[2] * 0.33),
                DroneHeli(droCorpus[7], droSize[0] * 0.45, droSize[2] * 0.33)
                
            },
            boundingBox(droPosition, droSize.maximized().mult(Vector3I{2.0, 2.0, 0.0}) + Vector3I{0, 0, droSize[2] * 1.5}) {

            targetPosition = droPosition;    
        }

        void UpDate(float dt, Core& core);
        
        void TurnHelis(bool on_off) {

            for (DroneHeli& heli : droHelis) {
                
                heli.enabled = on_off;

            }

        }

        void SaveToFile(const std::string& filename) {

            droCorpus.SaveToFile(filename + "_corpus");

            for (uint i = 0; i < 4; i++) {
        
                droHelis[i].SaveToFile(filename + "_heli" + std::to_string(i));

            }
        
        }
        

        std::vector<std::string> GetGNUPlotFilenames(const std::string& filename) const {

            std::vector<std::string> filenames{filename + "_corpus"};

            for (uint i = 0; i < 4; i++) {

                filenames.push_back(filename + "_heli" + std::to_string(i));

            }

            return filenames;

        }
};

std::ostream &operator<<(std::ostream &out, Drone const &drone);