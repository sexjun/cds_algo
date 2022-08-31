cmake_minimum_required(VERSION 3.0.0)
project(algo VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)

include_directories(. a_45)

aux_source_directory(./code SRC)
add_subdirectory(a_45)
add_executable(${PROJECT_NAME} main.cpp ${SRC})
target_link_libraries(${PROJECT_NAME}   sub::lib2)



