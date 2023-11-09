#!/bin/bash

export LD_LIBRARY_PATH=/opt/maxeler/maxeleros/lib:$LD_LIBRARY_PATH

declare -a array=("cpu" "cpu-buff" "dfe" "dfe-full")

for mode in "${array[@]}"
do
	for ((run=0; run < 10; run++)); 
	do
		for threads in 1 2 4 8;
			do
			echo -e "Mode: $mode \n Run: $run \n Threads: $threads"
			mpirun -np $threads build/$mode/cavity2d
		done
	done
done
