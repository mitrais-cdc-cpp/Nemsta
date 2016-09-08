cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set (EXECUTABLE_OUTPUT_FILE_NAME TestSuite)

project(${EXECUTABLE_OUTPUT_FILE_NAME} VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
	main.cpp	
	*.h
	*.cpp
	../inc/util/*.h
	../src/util/*.cpp)

#to take control which files are used, dont go recursive through
#file(GLOB_RECURSE SOURCES src/*.cpp inc/*.h)

message("Following sources found:")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(${EXECUTABLE_OUTPUT_FILE_NAME} ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(${EXECUTABLE_OUTPUT_FILE_NAME} PUBLIC -Wextra)


###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET ${EXECUTABLE_OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${EXECUTABLE_OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## dependencies ###############################################################
###############################################################################
#BOOST
set( BOOST_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/boost/1.61.0/include)
set( BOOST_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/boost/1.61.0/lib)

# CPPUNIT
set( CPPUNIT_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/../env/cppunit/1.12.1/include)
set( CPPUNIT_LIBRARY ${CMAKE_CURRENT_LIST_DIR}/../env/cppunit/1.12.1/lib/libcppunit.so)

#SNMPDao
set(SNMPDAO_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPDao/lib)
set(SNMPDAO_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPDao/inc)

find_library(
    SNMPDAO_LIBRARIES
    NAMES SNMPDao
    PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/SNMPDao
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

#SNMPLib
set(SNMPLIB_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPLib/lib)
set(SNMPLIB_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/SNMPLib/inc)

find_library(
    SNMPLIB_LIBRARIES
    NAMES SNMPLib
    PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/SNMPLib
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)

# TEST FILES
#file(GLOB TEST_FILES "test_files/*")
#file(COPY ${TEST_FILES} DESTINATION .)

include_directories(${BOOST_INCLUDE_DIRS} ${CPPUNIT_INCLUDE_DIRS} ${SNMPDAO_INCLUDE_DIRS} ${SNMPLIB_INCLUDE_DIRS})
link_directories(${BOOST_LIBRARY_DIRS} ${CPPUNIT_LIBRARY} ${SNMPDAO_LIBRARY_DIRS} ${SNMPLIB_LIBRARY_DIRS})
target_link_libraries(${EXECUTABLE_OUTPUT_FILE_NAME} ${CPPUNIT_LIBRARY} ${SNMPDAO_LIBRARIES} ${SNMPLIB_LIBRARIES} ${CMAKE_DL_LIBS})