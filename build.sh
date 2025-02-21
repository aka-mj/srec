#!/bin/sh
#
# Must provide the path to the cross-compiler in the environment variable CROSS_COMPILER.
# For example:
# export CROSS_COMPILER=$PWD/armv7-eabihf--musl--stable-2023.11-1
#
export CROSS_COMPILER=$PWD/armv7-eabihf--musl--stable-2023.11-1

# build for host (x86_64)
mkdir -p build_host
cd build_host
cmake ..
make
cd ..

# build for target (arm)
mkdir -p build_target
cd build_target
cmake -DCMAKE_TOOLCHAIN_FILE=../toolchainfile.cmake -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_EXE_LINKER_FLAGS="-static" ..
make
cd ..
