#ifndef SENSOR_UTILS_SENSOR_H
#define SENSOR_UTILS_SENSOR_H
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <iostream>

#include <lms/time.h>

namespace sensor_utils{
class Sensor {
    std::string m_name;
    size_t m_sensorId;
    lms::Time m_timestamp; //!< Timestamp of measurement in SENSOR timebase
public:
    Sensor():m_sensorId(0), m_timestamp(lms::Time::ZERO){}
    Sensor(std::string name):m_name(name),m_sensorId(0), m_timestamp(lms::Time::ZERO){}
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

    virtual void print(std::ostream& out) const{
        (void)out;
    }
    friend std::ostream& operator<<(std::ostream& out, const Sensor& sensor)
    {
        sensor.print(out);
        return out;
    }
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
    std::size_t size() const{
        return m_sensors.size();
    }

    iterator begin() { return m_sensors.begin(); }
    iterator end() { return m_sensors.end(); }

    const_iterator begin() const { return m_sensors.begin(); }
    const_iterator end() const { return m_sensors.end(); }
protected:
    //! Sensor data storage
    container m_sensors;
};

struct SensorHasUpdate{
    //We could use Sensor
private:
    std::vector<Sensor> sensors;
public:
    bool hasSensor(const Sensor &sensor){
        for(const Sensor &s:sensors){
            if(s.name() == sensor.name()){
                return true;
            }
        }
        return false;
    }

    bool hasUpdate(const Sensor &sensor) const{
        for(const Sensor &s:sensors){
            if(s.name() == sensor.name()){
                return s.timestamp() < sensor.timestamp();
            }
        }
        //TODO error handling
        return false;
    }
    void updateSensor(const Sensor &sensor){
        for(Sensor &s:sensors){
            if(s.name() == sensor.name()){
                s.timestamp(sensor.timestamp());
            }
        }
    }
    void addSensor(const Sensor &s){
        sensors.push_back(s);
    }
};

}

#endif //SENSOR_UTILS_SENSOR_H
