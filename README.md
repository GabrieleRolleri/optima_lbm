# optima2
Performance analysis of LBM implementation on FPGA cards.
Thi is an implmentation of PALABOS lattice D2Q9 on FPGA card within the OPTIMA JU co-founded project Grant Agreement n. 955739
The implementation was done on JUMAX platform available at JULICH with Maxeller compiler (now GROQ) 

Cavity2D was the chosen example for performance analysis, the respective directory can be found in palabos-master/examples/showCases/cavity2d.
On the other hand most changes had to be done on the Palabos classes responsible for the actual LBM simulation, these are found in palabos-master/src/atomicBlock/blockLattice2D.hh and its respective header file.

## Running the simulation
### CPU-Prof & CPU-BUff
The two CPU branches can be built and run following Palabos instructions (i.e. with CMake). 
The building process for DFE assisted execution is a little more involved.
### DFE & DFE-Full
Compile the .maxj kernel and manager in MaxIDE or via CLI. Move the resulting slic_pCollide.o object file in the cavity2d build folder.

Run CMake inside the build folder to prepare most binaries, even though the final compilation process will not be performed by make.
```
cmake ..
```
Afterwards, execute make inside the build folder, the command will fail and throw errors as the necessary maxj environment parameters have not been set inside the makefile.
```
make -j16
```
Ad hoc commands must now be used to include the maxj parameters, firstly compile with the following command (replace rolleri1 with your username)
```
/opt/Software/haswell/Stages/2021a/software/GCCcore/11.1.0/bin/c++ -DPLB_MPI_PARALLEL -DPLB_USE_POSIX -I/mnt/beegfs/Software/haswell/Stages/2021a/software/OpenMPI/4.1.2-GCC-11.1.0/include -I/opt/Software/haswell/Stages/2021a/software/OpenMPI/4.1.2-GCC-11.1.0/include -I/home/jusers/rolleri1/jumax/workspace/optima2/palabos-master/examples/showCases/cavity2d/../../../src -I/home/jusers/rolleri1/jumax/workspace/optima2/palabos-master/examples/showCases/cavity2d/../../../externalLibraries -I/home/jusers/rolleri1/jumax/workspace/optima2/palabos-master/examples/showCases/cavity2d/../../../externalLibraries/Eigen3 -I../../hardware/ -I '/opt/Software/maxeler/maxcompiler-2021.1/include/slic' -std=c++11 -Wall -Wextra -Wnon-virtual-dtor  -O3 -DNDEBUG -MD -MT CMakeFiles/cavity2d.dir/cavity2d.cpp.o -MF CMakeFiles/cavity2d.dir/cavity2d.cpp.o.d -o CMakeFiles/cavity2d.dir/cavity2d.cpp.o -c /home/jusers/rolleri1/jumax/workspace/optima2/palabos-master/examples/showCases/cavity2d/cavity2d.cpp
```
And subsequently link:
```
/opt/Software/haswell/Stages/2021a/software/GCCcore/11.1.0/bin/c++ -std=c++11 -Wall -Wextra -Wnon-virtual-dtor  -O3 -DNDEBUG -rdynamic CMakeFiles/cavity2d.dir/cavity2d.cpp.o -o ./cavity2d slic_pCollide.o libpalabos.a -L '/opt/Software/maxeler/maxcompiler-2021.1/lib' -lslic -L '/opt/Software/maxeler/maxcompiler-2021.1/lib/maxeleros-sim/lib' -lmaxeleros -lpthread -lm -lrt -lcurl -L/opt/Software/haswell/Stages/2021a/software/OpenMPI/4.1.2-GCC-11.1.0/lib -L/opt/Software/haswell/Stages/2021a/software/hwloc/2.4.1-GCCcore-11.1.0/lib -L/opt/Software/haswell/Stages/2021a/software/UCX/1.11.2-GCCcore-11.1.0/lib64 -L/usr/lib64 -Wl,-rpath -Wl,/opt/Software/haswell/Stages/2021a/software/OpenMPI/4.1.2-GCC-11.1.0/lib -Wl,-rpath -Wl,/opt/Software/haswell/Stages/2021a/software/hwloc/2.4.1-GCCcore-11.1.0/lib -Wl,-rpath -Wl,/opt/Software/haswell/Stages/2021a/software/UCX/1.11.2-GCCcore-11.1.0/lib64 -Wl,-rpath -Wl,/usr/lib64 -Wl,--enable-new-dtags -lmpi
```
Export a shell variable necessary for execution:
```
export LD_LIBRARY_PATH=$MAXELEROSDIR/lib:$LD_LIBRARY_PATH
```
We can now proceed to execution with X threads:
```
mpirun -np X ./cavity2d
```
To quickly perform benchmarks, the supplied bulk_exec_script.sh can be used.
