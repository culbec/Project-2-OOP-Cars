cmake_minimum_required(VERSION 3.25)
project(Project_2_OOP_Cars)

set(CMAKE_CXX_STANDARD 14)

include_directories(Headers)

add_executable(Project_2_OOP_Cars
        Headers/Car.h
        Headers/Repository.h
        Headers/Service.h
        Headers/tests.h
        Headers/UI.h
        Headers/Validator.h
        Sources/Car.cpp
        Sources/Repository.cpp
        Sources/Service.cpp
        Sources/tests.cpp
        Sources/UI.cpp
        Sources/Validator.cpp
        main.cpp)