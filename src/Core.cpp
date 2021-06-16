#include "../inc/Core.hh"
#include "../inc/helpers/Size.hh"
#include "../inc/Objects/Drone.hh"
#include "../inc/Objects/Object.hh"


void Core::NewDrone(

        const Vector3I startCenter,

        const Vector3I sizeTab,

        const int objectIndex

    ) {

    Dro.push_back(Drone(startCenter, sizeTab));
    //std::cout << Dro.back() << std::endl;

    std::cout << objectIndex << "<-- Object Index" << std::endl;

    GetDrone(objectIndex);

}

void Core::GetDrone(

        const int objectIndex

    ){

    std::cout << Dro.at(objectIndex) << std::endl;

}