cmake_minimum_required(VERSION 4.3.3)
project (yamldemo LANGUAGES CXX)

add_subdirectory(yaml)

add_executable(demo main.cpp)
target_link_libraries(demo yaml::markup)
