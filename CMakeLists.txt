# CMake needs this line.
cmake_minimum_required(VERSION 3.0)

# Define project name.
project(Neural_Network_CPP)

# Set the C++ standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type to RelWithDebInfo if not specified.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

# Set optimization flags for Intel Advisor profiling.
# -O2                  : safe optimization
# -g                   : include debug symbols
# -march=native        : use best SIMD supported by current CPU
# -fno-inline          : keep functions and loops visible to Advisor
# -pg                  : enable gprof profiling
# -fno-tree-vectorize  : disable vectorization
# -fopenmp             : enable OpenMP support (multi-threading)

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O1 -g -march=native -fopenmp")

# Set linker flags to enable gprof profiling and OpenMP output.
# set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "-pg -fopenmp")
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "-fopenmp")

# Set the source files.
set(NAME_SRC
    src/main.cpp
    src/dataset.cpp
    src/Net.cpp
    src/Neuron.cpp
)

# Set the header files (optional, for clarity/documentation purposes).
set(NAME_HEADERS
    include/Net.h
    include/Neuron.h
    include/Connection.h
    include/dataset.h
)

# Include directories.
include_directories(include)

# Build the executable file.
add_executable(Neural_Network_CPP ${NAME_SRC})

# Show warnings.
add_compile_options(-Wall -Wextra -pedantic)

# Link your application with additional libraries (if needed).
# target_link_libraries(Neural_Network_CPP ${library_name})
