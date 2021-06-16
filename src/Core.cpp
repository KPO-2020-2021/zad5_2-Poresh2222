#include "../inc/Core.hh"
#include "../inc/helpers/Size.hh"
#include "../inc/Objects/Drone.hh"
#include "../inc/Objects/Object.hh"
#include "../inc/Matrix/Matrix3x3.hh"


void Core::NewDrone(

        const Vector3I startCenter,

        const Vector3I sizeTab,

        const int objectIndex

    ) {

    Matrix3D matrixOne, matrixDro, matrixHel;


    MatrixOne.push_back(matrixOne);

    MatrixDro.push_back(matrixDro);

    MatrixHel.push_back(matrixHel);


    Dro.push_back(Drone(startCenter, sizeTab));


    std::cout << objectIndex << " <-- Object Index" << std::endl;


    GetDrone(objectIndex);

}

void Core::GetDrone(

        const int objectIndex

    ) {

    std::cout << Dro.at(objectIndex) << std::endl;


    std::cout << MatrixOne.at(objectIndex) << std::endl;

    std::cout << MatrixDro.at(objectIndex) << std::endl;

    std::cout << MatrixHel.at(objectIndex) << std::endl;

}

void Core::DelDrone(

        const int objectIndex

    ) {
    
    Dro.erase(Dro.begin() + objectIndex);

    std::cout << "\nComplete\n\n" << objectIndex << " <-- index DelObj" << std::endl;

}

void Core::FlyControl(

        const int objectIndex,

        bool launchStatus

    ) {

    if (launchStatus == false) {

        std::cout << "All is ready!" << std::endl;

    }

    if (launchStatus == true) {

        Dro.at(objectIndex).UpDate();

        std::cout << Dro.at(objectIndex) << std::endl;

    }

}



//Dro.at(objectIndex).droHelis[j]

//    for (Drone &drone : Dro) {
//
//        drone.UpDate();
//
//    }