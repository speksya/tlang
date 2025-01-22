#!/bin/bash

if [ ! -d "build" ]; then
    mkdir -p "build"
fi

cd build
cmake ..
make

if [ -f "tlc" ]; then
    mv tlc ../
else
    echo "Build failed"
    exit 1 
fi
