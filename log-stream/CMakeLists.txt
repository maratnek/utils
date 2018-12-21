find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(STREAM_HDRS
  qdebugstream.h
)

set(STREAM_SRCS
  qdebugstream.cxx
)

add_library(log_stream ${STREAM_HDRS} ${STREAM_SRCS})

target_include_directories(log_stream
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(log_stream utils Qt5::Widgets)

#add_subdirectory(utils)
