cmake_minimum_required(VERSION 3.5)

project("Train Simulation" VERSION 1.0)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

install(TARGETS train
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
