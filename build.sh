#!/bin/bash
NAME=sdl-helper

SDL_PATH=/usr/include/SDL2
SRC_PATH=src
INC_PATH=include
OBJ_PATH=objs
LIB_PATH=lib

ext=".c"

FILES=$(find $SRC_PATH/ -type f -name '*'$ext)

if [ -d $OBJ_PATH ]
then
    rm -r $OBJ_PATH   
fi
mkdir $OBJ_PATH

for file in $FILES
do
    echo "Building $file"
    OBJ=$OBJ_PATH/$(basename ${file} $ext).o
    clang -c -Wall -I$SDL_PATH -I$INC_PATH $file -o $OBJ
done

if [ -d $LIB_PATH ]
then
    rm -r $LIB_PATH
fi
mkdir $LIB_PATH


ar -rc $LIB_PATH/$NAME.a objs/*.o
ranlib $LIB_PATH/$NAME.a

echo "Libraries:"
ar -t $LIB_PATH/$NAME.a