#!/bin/bash

c++ --std=c++17 -Wall -Wextra -Werror -O2 -o raytrace raytrace.cpp
./raytrace > test.ppm
open .
sleep 1
rm raytrace ../.DS_STORE 2> .tmp
rm .tmp
