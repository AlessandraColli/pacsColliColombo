/*
 * FEMeval.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: eardi
 */


#define R_VERSION_

#include "fdaPDE.h"
//#include "IO_handler.h"
#include "mesh_objects.h"
#include "mesh.h"
#include "evaluator.h"
#include "projection.h"

extern "C" {
//! This function manages the various option for the solution evaluation.
/*!
	This function is than one called from R code.
	Call's the walking algoritm for efficient point location inside the mesh.

	\param Rmesh an R-object containg the output mesh from Trilibrary
	\param RX an R-vector containing the x coordinates of the points to be evaluated
	\param RY an R-vector containing the y coordinates of the points to be evaluated
	\param RZ an R-vector containing the z coordinates of the points to be evaluated
	\param Rcoef an R-vector the coeficients of the solution
	\param Rorder an R integer containg the order of the solution
	\param Rfast an R integer 0 for Naive location algorithm, 1 for Walking Algorithm (can miss location for non convex meshes)
*/

/*
SEXP eval_FEM_fd(SEXP Rmesh, SEXP RX, SEXP RY, SEXP Rcoef, SEXP Rorder, SEXP Rfast, SEXP Rmydim, SEXP Rndim)
{
	//Declare pointer to access data from C++

    double *X, *Y, *coef;
	int order,mydim,ndim;
	bool fast;

	//int n_coef 	= Rf_length(Rcoef);
	int n_X 	= Rf_length(RX);

    // Cast all computation parameters
    X 			= REAL(RX);
    Y 			= REAL(RY);
    coef 		= REAL(Rcoef);
    order 		= INTEGER(Rorder)[0];
    fast 		= INTEGER(Rfast)[0];
    mydim               = INTEGER(Rmydim)[0];
    ndim                = INTEGER(Rndim)[0];

    SEXP result;
	PROTECT(result=Rf_allocVector(REALSXP, n_X));
	std::vector<bool> isinside(n_X);
    //Set the mesh
	//std::cout<<"Length "<<n_X<<"--X0 "<<X[0]<<"--Y0 "<<Y[0];
    if(order == 1)
    {
    	MeshHandler<1,2,2> mesh(Rmesh);
		Evaluator<1,2,2> evaluator(mesh);
		//std::cout<<"Starting evaluation from FEMeval \n";
		evaluator.eval(X, Y, n_X, coef, order, fast, REAL(result), isinside);
	}
	else if(order == 2)
	{
    	MeshHandler<2,2,2> mesh(Rmesh);
    	Evaluator<2,2,2> evaluator(mesh);
		evaluator.eval(X, Y, n_X, coef, order, fast, REAL(result), isinside);
	}

    for (int i=0; i<n_X;++i)
    {
    	if(!(isinside[i]))
    	{
    		REAL(result)[i]=NA_REAL;
    	}

    }

	UNPROTECT(1);
    // result list
    return(result);
}*/

SEXP eval_FEM_fd(SEXP Rmesh, SEXP Rlocations, SEXP RincidenceMatrix, SEXP Rcoef, SEXP Rorder, SEXP Rfast, SEXP Rmydim, SEXP Rndim, SEXP Rsearch)
{
	int n_X = INTEGER(Rf_getAttrib(Rlocations, R_DimSymbol))[0];
	int nRegions = INTEGER(Rf_getAttrib(RincidenceMatrix, R_DimSymbol))[0];
	int nElements = INTEGER(Rf_getAttrib(RincidenceMatrix, R_DimSymbol))[1]; //number of triangles/tetrahedron if areal data
	//Declare pointer to access data from C++
	double *X, *Y, *Z;
	UInt **incidenceMatrix;
	double *coef;
	int order, mydim, ndim, search;
	bool fast;

	coef  = REAL(Rcoef);
    order = INTEGER(Rorder)[0];
    fast  = INTEGER(Rfast)[0];
    mydim = INTEGER(Rmydim)[0];
    ndim  = INTEGER(Rndim)[0];
	search  = INTEGER(Rsearch)[0];

	X = (double*) malloc(sizeof(double)*n_X);
	Y = (double*) malloc(sizeof(double)*n_X);
	Z = (double*) malloc(sizeof(double)*n_X);
	incidenceMatrix = (UInt**) malloc(sizeof(UInt*)*nRegions);

    // Cast all computation parameters
	if (ndim==3)
	{
		for (int i=0; i<n_X; i++)
		{
			X[i] = REAL(Rlocations)[i + n_X*0];
			//Rprintf("X[%i]= %d", i, X[i]);
			Y[i] = REAL(Rlocations)[i + n_X*1];
			Z[i] = REAL(Rlocations)[i + n_X*2];
		}
	}
	else //ndim==2
	{
		for (int i=0; i<n_X; i++)
		{
			X[i] = REAL(Rlocations)[i + n_X*0];
			Y[i] = REAL(Rlocations)[i + n_X*1];
			Z[i] = 0;
		}
	}
	for (int i=0; i<nRegions; i++)
	{
		incidenceMatrix[i] = (UInt*) malloc(sizeof(UInt)*nElements);
		for (int j=0; j<nElements; j++)
		{
			incidenceMatrix[i][j] = INTEGER(RincidenceMatrix)[i+nRegions*j];
		}
	}

//    #ifdef R_VERSION_
//    Rprintf("n_X: %i\n", n_X);
//    for( int i=0; i<n_X; i++)
//     Rprintf("X[%i]=%d , Y[%i] =%d , Z[%i]=%d  \n", i,X[i],i,Y[i],i,Z[i]);
//    
//	Rprintf("printing incidence matrix: \n");
//	for(int i = 0; i<nRegions; i++)
//	 for(int j=0; j<nElements; j++)
//	  Rprintf("[%i][%i]=%i , ", i,j,incidenceMatrix[i][j]);
    
//    #endif

    SEXP result;

	if (n_X>0) //pointwise data
	{
		PROTECT(result = Rf_allocVector(REALSXP, n_X));
		std::vector<bool> isinside(n_X);
		//Set the mesh
		//std::cout<<"Length "<<n_X<<"--X0 "<<X[0]<<"--Y0 "<<Y[0];
		if(order==1 && mydim==2 && ndim==2)
		{
			MeshHandler<1,2,2> mesh(Rmesh);
			Evaluator<1,2,2> evaluator(mesh);
			//std::cout<<"Starting evaluation from FEMeval \n";
			evaluator.eval(X, Y, n_X, coef, fast, REAL(result), isinside, search);
		}
		else if(order==2 && mydim==2 && ndim==2)
		{
			MeshHandler<2,2,2> mesh(Rmesh);
			Evaluator<2,2,2> evaluator(mesh);
			evaluator.eval(X, Y, n_X, coef, fast, REAL(result), isinside, search);
		}
		else if(order==1 && mydim==2 && ndim==3)
		{ 
			MeshHandler<1,2,3> mesh(Rmesh);
			//mesh.printTriangles(std::cout);
			//mesh.printPoints(std::cout);
			Evaluator<1,2,3> evaluator(mesh);
			evaluator.eval(X, Y, Z, n_X, coef, fast, REAL(result), isinside, search);
		}
		else if(order==2 && mydim==2 && ndim==3)
		{
			MeshHandler<2,2,3> mesh(Rmesh);
			Evaluator<2,2,3> evaluator(mesh);
			evaluator.eval(X, Y, Z, n_X, coef, fast, REAL(result), isinside, search);
		}
		else if(order==1 && mydim==3 && ndim==3)
		{ 
			MeshHandler<1,3,3> mesh(Rmesh);
			//mesh.printTriangles(std::cout);
			//mesh.printPoints(std::cout);
			Evaluator<1,3,3> evaluator(mesh);
			evaluator.eval(X, Y, Z, n_X, coef, fast, REAL(result), isinside, search);
		}

		for (int i=0; i<n_X; ++i)
		{
			if(!(isinside[i]))
			{
				REAL(result)[i]=NA_REAL;
			}
		}
	}
	else //areal data
	{
		PROTECT(result = Rf_allocVector(REALSXP, nRegions));
		if(order==1 && mydim==2 && ndim==2)
		{
			MeshHandler<1,2,2> mesh(Rmesh);
			Evaluator<1,2,2> evaluator(mesh);
			evaluator.integrate(incidenceMatrix, nRegions, nElements, coef, REAL(result));
		}
		else if(order==2 && mydim==2 && ndim==2)
		{
			MeshHandler<2,2,2> mesh(Rmesh);
			Evaluator<2,2,2> evaluator(mesh);
			evaluator.integrate(incidenceMatrix, nRegions, nElements, coef, REAL(result));
		}
		else if(order==1 && mydim==2 && ndim==3)
		{ 
			MeshHandler<1,2,3> mesh(Rmesh);
			Evaluator<1,2,3> evaluator(mesh);
			evaluator.integrate(incidenceMatrix, nRegions, nElements, coef, REAL(result));
		}
		else if(order==2 && mydim==2 && ndim==3)
		{
			MeshHandler<2,2,3> mesh(Rmesh);
			Evaluator<2,2,3> evaluator(mesh);
			evaluator.integrate(incidenceMatrix, nRegions, nElements, coef, REAL(result));
		}
		else if(order==1 && mydim==3 && ndim==3)
		{ 
			MeshHandler<1,3,3> mesh(Rmesh);
			Evaluator<1,3,3> evaluator(mesh);
			evaluator.integrate(incidenceMatrix, nRegions, nElements, coef, REAL(result));
//				#ifdef R_VERSION_
//				for (int region=0; region<nRegions; region++)
//				Rprintf("outside: result[%i] : %d \n", region, REAL(result)[region]);
//				#endif
		}
	}

	free(X); free(Y); free(Z);
	for (int i=0; i<nRegions; i++)
	{
		free(incidenceMatrix[i]);
	}
	free(incidenceMatrix);
	

	UNPROTECT(1);
    // result list
    return(result);
}


SEXP data_projection(SEXP Rmesh, SEXP Rlocations)
{
	int n_X = INTEGER(Rf_getAttrib(Rlocations, R_DimSymbol))[0];
	//Declare pointer to access data from C++
	double X, Y, Z;

    // Cast all computation parameters
    std::vector<Point> deData_(n_X); // the points to be projected
    std::vector<Point> prjData_(n_X); // the projected points
    
    for (int i=0; i<n_X; i++)
	{
		X = REAL(Rlocations)[i + n_X*0];
		//Rprintf("X[%i]= %d", i, X[i]);
		Y = REAL(Rlocations)[i + n_X*1];
		Z = REAL(Rlocations)[i + n_X*2];
		deData_[i]=Point(X,Y,Z);

		if (i==0) {
			Rprintf("Rlocation_0: %f\n", REAL(Rlocations)[i + n_X*0]);
			Rprintf("Rlocation_1: %f\n", REAL(Rlocations)[i + n_X*1]);
			Rprintf("Rlocation_2: %f\n", REAL(Rlocations)[i + n_X*2]);
			Rprintf("X= %f\n", X);
			Rprintf("Y= %f\n", Y);
			Rprintf("Z= %f\n", Z);
		}
	}

    SEXP result;

	if (n_X>0) //pointwise data
	{
		PROTECT(result = Rf_allocMatrix(REALSXP, n_X, 3));
		//default order: 1 *************************
		MeshHandler<1,2,3> mesh(Rmesh);
		projection<1,2,3> projector(mesh, deData_);
		prjData_ = projector.computeProjection();
	}

	for (int i=0; i<n_X; ++i)
	{
		REAL(result)[i + n_X*0]=prjData_[i][0];
		REAL(result)[i + n_X*1]=prjData_[i][1];
		REAL(result)[i + n_X*2]=prjData_[i][2];

		if (i==0) {
			Rprintf("prjData_[i][0]= %f\n", prjData_[i][0]);
			Rprintf("prjData_[i][1]= %f\n", prjData_[i][1]);
			Rprintf("prjData_[i][2]= %f\n", prjData_[i][2]);
			Rprintf("result_0: %f\n", REAL(result)[i + n_X*0]);
			Rprintf("result_1: %f\n", REAL(result)[i + n_X*1]);
			Rprintf("result_2: %f\n", REAL(result)[i + n_X*2]);

		}
	}

	UNPROTECT(1);
    // result matrix
    return(result);
}

}

