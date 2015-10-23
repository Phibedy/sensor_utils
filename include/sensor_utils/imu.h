#ifndef SENSOR_UTILS_IMU_H
#define SENSOR_UTILS_IMU_H

namespace sensor_utils{
struct Vector{
    float x;
    float y;
    float z;
};

struct IMU{
    Vector acc;
    Vector gyro;
    Vector magnetometer;
};
}

#endif //SENSOR_UTILS_IMU_H
