cmake_minimum_required(VERSION 3.10.0)
project(ascii_vision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find opencv package installed on system
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

# Set variable for sources
set(SOURCES src/main.cpp)

# Compilation
add_executable(ascii_vision ${SOURCES})

# Tells CMake to use C++ linking for the specific target
set_target_properties(ascii_vision PROPERTIES LINKER_LANGUAGE CXX)

# Link external libraries
# Link OPENCV
target_link_libraries(ascii_vision PRIVATE ${OpenCV_LIBS})

