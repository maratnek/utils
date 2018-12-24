cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(LogStream)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_define_targets()

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(${PROJECT_NAME} main.cxx)

target_include_directories(LogStream
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/log-stream
)

target_link_libraries(${PROJECT_NAME} log_stream Qt5::Widgets)

add_subdirectory(log-stream)
add_subdirectory(utils)

 #set(BUILD_TESTING TRUE)
 #if(BUILD_TESTING)
   #add_subdirectory(utils/Testing/gtest)
 #endif()
