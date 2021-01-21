#!/bin/bash

clang -c -Wall -I/usr/include/SDL2 charset/charset.c -o objs/charset.o
clang -c -Wall -I/usr/include/SDL2 input/input.c -o objs/input.o
clang -c -Wall -I/usr/include/SDL2 utils/sdl.c -o objs/sdl.o

ar -rc lib/sdl_helper.a objs/*.o
ranlib lib/sdl_helper.a
ar -t lib/sdl_helper.a