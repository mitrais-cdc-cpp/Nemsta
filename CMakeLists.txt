cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(Nemsta VERSION 0.1 LANGUAGES CXX)

###############################################################################
## target definitions #########################################################
###############################################################################

file(GLOB SOURCES
 	main.cpp
 	inc/*.hpp
 	inc/util/*.hpp
 	src/*.cpp
 	src/util/*.cpp)
 
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
set_property(TARGET Nemsta PROPERTY CXX_STANDARD 11)
set_property(TARGET Nemsta PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## generate documentation #####################################################
###############################################################################

#find_package(Doxygen)
set(DOXYGEN_EXECUTABLE ${CMAKE_CURRENT_LIST_DIR}/env/doxygen-1.8.11/bin/doxygen)
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

# ODB
set(ODB_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/odb/lib)  
set(ODB_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/odb/include)  
find_library(  
	ODB_LIBRARIES  
	NAMES odb libodb
	PATHS ${CMAKE_CURRENT_LIST_DIR}/env/odb/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)

# ODB_MYSQL
set(ODB_MYSQL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/odb-mysql/lib)  
set(ODB_MYSQL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/odb-mysql/include)  
find_library(  
	ODB_MYSQL_LIBRARIES  
	NAMES odb-mysql libodb-mysql
	PATHS ${CMAKE_CURRENT_LIST_DIR}/env/odb-mysql/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)

# ODB_BOOST
set(ODB_BOOST_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/odb-boost/lib)  
set(ODB_BOOST_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/odb-boost/include)  
find_library(  
	ODB_BOOST_LIBRARIES  
	NAMES odb-boost libodb-boost
	PATHS ${CMAKE_CURRENT_LIST_DIR}/env/odb-boost/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH  
)

#MYSQL_CLIENT
set(MYSQL_CLIENT_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/lib)  
set(MYSQL_CLIENT_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/include)  
find_library(  
	MYSQL_CLIENT_LIBRARIES  
	NAMES mysqlclient
	PATHS ${CMAKE_CURRENT_LIST_DIR}/env/mysql-connector/lib
	PATH_SUFFIXES "lib"  
	NO_DEFAULT_PATH
)

include_directories(${SNMPDAO_INCLUDE_DIRS}
					${SNMPDAO_INCLUDE_DIRS}/Entity
					${SNMPLIB_INCLUDE_DIRS}
					${ODB_INCLUDE_DIRS}
					${ODB_MYSQL_INCLUDE_DIRS}
					${ODB_BOOST_INCLUDE_DIRS}
					${MYSQL_CLIENT_INCLUDE_DIRS})


link_directories(${SNMPDAO_LIBRARY_DIRS}
				 ${SNMPLIB_LIBRARY_DIRS}
				 ${ODB_LIBRARY_DIRS}
				 ${ODB_MYSQL_LIBRARY_DIRS}
				 ${ODB_BOOST_LIBRARY_DIRS}
				 ${MYSQL_CLIENT_LIBRARY_DIRS})


target_link_libraries(Nemsta
					  ${SNMPDAO_LIBRARIES}
					  ${SNMPLIB_LIBRARIES}
					  ${ODB_LIBRARIES}
					  ${ODB_MYSQL_LIBRARIES}
					  ${ODB_BOOST_LIBRARIES}
					  ${MYSQL_CLIENT_LIBRARIES}
					  Threads::Threads)