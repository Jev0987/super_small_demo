cmake_minimum_required(VERSION 3.31)
project(super_small_demo)

set(CMAKE_CXX_STANDARD 14)

add_library(demo
        demo_async_mission.cpp
        demo_base_derived.cpp
        demo_future_promise.cpp
        demo_member_class.cpp
        demo_print_enum_hex.cpp
        demo_check_free_malloc.cpp
        demo_friend_method.cpp
        demo_review_ptr_use.cpp
        demo_use_enum.cpp
)

add_executable(${PROJECT_NAME}
        main.cpp
)
target_link_libraries(${PROJECT_NAME} demo)

