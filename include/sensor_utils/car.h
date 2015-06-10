#ifndef SENSOR_UTILS_CAR_H
#define SENSOR_UTILS_CAR_H
#include "sensor_utils/dynamic_entity.h"
#include "senseboard2015.h"

namespace sensor_utils {
struct Car:public DynamicEntity{
        Car():steering_front(0),steering_rear(0),targetSpeed(0){
        }

        float steering_front, steering_rear;
        float targetSpeed;
    };
}//sensor_utils

#endif //SENSOR_UTILS_CAR_H
