

cmake_minimum_required(VERSION 3.10)

# Set the project name
project(mTSP)

# Add the include directory to the project
include_directories(src)

# Add the executable
add_executable(
    mtsp 
    src/initial_random_chromosome_generation.cpp
    src/random_coord_generation.cpp
)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories if needed
# include_directories(${PROJECT_SOURCE_DIR}/include)

# Link libraries if needed
# target_link_libraries(initial_random_chromosome_generation <library_name>)