#!/bin/bash

for file in ../*.3DS
do
	filename=$(basename "$file")
	extension="${filename##*.}"
	filename="${filename%.*}"
	meshlabserver -i "$file" -o $filename.off
done
