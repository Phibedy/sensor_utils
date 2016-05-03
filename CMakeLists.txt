set ( SOURCES
    "src/line_depth_environment.cpp"
)

set (HEADERS
    "include/sensor_utils/line_depth_environment.h"
    "include/sensor_utils/distance_sensor.h"
    "include/sensor_utils/pid_controller.h"
    "include/sensor_utils/imu.h"
    "include/sensor_utils/plane.h"
    "include/sensor_utils/sensor.h"
    "include/sensor_utils/odometer.h"
)

include_directories("include")
add_library (sensor_utils SHARED ${SOURCES} ${HEADERS})
target_link_libraries (sensor_utils PRIVATE lmscore)
#TODO
#target_link_libraries (sensor_utils PUBLIC imaging)
