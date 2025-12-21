#!/bin/bash
# Format the current file with clang-format
if [ -z "$1" ]; then
  echo "Usage: format-file.sh <file>"
  exit 1
fi

clang-format -i -style=file "$1"

