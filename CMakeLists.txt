cmake_minimum_required(VERSION 3.10)

# Define the project
project(HMIProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define source files
set(SOURCES
    app/main.cpp
    include/hmi.h
    include/input_events_if.h
    include/input_events_impl.h
    include/input_actuators_events_if.h
    include/input_actuators_impl.h
)

# Create the executable
add_executable(HMIProject ${SOURCES})
