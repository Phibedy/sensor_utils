#ifndef SENSOR_UTILS_IMU_H
#define SENSOR_UTILS_IMU_H

#include "sensor.h"
namespace sensor_utils{
struct Vector{
    float x;
    float y;
    float z;
};

struct IMU: public Sensor{
    Vector acc;
    Vector gyro;
    Vector magnetometer;
};
}

#endif //SENSOR_UTILS_IMU_H
