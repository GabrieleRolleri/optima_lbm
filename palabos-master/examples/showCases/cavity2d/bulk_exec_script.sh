#!/bin/bash

export LD_LIBRARY_PATH=/opt/maxeler/maxeleros/lib:$LD_LIBRARY_PATH

for ((i=0; i < 9; i++)); do
	echo "Run $i of 9"
	for ((j=1; j < 5; j++)); do
		echo "Number of threads: $j"
		sleep 60
		maxforceidle -a
		mpirun -np $j ./cavity2d
	done
	sleep 60
	maxforceidle -a
	mpirun -np 8 ./cavity2d
done
