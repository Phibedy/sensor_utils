if(USE_CONAN)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
endif(USE_CONAN)

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
    "include/sensor_utils/parking_sensor.h"
)

include_directories("include")
#set compiler flags
if((${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang") OR (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU"))
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wreturn-type -Wpedantic ")
endif()


add_library (lms_sensor_utils SHARED ${SOURCES} ${HEADERS})
if(USE_CONAN)
target_link_libraries (lms_sensor_utils PRIVATE ${CONAN_LIBS})
else()
target_link_libraries (lms_sensor_utils PRIVATE lms_math)
endif(USE_CONAN)
