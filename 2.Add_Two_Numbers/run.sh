#!/bin/bash

output=$(basename "$(pwd)")
echo "$output"

# Check if CMakeLists.txt exists in the current directory
if [ -f "CMakeLists.txt" ]; then
    echo "Found CMakeLists.txt. Running CMake..."
    # Create a build directory if it doesn't exist
    mkdir -p build
    # Change to the build directory
    cd build
    # Run CMake
    cmake ..
    # Run Make
    make
    # Check if the make command was successful
    if [ $? -eq 0 ]; then
        # If successful, execute the output binary if it exists
        if [ -f "${output}" ]; then
            echo "Running the ${output} binary..."
            # Binary name here
            ./"${output}"
        else
            echo "Error: The output binary '${output}' not found."
        fi
    else
        echo "Error: Build failed."
    fi
else
    echo "Error: CMakeLists.txt not found in the current directory."
fi
