cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS_RELEASE "/MT")
#set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
set(Boost_DEBUG 1)

set(CompilerFlags
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  #string(REPLACE "/MDd" "/MD" ${CompilerFlag} "${${CompilerFlag}}")
  #string(REPLACE "/MTd" "/MD" ${CompilerFlag} "${${CompilerFlag}}")
#  message("${${CompilerFlag}}")
endforeach()

project(LogStream)

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
