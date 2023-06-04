#!/bin/bash

for ((i=0; i < 9; i++)); do
	echo "Run $i of 9"
	for ((j=1; j < 5; j++)); do
		echo "Number of threads: $j"
		maxforceidle -a
		mpirun -np $(j) ./cavity2d
	done
	maxforceidle -a
	mpirun -np 8 ./cavity2d
done
