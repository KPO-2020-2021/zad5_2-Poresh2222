#include "../inc/Vector/Vector3I.hh"

Vector3I cross(const Vector3I &VL, const Vector3I &VR) {
    Vector3I result;

    result[0] = VL[1] * VR[2] - VL[2] * VR[1];
    result[1] = VL[2] * VR[0] - VL[0] * VR[2];
    result[2] = VL[0] * VR[1] - VL[1] * VR[0];

    return result;

}