#ifndef SENSOR_UTILS_PLANE_H
#define SENSOR_UTILS_PLANE_H
#include "sensor_utils/dynamic_entity.h"
#include <cmath>

namespace sensor_utils {
class Plane{
public:
    float q0, q1, q2, q3;	// quaternion of sensor frame relative to auxiliary frame

    float desiredMotorSpeed;
    //rudders in radians
    float rudder; //Seitenruder
    float elevator; //Hoehenruder
    float aileron; //

    float pitch(){
        return atan2(2*q0*q3 - 2*q1*q2, 1 - 2*q0*q0 - 2*q2*q2);
    }

    float yaw(){
        return asin(2*q0*q1 + 2*q2*q3);
    }

    float roll(){
        return atan2(2*q1*q3 - 2*q0*q3, 1 - 2*q2*q2 - 2*q3*q3);
    }

    Plane(){
        q0 = 0;
        q1 = 0;
        q2 = 0;
        q3 = 0;
        desiredMotorSpeed = 0;
        rudder = 0;
        elevator = 0;
        aileron = 0;
    }





};
}//sensor_utils

#endif //SENSOR_UTILS_PLANE_H
