cmake_minimum_required(VERSION 3.13)

project(utils)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
#set(Boost_NO_SYSTEM_PATHS ON)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_define_targets(TARGETS)
message(CONAN)
message(${CONAN_LIBS})
message(${CONAN_INCLUDE_DIRS})
message(${CONAN_LIB_DIRS})
message(${CONAN_INCLUDE_DIRS_BOOST})
message(${CONAN_LIB_DIRS_BOOST})

message(${CONAN_INCLUDE_DIRS_BOOST})
message(${CONAN_LIB_DIRS_BOOST})

set(BOOST_ROOT ${CONAN_INCLUDE_DIRS_BOOST} ${CONAN_LIB_DIRS_BOOST})
set(Boost_USE_STATIC_LIBS   OFF)
set(Boost_USE_MULTITHREADED ON)

#find_package(Boost COMPONENTS REQUIRED
#    system
#    date_time
#    filesystem
#    thread
#    regex
#)

find_package(Boost COMPONENTS log log_setup thread REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
message(STATUS "BOOST_ROOT = ${BOOST_ROOT}")
message(STATUS "Boost_VERSION = ${Boost_VERSION}")
message(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")
message(STATUS "Boost_MAJOR_VERSION = ${Boost_MAJOR_VERSION}")
message(STATUS "Boost_MINOR_VERSION = ${Boost_MINOR_VERSION}")
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARY_DIRS = ${Boost_LIBRARY_DIRS}")

find_package(Threads)

set(UTILS_HDRS
  log.h
  first.h
)

set(UTILS_SRCS
  log.cxx
  first.cxx
)

add_library(${PROJECT_NAME} ${UTILS_HDRS} ${UTILS_SRCS})

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
#  ${Boost_INCLUDE_DIR})

#target_link_libraries(utils Boost::log Boost::log_setup)
#target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
#target_link_libraries(${PROJECT_NAME} CONAN_PKG::boost CONAN_PKG::boost_log CONAN_PKG::boost_log_setup)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::boost)

# set(BUILD_TESTING TRUE)
# if(BUILD_TESTING)
#   add_subdirectory(utils/Testing/gtest)
# endif()
