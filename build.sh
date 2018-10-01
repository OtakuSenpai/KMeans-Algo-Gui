#!/bin/sh

echo "Making directory ..."
mkdir build && cd build/

echo "Compiling now..."
cmake -DFLTK_DIR=./../libs/fltk-1.3.4-2/CMake/FLTKConfig.cmake.in ..
make

echo "Done."