#!/bin/bash
cd ..
mkdir build 
cd build
cmake ..
make
cd ..
rm -r build
