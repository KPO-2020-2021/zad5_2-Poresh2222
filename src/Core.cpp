#include "../inc/Core.hh"
#include "../inc/helpers/Size.hh"
#include "../inc/Objects/Drone.hh"
#include "../inc/Objects/Object.hh"


void Core::NewDrone(

        const Vector3I startCorner,

        const Vector3I sizeTab

        //const int objectIndex

    ) {
    
    //Vector4I heliTab[4];

    Vector3I supportCorners, heliSize, startHeliCorner[HELITAB], corpusDroneTab[CUBE], corpusHeliTab[HELI];

    //Drone<8>* arr[5];


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

    }

    std::cout << "\n" << corpusDroneTab << "corpusTab" << std::endl;


    //DroneCorpus DroneCorpus(corpusDroneTab);

    //std::cout << "\n" << DroneCorpus << "corpus" << std::endl;


    //arr[0] = new DroneCorpus(corpusDroneTab);

    

    for (int i = 0; i < 3; ++i) {

        if (i == 0 || i == 1) {

            heliSize[i] = round(sizeTab[0] * 0.31);

        } else {

            heliSize[i] = round(sizeTab[i] * 0.33);

        }

        std::cout << "\n" << heliSize[i] << " heliSize" << std::endl;

    }

    for (int i = 0; i < HELITAB; ++i) {

        startHeliCorner[i] = corpusDroneTab[4 + i];

        std::cout << "\n" << startHeliCorner[i] << "startcorners" << std::endl;

    }

    for (int i = 0; i < HELITAB; ++i) {
        
        supportCorners = startHeliCorner[i];

        for (int j = 0; j < HELI; ++j) {

            if (j > 7) {supportCorners[2] = supportCorners[2] + heliSize[2];}

            for (int k = 0; k < ROWS; ++k) {

                if (((j == 0 || j == 3 || j == 8 || j == 11) && k == 0) || ((j == 2 || j == 10 || j == 5 || j == 13) && k == 1)) {

                    corpusHeliTab[j][k] = supportCorners[k] + (heliSize[k] / 2);

                }

                if (((j == 4 || j == 12 || j == 7 || j == 15) && k == 0) || ((j == 1 || j == 9 || j == 6 || j == 14) && k == 1)) {

                    corpusHeliTab[j][k] = supportCorners[k] - (heliSize[k] / 2);
                    
                }

                if (((j == 1 || j == 9 || j == 2 || j == 10) && k == 0) || ((j == 3 || j == 11 || j == 4 || j == 12) && k == 1)) {

                    corpusHeliTab[j][k] = supportCorners[k] + heliSize[k];

                }

                if (((j == 5 || j == 13 || j == 6 || j == 14) && k == 0) || ((j == 0 || j == 8 || j == 7 || j == 15) && k == 1)) {

                    corpusHeliTab[j][k] = supportCorners[k] - heliSize[k];

                }

                if (k == 2) {

                    corpusHeliTab[j][k] = supportCorners[k];

                }
                
            }

            supportCorners = startHeliCorner[i];

        }

        DroneHeli DroneHeli(corpusHeliTab);

        std::cout << "\n" << DroneHeli << "heli" << std::endl;

    }

    //Dro.push_back(DroneCorpus);

}