#ifndef SENSOR_UTILS_SENSOR_H
#define SENSOR_UTILS_SENSOR_H
#include <string>
#include <vector>
#include <memory>
namespace sensor_utils{
class Sensor{
    std::string m_name;
    int m_sensorId;
public:
    std::string name() const{
        return m_name;
    }
    void name(std::string name){
        m_name = name;
    }
    int sensorId() const{
        return m_sensorId;
    }

    void sensorId(int sensorId){
        m_sensorId = sensorId;
    }
};
typedef  std::shared_ptr<Sensor> SensorPtr;
/**
  //TODO create a sensor-map, use polygons to check if a sensor covers a region and return the point-cloud
 * @brief The SensorContainer class
 */
class SensorContainer{
    std::vector<std::shared_ptr<Sensor>> m_sensors;
public:
    template<typename T>
    std::shared_ptr<T> sensor(std::string name){
        for(SensorPtr s: m_sensors){
            if(s->name() == name)
                return std::static_pointer_cast<T>(s);
        }
        return std::make_shared<T>(nullptr);
    }
    bool hasSensor(std::string name){
        for(SensorPtr s: m_sensors){
            if(s->name() == name)
                return true;
        }
        return false;
    }
    void put(SensorPtr toAdd){
        for(SensorPtr s:m_sensors){
            if(s->name() == toAdd->name()){
                *s = *toAdd; //set the data
                return;
            }
        }
        m_sensors.push_back(toAdd);
    }
};
}

#endif //SENSOR_UTILS_SENSOR_H
