#ifndef SENSOR_UTILS_PARKING_SENSOR_H
#define SENSOR_UTILS_PARKING_SENSOR_H

#include "sensor.h"
#include "types.h"

namespace sensor_utils
{
struct ParkingSensor : public Sensor
{
    typedef float GapSize;
    typedef float GapPosition;

    /// defines the size of the detected gap
    GapSize size;


    /// defines the absolute x-position of the SECOND edge of the detected gap
    GapPosition position;


    void print(std::ostream& out) const
    {
        out << "Parking_Sensor [ "
        << "Gap Size: " << size << " | "
        << "position: " << position
        << " ]";
    }
};
} //sensor_utils


#endif //SENSOR_UTILS_PARKING_SENSOR_H
