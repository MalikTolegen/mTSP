cmake_minimum_required(VERSION 3.10)

# Set the project name
project(mTSP)

# Add the include directory to the project
include_directories(src)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable
add_executable(
    mtsp
    src/initial_random_chromosome_generation.cpp
    src/random_coord_generation.cpp
)

# Ensure the correct include directories are used
target_include_directories(mtsp PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Link libraries if needed
# target_link_libraries(mtsp <library_name>)
