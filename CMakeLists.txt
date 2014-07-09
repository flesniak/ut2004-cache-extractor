cmake_minimum_required( VERSION 2.4 )
project( cacheext )

find_package( Qt4 COMPONENTS QtGui QtNetwork REQUIRED )

SET( cacheext_SRCS main.cpp cacheext.cpp cache_thread.cpp cache_type.cpp )
SET( cacheext_HDRS cacheext.h cache_thread.h cache_type.h )

include( ${QT_USE_FILE} cacheext_HDRS )

QT4_WRAP_CPP( cacheext_MOC_SRCS ${cacheext_HDRS} )

add_definitions( -O2 )

add_executable( cacheext ${cacheext_SRCS} ${cacheext_MOC_SRCS} )

target_link_libraries( cacheext ${QT_LIBRARIES} )
