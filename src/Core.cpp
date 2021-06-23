#include "../inc/Core.hh"
#include "../inc/helpers/Size.hh"
#include "../inc/Objects/Drone.hh"
#include "../inc/Objects/Object.hh"
#include "../inc/Matrix/Matrix3x3.hh"


void Core::NewDrone(

        const Vector3I startCenter,

        const Vector3I sizeTab,

        PzG::LaczeDoGNUPlota& Lacze

    ) {

    uint id = Dro.size();

    Dro.push_back(Drone(startCenter, sizeTab));  

    std::vector<std::string> filenames = Dro.back().GetGNUPlotFilenames("data/drone" + std::to_string(id));

    for (std::string& name : filenames) {

        Lacze.DodajNazwePliku(name.c_str());

    }

    std::cout << id << " --> Drone Index in vetor Dro" << std::endl;
    std::cout << id + 1 << " --> Drone Index for User\n" << std::endl;

}

Drone& Core::GetDrone(

        const int objectIndex

    ) {

    return Dro[objectIndex];

}

void Core::DelDrone(

        const int objectIndex

    ) {
    
    Dro.erase(Dro.begin() + objectIndex);

    std::cout << "\nComplete\n\n" << objectIndex << " <-- index DelObj" << std::endl;

}

void Core::Update(float dt) {

    for (uint i = 0; i < Dro.size(); ++i) {

        Dro[i].UpDate(dt);
        Dro[i].SaveToFile("data/drone" + std::to_string(i));

    }

}