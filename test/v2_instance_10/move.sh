#!/bin/bash

# Compilementary script for moving the results 
# of the program into an the output folder

rm -rf output
mkdir output
mv bin/map.pgm output/
mv bin/map.dat output/
mv bin/stdout output/ 