#pragma once

#include "Object.hh"

class Box : public Object<8> {

    public:

        Box(Vector3I pivot, Vector3I size) {

            this->pivot = pivot;
            Vector3I halfSize = size / 2;

            Box& self = *this;

            int l = 0;

            for (double i = -1; i <= 1; ++i) {

                for (double j = -1; j <= 1; ++j) {

                    for (double k = -1; k <= 1; ++k) {

                        if (i != 0 && j != 0 && k != 0) {

                            self[l++] = pivot + Vector3I{k, j, i}.mult(halfSize);

                        }

                    }

                }

            }

            indices = std::vector<int>{0, 1, 3, 2, 0, 4, 5, 7, 6, 4, 7, 3, 2, 6, 5, 1};

        }

        bool DoesIntersect(const Box& other) const {

            return  min()[0] <= other.max()[0] && max()[0] >= other.min()[0] &&
                    min()[1] <= other.max()[1] && max()[1] >= other.min()[1] &&
                    min()[2] <= other.max()[2] && max()[2] >= other.min()[2];
        
        }


        Vector3I min() const {

            double xmin = std::numeric_limits<double>().max();
            double ymin = std::numeric_limits<double>().max();
            double zmin = std::numeric_limits<double>().max();

            for (auto corner : lokCorners) {

                if (corner[0] < xmin)
                    xmin = corner[0];
                if (corner[1] < ymin)
                    ymin = corner[1];
                if (corner[2] < zmin)
                    zmin = corner[2];

            }

            return Vector3I{xmin, ymin, zmin};

        }

        Vector3I max() const {

            double xmax = std::numeric_limits<double>().min();
            double ymax = std::numeric_limits<double>().min();
            double zmax = std::numeric_limits<double>().min();

            for (auto corner : lokCorners) {

                if (corner[0] > xmax)
                    xmax = corner[0];
                if (corner[1] > ymax)
                    ymax = corner[1];
                if (corner[2] > zmax)
                    zmax = corner[2];

            }

            return Vector3I{xmax, ymax, zmax};

        }
        
};