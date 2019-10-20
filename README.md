This repository implements ADTree search algorithm on finite element mesh.
It forks with the development version of fdaPDE package (future 2.0 version) and will be updated periodically with recent version.

ADtree search algorithm has been implemented over 2D mesh but needed to be verified as well.

**The goal is to implement ADTree search algorithm over 2.5D, 3D domain.**

*Below is README.md of forked repository.*
#fdaPDE_dev

This repository contains the development version of fdaPDE package (future 2.0 version).

New features wrt CRAN: smooth regression for manifold and volumetric domains, also with areal data. Smooth fPCA over 2D, 2.5D and 3D domains, also with areal data.

Bugs in fPCA, boundary conditions and space-varying regression have been fixed. Issues about areal data and 2.5 mesh are still under study.

Compiled in both Win RStudio and Ubuntu 18.04 using g++ compiler. If using a Linux machine, it is advisable to install rgl, plot3D and plot3Drgl before fdaPDE.

Subfolder structure
/src contains all C++ code and a special file named Makevars necessary to build and install the R package
/R contains the R functions that wrap the C++ calls

Remarks:

1) the meshes 2.5D and 3D contained in /data are outdated (nodes are stored in a vector instead of a matrix). To create a consistent mesh    from those, do:

   data(meshName)

   vertici <- matrix(data=meshName$nodes,ncol=3,byrow=T)
   triangoli <- matrix(data=meshName$triangles, ncol=3, byrow=T) # tetrahedrons with 4 columns in 3D

   mesh <- fdaPDE::create.MESH.2.5D(nodes = vertici,triangles = triangoli)
   
2) the test scripts in /tests are outdated, and will be updated as soon as possible. Scripts in /RScripts have not been verified yet.

3) the shift of indexes from R to C++ is done within the R functions smooth.FEM.basis and smooth.FEM.FPCA. Do not use C++ scripts directly on the R mesh objects, unless you take care of shifing indexes by yourself.

4) in order to plot 2D meshes, use the extended name plot.MESH.2D() instead of plot(). This is due to the fact that 2D meshes are object of class "MESH2D" instead of "MESH.2D" so automatic plot conversion is disabled. This will be fixed soon. 
