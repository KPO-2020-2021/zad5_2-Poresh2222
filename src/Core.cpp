#include "../inc/Core.hh"
#include "../inc/helpers/Size.hh"
#include "../inc/Objects/Drone.hh"
#include "../inc/Objects/Object.hh"


void Core::NewDrone(

        const Vector3I startCorner,

        const Vector3I sizeTab

        //const int objectIndex

    ) {

    Vector3I corpusDroneTab[CUBE];

    


    Vec.push_back(startCorner);


    for (int i = 0; i < CUBE; ++i) {

        for (int j = 0; j < ROWS; ++j) {

            if ((i == 1 && j == 0) || 
                (i == 2 && j != 2) || 
                (i == 3 && j == 1) ||
                (i == 4 && j == 2) ||
                (i == 5 && j != 1) ||
                (i == 6 && j != 3) ||
                (i == 7 && j != 0) ){

                corpusDroneTab[i][j] = startCorner[j] + sizeTab[j];

            } else {

                corpusDroneTab[i][j] = startCorner[j];

            }

        }

        std::cout << corpusDroneTab[i] << std::endl;

    }

    Drone Drone(corpusDroneTab);

    Dro.push_back(Drone);

    std::cout << Drone << std::endl;

}