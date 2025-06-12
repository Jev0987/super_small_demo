cmake_minimum_required(VERSION 3.31)
project(super_small_demo)

set(CMAKE_CXX_STANDARD 14)

add_library(demo small_demo_1.cpp
        small_demo_2.cpp
        small_demo_3.cpp
        small_demo_4.cpp
        small_demo_5.cpp
        small_demo_6.cpp
)

add_executable(${PROJECT_NAME}
        main.cpp)
target_link_libraries(${PROJECT_NAME} demo)
