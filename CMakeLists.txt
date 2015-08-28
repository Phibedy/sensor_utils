set ( SOURCES
	"src/line_depth_environment.cpp"
    "src/dynamic_entity.cpp"
)

set (HEADERS
	"include/sensor_utils/line_depth_environment.h"
    "include/sensor_utils/dynamic_entity.h"
    "include/sensor_utils/distance_sensor.h"
    "include/sensor_utils/car.h"
)

include_directories("include")
add_library (sensor_utils SHARED ${SOURCES} ${HEADERS})
target_link_libraries (sensor_utils PRIVATE lmscore)
target_link_libraries (sensor_utils PUBLIC imaging)
