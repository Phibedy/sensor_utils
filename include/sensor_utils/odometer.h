#ifndef SENSOR_UTILS_ODOMETER_H
#define SENSOR_UTILS_ODOMETER_H
#include "sensor.h"
namespace sensor_utils{
class Odometer:public Sensor{
public:
    float xdist; /*< Distance travelled along x-axis [m]*/
    float ydist; /*< Distance travelled along y-axis [m]*/
    float zdist; /*< Distance travelled along z-axis [m]*/
    float xvelocity; /*< Velocity along x-axis [m/s]*/
    float yvelocity; /*< Velocity along y-axis [m/s]*/
    float zvelocity; /*< Velocity along z-axis [m/s]*/

};
}//sensor_utils


#endif //SENSOR_UTILS_ODOMETER_H
