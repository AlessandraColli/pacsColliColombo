# fdaPDE 2.0

## Major changes
New features: smooth regression for manifold and volumetric domains, regression with areal data, and functional smooth PCA (SF-PCA algorithm).
Stochastic GCV computation has been added: parameter 'GCVmethod' can be used both regression and FPCA, can be either 'Stochastic' or 'Exact'.
Kfold cross-validation is available in FPCA algorithm.
smooth.FEM.PDE.basis and smooth.FEM.PDE.sv.basis are deprecated, use smooth.FEM.basis instead.
The usage of 'MESH' in classes and function names has been deprecated, now use 'mesh'.
Meuse dataset has been removed. New datasets are provided.
The parameter CPP_CODE has been removed, the R-only functions (whose names began with R_) have been removed.

## Bug fixes
A bug in R/C++ indexes conversion in the space-varying regression has been fixed.
