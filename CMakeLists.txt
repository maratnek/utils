cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

project(utils_lib)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#add_definitions(-DBOOST_LOG_DYN_LINK)
find_package(Boost COMPONENTS log log_setup thread system atomic filesystem exception REQUIRED)
message(status "** Boost Include: ${Boost_INCLUDE_DIR}")
message(status "** Boost Libraries: ${Boost_LIBRARY_DIRS}")
message(status "** Boost Libraries: ${Boost_LIBRARIES}")
message(status "** Boost LOG Libraries: ${Boost_LOG_LIBRARIES}")
find_package(Threads)

set(UTILS_HDRS
  log.h
  first.h
)

set(UTILS_SRCS
  log.cxx
  first.cxx
)

add_library(utils ${UTILS_HDRS} ${UTILS_SRCS})

target_include_directories(utils
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIR})

target_link_libraries(utils Boost::log Boost::log_setup)

set(BUILD_TESTING TRUE)
if(BUILD_TESTING)
  add_subdirectory(Testing/gtest)
endif()
