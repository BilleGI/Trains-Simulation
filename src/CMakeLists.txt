cmake_minimum_required(VERSION 3.5)

add_executable(train main.cpp ${MY_INCLUDE_DIR}/train.h train.cpp)

target_include_directories(train PUBLIC ${MY_INCLUDE_DIR})
