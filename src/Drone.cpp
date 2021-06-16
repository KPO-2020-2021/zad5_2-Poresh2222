#include "../inc/Objects/Drone.hh"

std::ostream &operator<<(std::ostream &out, Drone const &drone) {
    
    out << "\nCorpus\n---------------------------------------------\n" << drone.droCorpus << "---------------------------------------------\n" << std::endl;

    for (int i = 0; i < 4; i++) {

        out << "Helis " << i+1 << "\n" <<"---------------------------------------------\n" << drone.droHelis[i] << "---------------------------------------------\n" << std::endl;

    }

  return out;

}
