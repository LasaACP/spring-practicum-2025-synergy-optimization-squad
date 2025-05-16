cmake_minimum_required(VERSION 3.28)

project(SynergyScheduler)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SynergyScheduler
        src/main.cpp
        src/json/json.h src/json/json-forwards.h src/jsoncpp.cpp
        src/schedule.cpp src/schedule.h
        src/cost.cpp src/cost.h
        src/mutation.cpp src/mutation.h
        src/genetic.cpp src/genetic.h
        src/fitness.cpp src/fitness.h)

add_executable(SyntheticData src/jsongen.cpp)
