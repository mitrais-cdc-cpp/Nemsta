cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
set (EXECUTABLE_OUTPUT_FILE_NAME TestSuite)

project(${EXECUTABLE_OUTPUT_FILE_NAME} VERSION 0.2 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")
set (UNITTEST_CMAKE_CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
	main.cpp	
	*.h
	*.cpp
	*.hpp
	../inc/util/*.h
	../src/util/*.cpp)
 

message("Following sources found: ")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

###############################################################################
## target definitions #########################################################
###############################################################################

add_executable(${EXECUTABLE_OUTPUT_FILE_NAME} ${SOURCES})
target_compile_definitions(${EXECUTABLE_OUTPUT_FILE_NAME} PRIVATE LIBODB_MYSQL_INCLUDE_SHORT=1)
#add_definitions(-DLIBODB_MYSQL_INCLUDE_SHORT)

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET ${EXECUTABLE_OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${EXECUTABLE_OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

#set warning level
set_property(TARGET ${EXECUTABLE_OUTPUT_FILE_NAME} APPEND_STRING PROPERTY COMPILE_FLAGS "-Wno-deprecated")

###############################################################################
## generate documentation #####################################################
###############################################################################

find_package(Doxygen)
add_custom_target (doc ALL
	${DOXYGEN_EXECUTABLE} ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/doxy/*.doxyfile
	WORKING_DIRECTORY ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/doxy)

###############################################################################
## dependencies ###############################################################
###############################################################################

#SNMPDao
set(SNMPDAO_LIBRARY_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/SNMPDao/lib)
set(SNMPDAO_INCLUDE_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/SNMPDao/inc)
find_library(
    SNMPDAO_LIBRARIES
    NAMES SNMPDao
    PATHS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/SNMPDao
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH)

#SNMP++
set(SNMP_PP_LIBRARY_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/lib)
set(SNMP_PP_INCLUDE_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/include)
find_library(
    SNMP_PP_LIBRARIES
    NAMES snmp++
    PATHS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/snmp_pp/lib
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH)

#SNMPLib
set(SNMPLIB_LIBRARY_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/SNMPLib/lib)
set(SNMPLIB_INCLUDE_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/SNMPLib/inc)
find_library(
    SNMPLIB_LIBRARIES
    NAMES SNMPLib
    PATHS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/SNMPLib
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH)

#ODB
set(ODB_LIBRARY_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/odb/lib)  
set(ODB_INCLUDE_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/odb/include)  
find_library(  
	ODB_LIBRARIES  
	NAMES odb libodb
	PATHS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/odb/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH)

#ODB_MYSQL
set(ODB_MYSQL_LIBRARY_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/odb-mysql/lib)  
set(ODB_MYSQL_INCLUDE_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/odb-mysql/include)  
find_library(  
	ODB_MYSQL_LIBRARIES  
	NAMES odb-mysql libodb-mysql
	PATHS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/odb-mysql/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH)

#MYSQL_CLIENT
set(MYSQL_CLIENT_LIBRARY_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/lib)  
set(MYSQL_CLIENT_INCLUDE_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/include)  
find_library(  
	MYSQL_CLIENT_LIBRARIES  
	NAMES mysqlclient
	PATHS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH)

# CPPUNIT
set( CPPUNIT_INCLUDE_DIRS ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/cppunit/1.12.1/include)
set( CPPUNIT_LIBRARY ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/env/cppunit/1.12.1/lib/libcppunit.so)


include_directories(${SNMPDAO_INCLUDE_DIRS}
		${SNMPDAO_INCLUDE_DIRS}/Entity
		${SNMP_PP_INCLUDE_DIRS}
		${SNMPLIB_INCLUDE_DIRS}
		${ODB_INCLUDE_DIRS}
		${ODB_MYSQL_INCLUDE_DIRS}
		${MYSQL_CLIENT_INCLUDE_DIRS}
		${CPPUNIT_INCLUDE_DIRS})


link_directories(${SNMPDAO_LIBRARY_DIRS}
		${SNMPLIB_LIBRARY_DIRS}
		${SNMP_PP_LIBRARY_DIRS}
		${ODB_LIBRARY_DIRS}
		${ODB_MYSQL_LIBRARY_DIRS}
		${MYSQL_CLIENT_LIBRARY_DIRS}
		${CPPUNIT_LIBRARY})


target_link_libraries(${EXECUTABLE_OUTPUT_FILE_NAME}
	${SNMPDAO_LIBRARIES}
	${SNMPLIB_LIBRARIES}
	${SNMP_PP_LIBRARIES}
	${ODB_LIBRARIES}
	${ODB_MYSQL_LIBRARIES}
	${MYSQL_CLIENT_LIBRARIES}
	${CPPUNIT_LIBRARY})


###############################################################################
## clean ######################################################################
###############################################################################

if(UNIX)
    add_custom_target (distclean @echo cleaning generated cmake-files)
    add_custom_command(
        COMMENT "cmake generated clean"
        COMMAND make ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeCache.txt" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeFiles" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "Makefile" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.cmake" | xargs rm -rf
        COMMAND rm ARGS -rf ${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt
        TARGET  distclean)

    add_custom_target (projclean @echo cleaning generated project-files)
    add_custom_command(
        COMMENT "project generated clean"
        COMMAND make ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".csettings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".settings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".project" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".cproject" | xargs rm -rf
        TARGET  projclean)

    add_custom_target (clean-all @echo cleaning generated project- and cmake-files)
    add_custom_command(
        COMMENT "cmake & project generated clean"
        COMMAND make ARGS -C ${CMAKE_CURRENT_BINARY_DIR} clean
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "build" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".csettings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".settings" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".project" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name ".cproject" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeCache.txt" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "CMakeFiles" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "Makefile" | xargs rm -rf
        COMMAND find ARGS ${CMAKE_CURRENT_BINARY_DIR} -name "*.cmake" | xargs rm -rf
        COMMAND rm ARGS -rf ${CMAKE_CURRENT_BINARY_DIR}/install_manifest.txt
        TARGET  clean-all)
endif(UNIX)

#copy config file to the output directory
file(COPY ${UNITTEST_CMAKE_CURRENT_LIST_DIR}/mysql.config DESTINATION .)