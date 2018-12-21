cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

set(UTILS_HDRS
  #log.h
  first.h
)

set(UTILS_SRCS
  #log.cxx
  first.cxx
)

add_library(utils ${UTILS_HDRS} ${UTILS_SRCS})

target_include_directories(utils
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIR})

#target_link_libraries(utils Boost::log Boost::log_setup  ${CMAKE_THREAD_LIBS_INIT})

set(BUILD_TESTING TRUE)
if(BUILD_TESTING)
  add_subdirectory(Testing/gtest)
endif()
