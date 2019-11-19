#!/bin/bash

# Compilementary script for moving the results 
# of the program into an the output folder

rm -rf output
mkdir output
mv map.pgm output/
mv map.dat output/