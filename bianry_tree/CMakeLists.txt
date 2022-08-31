cmake_minimum_required(VERSION 3.0.0)

project(a_45)
set (CMAKE_CXX_STANDARD 11)
include_directories(.)
aux_source_directory(. SRC_45)

message("=================")
message(${SRC_45})
message("=================")

add_library(${PROJECT_NAME} ${SRC_45})
add_library(sub::lib2 ALIAS ${PROJECT_NAME})
# add_executable(${PROJECT_NAME} ${SRC_45})

