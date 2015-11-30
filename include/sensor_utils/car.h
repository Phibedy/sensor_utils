#ifndef SENSOR_UTILS_CAR_H
#define SENSOR_UTILS_CAR_H
#include "sensor_utils/dynamic_entity.h"
#include "lms/extra/time.h"

#ifdef USE_CEREAL
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/base_class.hpp"
#endif

namespace sensor_utils {
/**
  *TODO Add hasState()
 * @brief The Car class
 */
class Car:public DynamicEntity{
public:
    Car(){
    }
    enum class StateType{
        NOT_DEFINED,IDLE,DRIVING,PARKING,RACE
    };
    struct State{
        State():priority(0),state(StateType::NOT_DEFINED),startState(lms::extra::PrecisionTime::ZERO),
            endState(lms::extra::PrecisionTime::ZERO),steering_front(0),steering_rear(0),targetSpeed(0){}

        /**
         * @brief priority of the state, for example StateType::DRIVING could have priority 1, PARKING could have 2 -> the car would par
         */
        int priority;
        std::string name;
        StateType state;

        /**
         * @brief startState
         */
        lms::extra::PrecisionTime startState;
        /**
         * @brief endState time till the car should do something (for example idle)
         */
        lms::extra::PrecisionTime endState;
        float steering_front, steering_rear;
        float targetSpeed;

        bool intime(const lms::extra::PrecisionTime &currentTime) const{
            if(endState == lms::extra::PrecisionTime::ZERO){
                return true;
            }
            return startState < currentTime && currentTime < endState;
        }

        template <class Archive>
        void serialize( Archive & archive) {
            archive(priority, name, state, startState, endState, steering_front,
                    steering_rear, targetSpeed);
        }
    };
public:

    std::vector<State> states; //TODO not sure if it should be public

    State getPrioState() const{
        if(states.size() == 0){
            //TODO throw error
            return State();
        }
        State prio = states[0];
        for(uint i = 1; i < states.size();i++){
            if(states[i].priority > prio.priority)
                prio = states[i];
        }
        return prio;
    }

    float steeringFront() const{
        return getPrioState().steering_front;
    }

    float steeringRear() const{
        return getPrioState().steering_rear;
    }

    float targetSpeed() const{
        return getPrioState().targetSpeed;
    }

    void addState(State &s){
        states.push_back(s);
    }

    void putState(State &s){
        for(uint i = 0; i < states.size(); i++){
            if(states[i].name == s.name){
                states[i] = s;
                return;
            }
        }
        addState(s);
    }

    bool removeState(const std::string &name){
        for(uint i = 0; i < states.size();){
            if(states[i].name == name){
                states.erase(states.begin()+i);
                return true;
            }else{
                i++;
            }
        }
        return false;
    }

    State* getState(const std::string &name){
        for(State &s:states){
            if(s.name == name)
                return &s;
        }
        return nullptr;
    }

    /**
     * @brief validateStates removed invalid/outdated states
     * @param currentTime
     */
    void validateStates(const lms::extra::PrecisionTime &currentTime){
        for(uint i = 0; i < states.size();){
            //TODO
            /*
            if(!states[i].intime(currentTime)){
                states.erase(states.begin()+i);
            }else{
                i++;
            }
            */
        }
    }

    // cereal implementation
#ifdef USE_CEREAL
    //get default interface for datamanager
    CEREAL_SERIALIZATION()

    template <class Archive>
    void serialize( Archive & archive) {
        //TODO
        archive(states);
        archive(cereal::base_class<DynamicEntity>(this));
    }
#endif
};
}//sensor_utils

#endif //SENSOR_UTILS_CAR_H
