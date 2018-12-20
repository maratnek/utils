cmake_minimum_required(VERSION 3.3)
set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED)

set(UTILS_HDRS
  #log.h
)

set(UTILS_SRCS
  #log.cxx
  first.cxx
)

add_library(utils ${UTILS_HDRS} ${UTILS_SRCS})

#if(NOT UNIX)
  #add_library(utils STATIC ${Module_SRCS})
#else()
  #add_library(utils ${Module_SRCS})
#endif()

target_include_directories(utils
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
  ${Boost_INCLUDE_DIR})

target_link_libraries(utils)

#if(UNIX)
  #target_link_libraries(utils boost_system)
#endif()

set(BUILD_TESTING TRUE)
if(BUILD_TESTING)
  add_subdirectory(Testing/gtest)
endif()
