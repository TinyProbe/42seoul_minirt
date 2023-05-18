#!/bin/bash

c++ --std=c++17 -Wall -Wextra -Werror -O2 -o raytrace raytrace.cpp\
&& ./raytrace > test.ppm\
&& open -a Preview test.ppm\
&& (sleep 1 ; rm raytrace test.ppm)
