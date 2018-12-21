cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

project(LogStream)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(LogStream main.cxx)

target_include_directories(LogStream
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/log-stream
)

target_link_libraries(LogStream log_stream Qt5::Widgets)

add_subdirectory(log-stream)
add_subdirectory(utils)


 #set(BUILD_TESTING TRUE)
 #if(BUILD_TESTING)
   #add_subdirectory(utils/Testing/gtest)
 #endif()
