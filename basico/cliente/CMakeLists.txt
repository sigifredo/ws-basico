project( cliente )
cmake_minimum_required(VERSION 2.8)

include ("config/gsoap_config.cmake")

include_directories(${CMAKE_BINARY_DIR} include)

add_executable(cliente src/main.cpp)

target_link_libraries(cliente ${GSOAP_LIBRARIES})
