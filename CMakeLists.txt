cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Nemsta VERSION 0.1 LANGUAGES CXX)

###############################################################################
## target definitions #########################################################
###############################################################################

file(GLOB SOURCES
 main.cpp
 inc/util/*.hpp 
 src/util/*.cpp
 )
 
 message("Following sources found:")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

#Generate the shared library from the sources
add_executable(Nemsta ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
#set_property(TARGET Nemsta PROPERTY CXX_STANDARD 11)
#set_property(TARGET Nemsta PROPERTY CXX_STANDARD_REQUIRED ON)
add_definitions("-DSTDCXX_98_HEADERS -D_SNMPv3")

###############################################################################
## generate documentation #####################################################
###############################################################################

find_package(Doxygen)
#set(DOXYGEN_EXECUTABLE ${CMAKE_CURRENT_LIST_DIR}/env/doxygen-1.8.11/bin/doxygen)
add_custom_target (doc ALL
	${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/doxy/*.doxyfile
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxy
)

###############################################################################
## dependencies ###############################################################
###############################################################################

# THREADS
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#SNMPDao
set(SNMPDAO_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPDao/lib)
set(SNMPDAO_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPDao/inc)

find_library(
    SNMPDAO_LIBRARIES
    NAMES SNMPDao
    PATHS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPDao
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

#SNMP++
set(SNMP_PP_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/lib)
set(SNMP_PP_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/include)

find_library(
    SNMP_PP_LIBRARIES
    NAMES snmp++
    PATHS ${CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/lib
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

#SNMPLib
set(SNMPLIB_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPLib/lib)
set(SNMPLIB_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPLib/inc)

find_library(
    SNMPLIB_LIBRARIES
    NAMES SNMPLib
    PATHS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPLib
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

include_directories(${SNMPDAO_INCLUDE_DIRS} ${SNMPLIB_INCLUDE_DIRS} ${SNMP_PP_INCLUDE_DIRS})
link_directories(${SNMPDAO_LIBRARY_DIRS} ${SNMPLIB_LIBRARY_DIRS} ${SNMP_PP_LIBRARY_DIRS})
target_link_libraries(Nemsta ${SNMPDAO_LIBRARIES} ${SNMPLIB_LIBRARIES} ${SNMP_PP_LIBRARIES} Threads::Threads)