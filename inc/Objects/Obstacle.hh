#pragma once

#include "Box.hh"

class Obstacle : public Object<5> {

    public:

        Box boundingBox;


        Obstacle(Vector3I pivot, Vector3I size) : boundingBox(pivot, size) {

            this->pivot = pivot;
            auto halfSize = size / 2;
            halfSize[2] = 0.0;

            lokCorners[0] = pivot + halfSize;
            lokCorners[1] = pivot - halfSize;
            lokCorners[2] = pivot + halfSize.mult(Vector3I{-1, 1, 0});
            lokCorners[3] = pivot + halfSize.mult(Vector3I{1, -1, 0});
            lokCorners[4] = pivot + Vector3I{0, 0, size[2]};

            indices = std::vector<int>{0, 2, 1, 3, 0, 4, 1, 4, 2, 4, 3};

        }

        std::vector<std::string> GetGNUPlotFilenames(const std::string& filename) const {

            std::vector<std::string> filenames{filename};
            return filenames;

        }
};