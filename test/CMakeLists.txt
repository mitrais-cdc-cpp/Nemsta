cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(NemstaTest VERSION 0.1 LANGUAGES CXX)

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
add_executable(NemstaTest ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(NemstaTest PUBLIC -Wextra)


###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET NemstaTest PROPERTY CXX_STANDARD 11)
set_property(TARGET NemstaTest PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## dependencies ###############################################################
###############################################################################

# CPPUNIT
find_library(CPPUNIT_LIBRARY_DEBUG NAMES cppunit cppunit_dll cppunitd cppunitd_dll
            	PATHS  
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES debug )

find_library(CPPUNIT_LIBRARY_RELEASE NAMES cppunit cppunit_dll
            PATHS   ${PATH}/lib
                    /usr/lib
                    /usr/lib64
                    /usr/local/lib
                    /usr/local/lib64
            PATH_SUFFIXES release )

if(CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)
    set(CPPUNIT_LIBRARY_RELEASE ${CPPUNIT_LIBRARY_DEBUG})
endif(CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)

set( CPPUNIT_LIBRARY debug ${CPPUNIT_LIBRARY_DEBUG} optimized ${CPPUNIT_LIBRARY_RELEASE} )

#SNMPDao
#set(SNMPDAO_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmpdao/lib)
#set(SNMPDAO_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmpdao/inc)

#find_library(
#    SNMPDAO_LIBRARIES
#    NAMES SNMPDao
#    PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/snmpdao
#    PATH_SUFFIXES "lib"
#    NO_DEFAULT_PATH
#)

#SNMPLib
#set(SNMPLIB_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmplib/lib)
#set(SNMPLIB_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/snmplib/inc)

#find_library(
#    SNMPLIB_LIBRARIES
#    NAMES SNMPLib
#    PATHS ${CMAKE_CURRENT_LIST_DIR}/../env/snmplib
#    PATH_SUFFIXES "lib"
#    NO_DEFAULT_PATH
#)

# TEST FILES
#file(GLOB TEST_FILES "test_files/*")
#file(COPY ${TEST_FILES} DESTINATION .)

#include_directories(${SNMPDAO_INCLUDE_DIRS} ${SNMPLIB_INCLUDE_DIRS})
#link_directories(${CPPUNIT_LIBRARY} ${SNMPDAO_LIBRARY_DIRS} ${SNMPLIB_LIBRARY_DIRS})
#target_link_libraries(NemstaTest ${CPPUNIT_LIBRARY} ${SNMPDAO_LIBRARIES} ${SNMPLIB_LIBRARIES})

include_directories()
link_directories(${CPPUNIT_LIBRARY})
target_link_libraries(NemstaTest ${CPPUNIT_LIBRARY} ${CMAKE_DL_LIBS})