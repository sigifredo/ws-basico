project( cliente )
cmake_minimum_required(VERSION 2.8)

include ("config/gsoap_config.cmake")
# set(HDRS
# include/Cliente.hpp
# )
# 
# set(SRCS
# src/Cliente.cpp
# )
# 
# add_library(conn SHARED
# ${HDRS}
# ${SRCS}
# )

add_executable(cliente src/main.cpp)

target_link_libraries(cliente ${GSOAP_LIBRARIES})

# target_link_libraries(cliente conn)
