cmake_minimum_required(VERSION 3.0.0)
project(algo VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 11)

include_directories(.)

aux_source_directory(./code SRC)
add_executable(algo main.cpp ${SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
