# CMake needs this line.
cmake_minimum_required(VERSION 3.0)

# Define project name.
project(Neural_Network_CPP)

# Set the C++ standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
