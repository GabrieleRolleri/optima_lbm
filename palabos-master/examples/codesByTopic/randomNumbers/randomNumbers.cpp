/* This file is part of the Palabos library.
 *
 * The Palabos softare is developed since 2011 by FlowKit-Numeca Group Sarl
 * (Switzerland) and the University of Geneva (Switzerland), which jointly
 * own the IP rights for most of the code base. Since October 2019, the
 * Palabos project is maintained by the University of Geneva and accepts
 * source code contributions from the community.
 *
 * Contact:
 * Jonas Latt
 * Computer Science Department
 * University of Geneva
 * 7 Route de Drize
 * 1227 Carouge, Switzerland
 * jonas.latt@unige.ch
 *
 * The most recent release of Palabos can be downloaded at
 * <https://palabos.unige.ch/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/** \file
 *
 * This code demonstrates the use of random numbers.
 *
 **/

#include "palabos3D.h"
#include "palabos3D.hh"

using namespace plb;

typedef double T;

void writeVTK(MultiScalarField3D<T> &field, std::string const &name)
{
    VtkImageOutput3D<T> vtkOut(name, 1.0);
    vtkOut.writeData<float>(field, name, 1.0);
}

int main(int argc, char *argv[])
{
    plbInit(&argc, &argv);
    global::directories().setOutputDir("./tmp/");

    plint nx = 100;
    plint ny = 100;
    plint nz = 100;
    uint32_t seed = 1;

    MultiScalarField3D<T> originalField(nx, ny, nz);

    pcout << "Scalar Field" << std::endl;
    plint blockLx = 20;
    plint blockLy = 20;
    plint blockLz = 20;
    std::unique_ptr<MultiScalarField3D<T>> scalarField =
        reparallelize<T>(originalField, blockLx, blockLy, blockLz);
    pcout << getMultiBlockInfo(*scalarField) << std::endl;
    setToRandom(*scalarField, scalarField->getBoundingBox(), seed);
    writeVTK(*scalarField, "scalarField");
    pcout << "Sum = " << std::scientific << std::setprecision(16) << computeSum(*scalarField)
          << std::endl;

    pcout << std::endl;

    pcout << "Scalar Field 2" << std::endl;
    blockLx = 10;
    blockLy = 10;
    blockLz = 10;
    std::unique_ptr<MultiScalarField3D<T>> scalarField2 =
        reparallelize<T>(originalField, blockLx, blockLy, blockLz);
    pcout << getMultiBlockInfo(*scalarField2) << std::endl;
    setToRandom(*scalarField2, scalarField2->getBoundingBox(), seed);
    writeVTK(*scalarField2, "scalarField2");
    pcout << "Sum = " << std::scientific << std::setprecision(16) << computeSum(*scalarField2)
          << std::endl;

    return 0;
}
