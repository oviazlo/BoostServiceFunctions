CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )

PROJECT( BoostServiceFunctions )

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")

SET( PROJECT_VERSION_MAJOR 0 )
SET( PROJECT_VERSION_MINOR 1 )

INCLUDE_DIRECTORIES ( ${PROJECT_SOURCE_DIR}/include )
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../BoostServiceFunctions/)

SET( CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR} )
LIST ( APPEND CMAKE_CXX_FLAGS "-O3 -Wall -Wextra -Wshadow -ansi -Wno-long-long -Wuninitialized -fopenmp -flto -Weffc++ --std=c++11 -ggdb" )
LIST ( APPEND CMAKE_LD_FLAGS "-flto -O3 -ggdb" )

find_package ( ROOT REQUIRED )
include(${ROOT_USE_FILE})

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS program_options) 
include_directories(${Boost_INCLUDE_DIRS}) 

ADD_SUBDIRECTORY ( ${PROJECT_SOURCE_DIR}/libTesting )

MESSAGE (STATUS "*** Build Type ${CMAKE_BUILD_TYPE} ***" )
MESSAGE (STATUS "*** Compiler Flags:  ${CMAKE_CXX_FLAGS}"  )
MESSAGE (STATUS "*** Compiler Flags:  ${CMAKE_CXX_FLAGS_DEBUG}"  )

ADD_LIBRARY( BoostServiceFunctions SHARED src/boostServiceFunctions.cxx )
