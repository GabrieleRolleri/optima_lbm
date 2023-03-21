#!/bin/bash
for threads in {1..10}
do
	cd ./palabos-master/examples/showCases/cavity2d
	mpirun -n $threads ./cavity2d
	cd 
	cd workspace/optima2
	gprof ./palabos-master/examples/showCases/cavity2d/cavity2d ./palabos-master/examples/showCases/cavity2d/gmon.out > ./results/cpu/results_mpi_${threads}_thr.txt
done

