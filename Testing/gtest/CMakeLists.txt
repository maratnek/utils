add_executable(UtilsTest utils.cxx)
target_link_libraries(UtilsTest utils)


cmake_minimum_required (VERSION 3.1)

project (registerer)

##################################
# Download and install GoogleTest

include(ExternalProject)
ExternalProject_Add(gtest
  URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
  # Comment above line, and uncomment line below to use subversion.
  # SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
  # Uncomment line below to freeze a revision (here the one for 1.7.0)
  # SVN_REVISION -r700

  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  INSTALL_COMMAND ""
)
ExternalProject_Get_Property(gtest source_dir binary_dir)

################
# Define a test
add_executable(UtilsTest utils.cxx)
target_link_libraries(UtilsTest utils)

######################################
# Configure the test to use GoogleTest
#
# If used often, could be made a macro.

add_dependencies(UtilsTest gtest)
#include_directories(${source_dir}/include)
#target_link_libraries(registerer_test ${binary_dir}/libgtest.a)
#target_link_libraries(registerer_test ${binary_dir}/libgtest_main.a)

##################################
# Just make the test runnable with
#   $ make test

enable_testing()

add_test(NAME UtilsTest
  COMMAND ${CMAKE_BINARY_DIR}/utils
  ${GEOMEHANIKA_DATA_DIR}/utilsLines)

  #if (APPLE)
    #add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    #add_definitions(-D__GLIBCXX__)
  #endif (APPLE)
#
  ## This adds another subdirectory, which has 'project(gtest)'.
  #add_subdirectory(lib/gtest-1.6.0)
#
  #enable_testing()
#
  ## Include the gtest library. gtest_SOURCE_DIR is available due to
  ## 'project(gtest)' above.
  #include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#
  ###############
  ## Unit Tests
  ###############
  #add_executable(runUnitTests test_project1.cpp)
#
  ## Standard linking to gtest stuff.
  #target_link_libraries(runUnitTests gtest gtest_main)
#
  ## Extra linking for the project.
  #target_link_libraries(runUnitTests project1_lib)
#
  ## This is so you can do 'make test' to see all your tests run, instead of
  ## manually running the executable runUnitTests to see those specific tests.
  #add_test(NAME that-test-I-made COMMAND runUnitTests)
#
  ## You can also omit NAME and COMMAND. The second argument could be some other
  ## test executable.
  #add_test(that-other-test-I-made runUnitTests)

