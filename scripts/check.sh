#!/bin/bash

# Base directory containing root folders
BASE_DIR="./src"
EXIT_CODE=0  # Track the exit status

# If a specific path is provided, set it as the target directory
if [[ -n $1 ]]; then
    TARGET_DIR="$BASE_DIR/$1"
    if [[ ! -d "$TARGET_DIR" ]]; then
        echo "Error: Directory $TARGET_DIR does not exist."
        exit 1
    fi
    # Check only the main.cpp in the specified directory
    FILES=$(find "$TARGET_DIR" -type f -name "main.cpp")
else
    # Check all main.cpp files under the base directory
    FILES=$(find "$BASE_DIR" -type f -name "main.cpp")
fi

# Traverse all the main.cpp files
for main_file in $FILES; do
    dir=$(dirname "$main_file") 
    out_file="$dir/out.txt"
    submit_file="$dir/submit.txt"

    echo $''
    echo "Checking $main_file"

    # Temporarily switch to the directory of the current file
    pushd "$dir" > /dev/null

    # Compile main.cpp
    g++ -std=c++11 -o out main.cpp
    if [[ $? -ne 0 ]]; then
        echo "❌ Compilation failed for $main_file"
        EXIT_CODE=1
        popd > /dev/null
        continue
    fi

    # Execute the compiled program
    ./out > /dev/null
    if [[ $? -ne 0 ]]; then
        echo "❌ Runtime error for $main_file"
        EXIT_CODE=1
        popd > /dev/null
        continue
    fi

    # Verify that the necessary files exist
    if [[ ! -f "out.txt" ]]; then
        echo "Error: out.txt was not generated."
        EXIT_CODE=1
        popd > /dev/null
        continue
    fi

    if [[ ! -f "submit.txt" ]]; then
        echo "Error: submit.txt does not exist."
        EXIT_CODE=1
        popd > /dev/null
        continue
    fi

    # Retrieve the last line from out.txt and submit.txt
    out_last_line=$(tail -n 1 "out.txt")
    submit_last_line=$(tail -n 1 "submit.txt")

    # Compare the last lines
    if [[ "$out_last_line" == "$submit_last_line" ]]; then
        echo "✅ Check passed"
    else
        echo "❌ Check failed"
        echo "  Expected: $submit_last_line"
        echo "  Got: $out_last_line"
        EXIT_CODE=1
    fi

    # Return to the previous directory
    popd > /dev/null
done

# Exit with the appropriate code
exit $EXIT_CODE