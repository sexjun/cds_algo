cmake_minimum_required(VERSION 3.0.0)
project(algo VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 11)
add_subdirectory(bianry_tree)
add_subdirectory(third_party/googletest)

set(WITH_GTEST OFF)
add_subdirectory(third_party/glog)

include_directories(. bianry_tree)


# find_package (glog 0.5.0 REQUIRED)

aux_source_directory(./code SRC)
add_executable(${PROJECT_NAME} main.cpp ${SRC})
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    sub::lib2
    gtest_main
    glog::glog
    )



