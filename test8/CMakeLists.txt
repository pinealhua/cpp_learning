cmake_minimum_required(VERSION 3.16)

project(robot_demo LANGUAGES CXX)

add_executable(robot
    main.cpp
    robot.cpp
)

target_compile_features(robot PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(robot PRIVATE /W4)
else()
    target_compile_options(robot PRIVATE -Wall -Wextra)
endif()
