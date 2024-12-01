#!/bin/bash

# Base directory containing root folders
BASE_DIR="./src"

# Traverse all main.cpp files in all subdirectories
find "$BASE_DIR" -type f -name "main.cpp" | while read -r main_file; do
    dir=$(dirname "$main_file")  # Get the directory containing main.cpp
    out_file="$dir/out.txt"
    submit_file="$dir/submit.txt"

    echo "Testing $main_file"

    # Temporarily switch to the directory of the current file
    pushd "$dir" > /dev/null

    # Compile main.cpp
    g++ -std=c++11 -o out main.cpp
    if [[ $? -ne 0 ]]; then
        echo "❌ Compilation failed for $main_file"
        popd > /dev/null
        continue
    fi

    # Execute the compiled program
    ./out > /dev/null
    if [[ $? -ne 0 ]]; then
        echo "❌ Runtime error for $main_file"
        popd > /dev/null
        continue
    fi

    # Verify that the necessary files exist
    if [[ ! -f "out.txt" ]]; then
        echo "Error: out.txt was not generated."
        popd > /dev/null
        continue
    fi

    if [[ ! -f "submit.txt" ]]; then
        echo "Error: submit.txt does not exist."
        popd > /dev/null
        continue
    fi

    # Retrieve the last line from out.txt and submit.txt
    out_last_line=$(tail -n 1 "out.txt")
    submit_last_line=$(tail -n 1 "submit.txt")

    # Compare the last lines
    if [[ "$out_last_line" == "$submit_last_line" ]]; then
        echo "✅ Test passed"
    else
        echo "❌ Test failed"
        echo "  Expected: $submit_last_line"
        echo "  Got: $out_last_line"
    fi

    # Return to the previous directory
    popd > /dev/null

    echo $'' # new line
done