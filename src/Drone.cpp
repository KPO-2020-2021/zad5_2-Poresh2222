#include "../inc/Objects/Drone.hh"
#include "Core.hh"
#include "Vector3I.cpp"

void Drone::UpDate(float dt, Core& core) {

    Vector3I distance = targetPosition - droCorpus.GetPivot();

    Vector3I translation;

    Vector3I product;

    float max_translation = MAX_VELOCITY * dt;

    float max_rotation = FLIGHT_ROTATION * dt;

    float angleFlyRot, rotation = max_rotation;

    std::cout << "| " << targetPosition << " <-- TargetPosition |" << " | " << distance << " <-- Distance |" << " | " << droCorpus.GetPivot() << " <-- Pivot |" << std::endl;

    if (distance.length() > 0) {

        if (distance.cast<2>().length() > 0.0f) {

            if (droCorpus.GetPivot()[2] < FLIGHT_HEIGHT) {

                distance = Vector3I{0.0f, 0.0f, FLIGHT_HEIGHT};

            } else {

                distance[2] = 0.0f;

                angleFlyRot = acos(droCorpus.GetDirection().scalar(distance.normalized())) * 180 / M_PI;

                angleFlyRot = floor(angleFlyRot);

                //std::cout << angleFlyRot << " -> generate\n" << std::endl;

                if (angleFlyRot != 0.0f) {

                    //std::cout << angleFlyRot << " -> in If != 0.0f\n" << std::endl;

                    if (angleFlyRot < rotation) {

                        rotation = angleFlyRot;

                    }

                    if (cross(droCorpus.GetDirection(), distance.normalized())[2] < 0) {

                        rotation *= -1.0f;

                    }

                    Matrix3D m = Matrix3D::Rotate_Z(rotation);

                    droCorpus.Rotate(m);

                    for (DroneHeli &heli: droHelis) {

                        heli.Rotate(m, droCorpus.GetPivot());

                    }

                    distance = Vector3I();

                }
                
            }

        } else {

            bool ok = false;

            do {

                ok = true;

                auto targetBB  = boundingBox;
                targetBB.Translate(distance);

                for (auto& obstacle : core.Obstacles) {

                    if (obstacle.boundingBox.DoesIntersect(targetBB)) {

                        ok = false;

                        break;

                    }

                }

                if (!ok) {

                    targetPosition += Vector3I{50, 50, 0}.mult(Vector3I{(double)(-1 + rand() % 3), (double)(-1 + rand() % 3), 0.0});
                    distance = targetPosition - droCorpus.GetPivot();

                }

            } while (!ok);
            
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

    boundingBox.Translate(translation);

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
