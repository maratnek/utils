#make_minimum_required(VERSION 3.1)

project(utils)

set(CompilerFlags
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  message("${${CompilerFlag}}")
endforeach()

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake)
include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup(TARGETS)

set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_NO_SYSTEM_PATHS ON)
#
# message(CONAN)
# message(${CONAN_LIBS})
# message(${CONAN_INCLUDE_DIRS})
# message(${CONAN_LIB_DIRS})
# message(${CONAN_INCLUDE_DIRS_BOOST})
# message(${CONAN_LIB_DIRS_BOOST})
# message(${CONAN_LIB_BOOST})
#
set(BOOST_ROOT ${CONAN_BUILD_DIRS_BOOST})
set(BOOST_LIBRARYDIR ${CONAN_LIB_DIRS_BOOST})

find_package(Boost COMPONENTS
   system
   date_time
   filesystem
   thread
   log
   log_setup
   regex
   REQUIRED
)

find_package(Threads)

#include_directories(${Boost_INCLUDE_DIRS})
#link_directories(${Boost_LIBRARY_DIRS})

 message(STATUS "BOOST_ROOT = ${BOOST_ROOT}")
 message(STATUS "Boost_VERSION = ${Boost_VERSION}")
 message(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")
 message(STATUS "Boost_MAJOR_VERSION = ${Boost_MAJOR_VERSION}")
 message(STATUS "Boost_MINOR_VERSION = ${Boost_MINOR_VERSION}")
 message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
 message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
 message(STATUS "Boost_LIBRARY_DIRS = ${Boost_LIBRARY_DIRS}")
 message(STATUS "Boost_LIBRARYDIR = ${BOOST_LIBRARYDIR}")

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
  ${Boost_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} CONAN_PKG::boost)
#target_link_libraries(utils Boost::log Boost::log_setup)
#target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
#target_link_libraries(${PROJECT_NAME} CONAN_PKG::boost CONAN_PKG::boost_log CONAN_PKG::boost_log_setup)

# set(BUILD_TESTING TRUE)
# if(BUILD_TESTING)
#   add_subdirectory(utils/Testing/gtest)
# endif()
