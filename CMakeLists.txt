cmake_minimum_required(VERSION 2.8)

#include(CPackConfig.txt)

project(gcrypt++)

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
message(FATAL_ERROR "CMake generation is not allowed within the source directory!
Remove the CMakeCache.txt file and try again from another folder, e.g.:

   rm CMakeCache.txt
   mkdir build
   cd build
   cmake ..
")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${gcrypt++_SOURCE_DIR}/cmake)

#set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_BUILD_TYPE "Debug")

if (DEBUG_MODE)
set(CMAKE_BUILD_TYPE "Debug")
        if(NOT WIN32)
                add_definitions(-g)
        endif()
else()
        if(NOT WIN32)
                add_definitions(-O3)
        endif()
endif()
if (NOT WIN32)
	add_definitions(-fPIC)
endif()

include(CTest)

#include(CPack)

include(CheckIncludeFiles)
include(CheckFunctionExists)
include(CheckLibraryExists)


include(CMakeRequiredLibraries.txt)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
else()
	set(CMAKE_CXX_FLAGS "-std=c++11")
endif()


set(GCRYPT++LIB_INCLUDE_DIRS "${gcrypt++_SOURCE_DIR}/src/lib/include/" "${gcrypt++_BINARY_DIR}/src/lib/include")

set(GCRYPT++LIB_LIBRARY "${gcrypt++_BINARY_DIR}/src/lib/gcrypt++.so")
if(WIN32)
	set(GCRYPT++LIB_LIBRARY "${gcrypt++_BINARY_DIR}/src/lib/${CMAKE_BUILD_TYPE}/gcrypt++.lib")
endif(WIN32)
if(APPLE)
	set(GCRYPT++LIB_LIBRARY "${gcrypt++_BINARY_DIR}/src/lib/gcrypt++.dylib")
endif(APPLE)

set(GCRYPT++_LINK_LIBRARIES
${Boost_LIBRARIES}
${GCRYPT_LIBRARY}
)
message("Gcrypt++ link libraries:${GCRYPT++_LINK_LIBRARIES}")

add_subdirectory(src)
