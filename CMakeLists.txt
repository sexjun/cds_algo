cmake_minimum_required(VERSION 3.0.0)
project(algo VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)

include_directories(. bianry_tree)

aux_source_directory(./code SRC)
add_subdirectory(bianry_tree)
add_executable(${PROJECT_NAME} main.cpp ${SRC})
target_link_libraries(${PROJECT_NAME}   sub::lib2)



