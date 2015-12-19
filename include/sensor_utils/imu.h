#ifndef SENSOR_UTILS_IMU_H
#define SENSOR_UTILS_IMU_H

#include "sensor.h"
#include "types.h"

namespace sensor_utils
{

struct IMU : public Sensor{
    typedef Vector3 Measurement;
    typedef Matrix3 Covariance;

    //! Linear acceleration measurement along x,y,z-axes [g]
    Measurement accelerometer;
    //! Angular velocity measurement around x,y,z-axes [rad/s]
    Measurement gyroscope;
    //! Magnetic field strength along x,y,z-axes [T]
    Measurement magnetometer;

    //! Covariance of acceleration measurements
    Covariance accelerometerCovariance;
    //! Covariance of angular velocity measurements
    Covariance gyroscopeCovariance;
    //! Covariance of magnetic field measurements
    Covariance magnetometerCovariance;
};
}

#endif //SENSOR_UTILS_IMU_H
