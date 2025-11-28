#!/bin/bash

mkdir -p build
cd build

cmake ..
cmake --build .

if [ $? -eq 0 ]; then
    echo "=== URUCHAMIANIE TESTOW ==="
    ./runTests
else
    echo "BLAD KOMPILACJI"
fi