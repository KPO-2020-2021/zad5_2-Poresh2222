#include "../inc/Objects/Drone.hh"

void Drone::UpDate(float dt) {

    Vector3I distance = targetPosition - droCorpus.GetPivot();

    Vector3I translation;

    float max_translation = MAX_VELOCITY * dt;

    if (distance.length() > 0) {

        if (distance.cast<2>().length() > 0.0f) {

            if (droCorpus.GetPivot()[2] < FLIGHT_HEIGHT) {

                distance = Vector3I{0.0f, 0.0f, FLIGHT_HEIGHT};

            } else {

                distance[2] = 0.0f;
                
                
            }

        }

    } else { return; }

    if (distance.length() > max_translation) {

        translation = distance.normalized() * max_translation;

        TurnHelis(true);

    } else {

        translation = distance;

        if (targetPosition[2] == 0.0f) {

            TurnHelis(false);

        }

    }

    droCorpus.UpDate(dt);

    for (int i = 0; i < 4; i++) {

        droHelis[i].UpDate(dt, i);

    }

    droCorpus.Translate(translation);

    for (DroneHeli &heli: droHelis) {

        heli.Translate(translation);

    }

}


void DroneCorpus::UpDate(float) {
}

void DroneHeli::UpDate(float dt, int index) {

    if (!enabled) {

        return;

    }

    if (index == 0 || index == 3) {
        
        Matrix3D m = Matrix3D::Rotate_Z(ROTATION_SPEED * dt);

        Rotate(m);

    } else {

        Matrix3D m = Matrix3D::Rotate_Z(-(ROTATION_SPEED * dt));

        Rotate(m);

    }

}

std::ostream &operator<<(std::ostream &out, Drone const &drone) {
    
    out << "\nCorpus\n---------------------------------------------\n" << drone.droCorpus << "---------------------------------------------\n" << std::endl;

    for (int i = 0; i < 4; i++) {

        out << "Helis " << i+1 << "\n" <<"---------------------------------------------\n" << drone.droHelis[i] << "---------------------------------------------\n" << std::endl;

    }

  return out;

}
