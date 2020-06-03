cmake_minimum_required(VERSION 3.10)
find_package(Eigen3 REQUIRED)

include_directories(
    include
    ${EIGEN3_INCLUDE_DIRS})

    add_executable(practice practice.cpp)
target_link_libraries(practice ${EIGEN3_LIBRARIES})

add_executable(block_operations block_operations.cpp)
target_link_libraries(block_operations ${EIGEN3_LIBRARIES})