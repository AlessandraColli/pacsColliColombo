#fdaPDE_dev

This repository contains the development version of fdaPDE package (future 2.0 version).

New features wrt CRAN: smooth regression for manifold and volumetric domains, also with areal data. Smooth fPCA over 2D, 2.5D and 3D domains, also with areal data.

Remarks: 
> the meshes 2.5D and 3D contained in /data are outdated (nodes are stored in a vector instead of a matrix). To create a consistent mesh     from those, do:

data(meshName)

vertici <- matrix(data=meshName$nodes,ncol=3,byrow=T)
triangoli <- matrix(data=meshName$triangles, ncol=3, byrow=T)

mesh <- fdaPDE::create.MESH.2.5D(nodes = vertici,triangles = triangoli)

> the shift of indexes from R to C++ is done within the R functions smooth.FEM.basis and smooth.FEM.FPCA. Do not use C++ scripts directly on the R mesh objects, unless you take care of shifing indexes by yourself.


