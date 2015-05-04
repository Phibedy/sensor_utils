set ( SOURCES 
	"src/line_depth_environment.cpp"

)

set (HEADERS 
	"include/sensor_utils/line_depth_environment.h"
)

include_directories("include")
add_library (sensor_utils SHARED ${SOURCES} ${HEADERS})
#target_link_libraries (imaging PRIVATE lms)
