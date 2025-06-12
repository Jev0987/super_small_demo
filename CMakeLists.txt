cmake_minimum_required(VERSION 3.31)
project(super_small_demo)

set(CMAKE_CXX_STANDARD 14)

add_library(demo demo_check_free_malloc.cpp
        demo_future_promise.cpp
        demo_promise_ref.cpp
        demo_async_mission.cpp
        demo_review_ptr_use.cpp
        demo_print_enum_hex.cpp
)

add_executable(${PROJECT_NAME}
        main.cpp)
target_link_libraries(${PROJECT_NAME} demo)
