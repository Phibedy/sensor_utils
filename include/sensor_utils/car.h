#ifndef SENSOR_UTILS_CAR_H
#define SENSOR_UTILS_CAR_H
#include "sensor_utils/dynamic_entity.h"
#include "senseboard2015.h"
#include "cereal/types/base_class.hpp"

namespace sensor_utils {
class Car:public DynamicEntity{
public:
    Car():steering_front(0),steering_rear(0),targetSpeed(0){
    }

    float steering_front, steering_rear;
    float targetSpeed;

    // cereal implementation
#ifdef USE_CEREAL
    //get default interface for datamanager
    CEREAL_SERIALIZATION()

    template <class Archive>
    void serialize( Archive & archive) {
        archive(steering_front,steering_rear,targetSpeed);
        archive(cereal::base_class<DynamicEntity>(this));
    }
#endif
};
}//sensor_utils

#endif //SENSOR_UTILS_CAR_H
