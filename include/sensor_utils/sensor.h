#ifndef SENSOR_UTILS_SENSOR_H
#define SENSOR_UTILS_SENSOR_H
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

#include <lms/extra/time.h>

namespace sensor_utils{
class Sensor {
    std::string m_name;
    size_t m_sensorId;
    lms::Time m_timestamp; //!< Timestamp of measurement in SENSOR timebase
public:
    std::string name() const{
        return m_name;
    }
    void name(const std::string& name){
        m_name = name;
    }
    size_t sensorId() const{
        return m_sensorId;
    }

    void sensorId(size_t sensorId){
        m_sensorId = sensorId;
    }

    lms::Time timestamp() const {
        return m_timestamp;
    }

    void timestamp(lms::Time timestamp) {
        m_timestamp = timestamp;
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
    std::shared_ptr<T> sensor(const std::string& name) const {
        const auto it = m_sensors.find(name);
        if(it != m_sensors.end())
        {
            // Found sensor
            return std::static_pointer_cast<T>( it->second );
        }
        return std::make_shared<T>();
    }
    bool hasSensor(const std::string& name) const {
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
