#!/bin/bash
# Finds all files and formats them in parallel using 8 threads.

# Check if clang-format is available
if ! command -v clang-format &> /dev/null; then
    echo "Error: clang-format is not installed or not in PATH"
    exit 1
fi

# Do formatting
find . -type f \
    \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \
       -o -name "*.cc" -o -name "*.cxx" -o -name "*.c" \) \
    -not -path "./build/*" -print0 \
    | xargs -0 -P 8 clang-format -i -style=file
echo "Done."