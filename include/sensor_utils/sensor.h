#ifndef SENSOR_UTILS_SENSOR_H
#define SENSOR_UTILS_SENSOR_H
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

namespace sensor_utils{
class Sensor {
    std::string m_name;
    size_t m_sensorId;
public:
    std::string name() const{
        return m_name;
    }
    void name(const std::string& name){
        m_name = name;
    }
    int sensorId() const{
        return m_sensorId;
    }

    void sensorId(size_t sensorId){
        m_sensorId = sensorId;
    }

    friend std::ostream& operator<<(std::ostream& out, const Sensor& sensor)
    {
        sensor.print(out);
        return out;
    }
    virtual void print(std::ostream& out) const = 0;
};
typedef  std::shared_ptr<Sensor> SensorPtr;
/**
  //TODO create a sensor-map, use polygons to check if a sensor covers a region and return the point-cloud
 * @brief The SensorContainer class
 */
class SensorContainer{
protected:
    typedef std::unordered_map<std::string, SensorPtr> container;
public:
    typedef container::iterator iterator;
    typedef container::const_iterator const_iterator;
public:
    template<typename T>
    std::shared_ptr<T> sensor(const std::string& name){
        const auto it = m_sensors.find(name);
        if(it != m_sensors.end())
        {
            // Found sensor
            return std::static_pointer_cast<T>( *it );
        }
        return std::make_shared<T>(nullptr);
    }
    bool hasSensor(const std::string& name){
        return ( m_sensors.find(name) != m_sensors.end() );
    }
    void put(SensorPtr toAdd){
        m_sensors[toAdd->name()] = toAdd;
    }

    iterator begin() { return m_sensors.begin(); }
    iterator end() { return m_sensors.end(); }

    const_iterator begin() const { return m_sensors.begin(); }
    const_iterator end() const { return m_sensors.end(); }
protected:
    //! Sensor data storage
    container m_sensors;
};
}

#endif //SENSOR_UTILS_SENSOR_H
