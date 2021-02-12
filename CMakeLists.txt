# Cmake needs this line.
cmake_minimum_required(VERSION 3.0)

# Define project name.
PROJECT (Neural__Network_CPP)


# Set the Source file that meant to be executed.
set( NAME_SRC
    src/main.cpp
)

# Set Headers.
set( NAME_HEADERS
     include/Net.h
     include/Neuron.h
     include/Net.cpp
     include/Neuron.cpp
     include/Connection.h
)

# Build the executable file.
add_executable( Neural__Network_CPP ${NAME_SRC} ${NAME_HEADERS} )

# Show Warnings.
add_compile_options(-Wall)


# Link your application with OpenCV libraries
#target_link_libraries( ${PROJECT_NAME} ${library_name} )
