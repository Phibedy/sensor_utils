#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H
#include "lms/math/vertex.h"
#include "sensor.h"


namespace sensor_utils{
class DistanceSensor:public Sensor{
public:

    DistanceSensor():localPosition(lms::math::vertex2f(0,0)),direction(0),distance(0){

    }

    lms::math::vertex2f localPosition;
    /**
     * @brief direction angle in radians
     */
    float direction;
    float distance;

    float totalX() const{
        return localPosition.x + cos(direction)*distance;
    }

    float totalY() const{
        return localPosition.y + sin(direction)*distance;
    }

    void print(std::ostream& out) const
    {
        out << "Distance [ "
        << "distance: " << distance
        << " ]";
    }
};

typedef std::vector<DistanceSensor> DistanceSensors;
} //namespace sensor_utils

#endif /* SENSOR_ENVIRONMENT_H */
