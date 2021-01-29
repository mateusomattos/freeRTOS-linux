#!/bin/bash

line_example=$( sed -n 108p main.c )
sed -i 's/'"$line_example"'/#define example '"$1"'/g' main.c  

make

printf "\n\n"
echo "Make done"
echo "Change to example $1"

sleep 2

./build/posix_demo