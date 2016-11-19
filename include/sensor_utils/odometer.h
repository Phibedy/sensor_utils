#ifndef SENSOR_UTILS_ODOMETER_H
#define SENSOR_UTILS_ODOMETER_H

#include "sensor.h"
#include "types.h"

namespace sensor_utils
{
struct Odometer : public Sensor
{
    typedef Vector3 Measurement;
    typedef Matrix3 Covariance;

    //! Distance travelled within last time-step along x,y,z-axis [m]
    Measurement distance;
    /**
     * @brief absDistance Distance travelled (doesn't have to be the sum of all distances)
     */
    Measurement absDistance;

    //! Current velocity along x,y,z-axis [m/s]
    Measurement velocity;

    //! Covariance of distance measurements
    Covariance distanceCovariance;
    //! Covariance of velocity measurements
    Covariance velocityCovariance;

    //! Quality indication number in [0,1] (higher is better)
    float quality;

    void print(std::ostream& out) const
    {
        out << "Odometer [ "
        << "distance: " << distance << " | "
        << "velocity: " << velocity
        << " ]";
    }
};
} //sensor_utils


#endif //SENSOR_UTILS_ODOMETER_H
