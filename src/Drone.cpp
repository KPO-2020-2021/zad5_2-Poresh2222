#include "../inc/Objects/Drone.hh"


void Drone::UpDate() {

    droCorpus.UpDate();

    for (DroneHeli &heli: droHelis) {

        heli.UpDate();

    }

}

void DroneCorpus::UpDate() {



}

void DroneHeli::UpDate() {

    Matrix3D Mat = Mat.Rotate_Z(1);

    for (int j = 0; j < 100; ++j) {

        for (int i = 0; i < 16; ++i) {

            (*this)[i] = Mat * (*this)[i];

        }

    }

}

std::ostream &operator<<(std::ostream &out, Drone const &drone) {
    
    out << "\nCorpus\n---------------------------------------------\n" << drone.droCorpus << "---------------------------------------------\n" << std::endl;

    for (int i = 0; i < 4; i++) {

        out << "Helis " << i+1 << "\n" <<"---------------------------------------------\n" << drone.droHelis[i] << "---------------------------------------------\n" << std::endl;

    }

  return out;

}
