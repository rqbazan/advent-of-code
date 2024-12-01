#!/bin/bash

BASE_DIR="./src"

find "$BASE_DIR" -type f -name "main.cpp" | while read -r main_file; do
    dir=$(dirname "$main_file")
    out_file="$dir/out.txt"
    submit_file="$dir/submit.txt"

    echo "Testing $main_file"

    g++ -std=c++11 -o "$dir/out" "$main_file" && "$dir/out"

    if [[ ! -f "$out_file" ]]; then
        echo "Error: $out_file not found."
        continue
    fi

    if [[ ! -f "$submit_file" ]]; then
        echo "Error: $submit_file not found."
        continue
    fi

    out_last_line=$(tail -n 1 "$out_file")
    submit_last_line=$(tail -n 1 "$submit_file")

    if [[ "$out_last_line" == "$submit_last_line" ]]; then
        echo "✅ Test passed for $main_file"
    else
        echo "❌ Test failed for $main_file"
        echo "  Expected: $submit_last_line"
        echo "  Got: $out_last_line"
    fi

    echo "---------------------------------"
done