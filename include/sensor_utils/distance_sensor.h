#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H
#include "lms/math/vertex.h"
#include "sensor.h"


namespace sensor_utils{

class DistanceSensorRadial:public Sensor{
public:
    DistanceSensorRadial():localPosition(0,0),minDistance(0),maxDistance(0),direction(0),startAngle(0),anglePerIndex(0){}

    lms::math::vertex2f localPosition;
    float minDistance;
    float maxDistance;
    /**
     * @brief direction angle in radians
     */
    float direction;
    /**
     * @brief startAngle first angle of the measurement in radians
     */
    float startAngle;
    /**
     * @brief anglePerIndex in radians
     */
    float anglePerIndex;
    /**
     * @brief distances in m
     */
    std::vector<float> distances;
    /**
     * @brief intensities value between 0 and 1
     */
    std::vector<float> intensities;

    std::vector<lms::math::vertex2f> getXY(){
        std::vector<lms::math::vertex2f> v;
        for(int i = 0; i < (int)distances.size(); i++){
            float angle = startAngle + i*anglePerIndex -direction;
            v.push_back(lms::math::vertex2f(distances[i]*cos(angle),distances[i]*sin(angle)));
        }
        return v;
    }

    int indexFromAngle() const{
        return 0; //TODO
    }

};

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
