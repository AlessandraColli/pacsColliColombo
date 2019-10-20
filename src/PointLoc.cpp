
#define R_VERSION_

#include "FEMr.hpp"
#include "mesh_objects.hpp"
#include "mesh.hpp"
#include "bounding_box.hpp"
#include "tree_header.hpp"
#include "domain.hpp"
#include "treenode.hpp"
#include "exception_handling.hpp"
#include "adtree.hpp"
extern "C" {
//! This function computes the point location with ADTree
/*!
	This function is than called from R code.
	\param Rlocation an R-vector containing the x-y coordinates of the points.
	\param Rnum_loc an R-integer containing the number of point to be located
	\param Rmesh an R-object containg the output mesh from Trilibrary
	\param Rorder an R-integer containing the order of the approximating basis.
	\return R-vector containg the index of the triangles
*/

SEXP PointLoc_c(SEXP Rlocations, SEXP Rnum_loc, SEXP Rmesh, SEXP Rorder)
{
	//set time information
	std::chrono::time_point<std::chrono::system_clock> start, end, start_tree, end_tree;
	//Set data
	int order = asInteger(Rorder); 
	int num_loc = asInteger(Rnum_loc); 
	Real location[2*num_loc];
	for(int i = 0; i < 2*num_loc; i++){
		location[i] = REAL(Rlocations)[i];
	}

	SEXP result;

	start = std::chrono::system_clock::now();
	start_tree = std::chrono::system_clock::now();
	if( order ==1 ){
		MeshHandler<1> mesh(Rmesh, 1);
		end_tree = std::chrono::system_clock::now();
		//std::cout<< "Mesh loaded"<<std::endl;
		Triangle<3> triangle;
		PROTECT(result=allocVector(INTSXP, num_loc));

		for (int i = 0; i < num_loc; i++) {
			Point search(location[2*i],location[2*i + 1]);	
			//std::cout << "search for point " << std::endl;
		//	search.print(std::cout);
	   		triangle = mesh.findLocationTree(search);
			INTEGER(result)[i] = triangle.getId() + 1;	//R indicizza i vettori partendo da 1!!
		}
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time_tree = end_tree-start_tree;
		std::chrono::duration<double> time = end-start;
		std::chrono::duration<double> time_search = end-end_tree;
		std::cout << std::endl;
		std::cout << "tempo totale impiegato:  " << time.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la costruzione della mesh:  " << time_tree.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la ricerca:  " << time_search.count() << " sec " << std::endl;
		UNPROTECT(1);
		return (result);

	}else if(order == 2){
		MeshHandler<2> mesh(Rmesh, 1);
		end_tree = std::chrono::system_clock::now();
		//std::cout<< "Mesh loaded"<<std::endl;
		Triangle<6> triangle;
		PROTECT(result=allocVector(INTSXP, num_loc));

		for (int i = 0; i < num_loc; i++) {
			Point search(location[2*i],location[2*i + 1]);	
			//std::cout << "search for point " << std::endl;
			//search.print(std::cout);
	   		triangle = mesh.findLocationTree(search);
			INTEGER(result)[i] = triangle.getId() + 1;	//R indicizza i vettori partendo da 1!!
		}
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time_tree = end_tree-start_tree;
		std::chrono::duration<double> time = end-start;
		std::chrono::duration<double> time_search = end-end_tree;
		std::cout << std::endl;
		std::cout << "tempo totale impiegato:  " << time.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la costruzione della mesh:  " << time_tree.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la ricerca:  " << time_search.count() << " sec " << std::endl;
		UNPROTECT(1);
		return (result);
	}

}

}


extern "C" {
//! This function computes the point location triangle by triangle
/*!
	This function is than called from R code.
	\param Rlocation an R-vector containing the x-y coordinates of the points.
	\param Rnum_loc an R-integer containing the number of point to be located
	\param Rmesh an R-object containg the output mesh from Trilibrary
	\param Rorder an R-integer containing the order of the approximating basis.
	\return R-vector containg the index of the triangles
*/

SEXP PointLocNaive_c(SEXP Rlocations, SEXP Rnum_loc, SEXP Rmesh, SEXP Rorder)
{
	//set time information
	std::chrono::time_point<std::chrono::system_clock> start, end, start_mesh, end_mesh;
	//Set data
	int order = asInteger(Rorder); 
	int num_loc = asInteger(Rnum_loc); 
	Real location[2*num_loc];
	for(int i = 0; i < 2*num_loc; i++){
		location[i] = REAL(Rlocations)[i];
	}

	SEXP result;

	start = std::chrono::system_clock::now();
	start_mesh = std::chrono::system_clock::now();

	if( order ==1 ){
		MeshHandler<1> mesh(Rmesh);
		end_mesh = std::chrono::system_clock::now();
		//std::cout<< "Mesh loaded"<<std::endl;
		Triangle<3> triangle;
		PROTECT(result=allocVector(INTSXP, num_loc));

		for (int i = 0; i < num_loc; i++) {
			Point search(location[2*i],location[2*i + 1]);	
		//	std::cout << "search for point " << std::endl;
		//	search.print(std::cout);
	   		triangle = mesh.findLocationNaive(search);
			INTEGER(result)[i] = triangle.getId() + 1;	//R indicizza i vettori partendo da 1!!
		}
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time_mesh = end_mesh-start_mesh;
		std::chrono::duration<double> time = end-start;
		std::chrono::duration<double> time_search = end-end_mesh;
		std::cout << std::endl;
		std::cout << "tempo totale impiegato:  " << time.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la costruzione della mesh:  " << time_mesh.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la ricerca:  " << time_search.count() << " sec " << std::endl;
		UNPROTECT(1);
		return (result);

	}else if(order == 2){
		MeshHandler<2> mesh(Rmesh);
		end_mesh = std::chrono::system_clock::now();
		//std::cout<< "Mesh loaded"<<std::endl;
		Triangle<6> triangle;
		PROTECT(result=allocVector(INTSXP, num_loc));

		for (int i = 0; i < num_loc; i++) {
			Point search(location[2*i],location[2*i + 1]);	
			//std::cout << "search for point " << std::endl;
			//search.print(std::cout);
	   		triangle = mesh.findLocationNaive(search);
			INTEGER(result)[i] = triangle.getId() + 1;	//R indicizza i vettori partendo da 1!!
		}
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time_mesh = end_mesh-start_mesh;
		std::chrono::duration<double> time = end-start;
		std::chrono::duration<double> time_search = end-end_mesh;
		std::cout << std::endl;
		std::cout << "tempo totale impiegato:  " << time.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la costruzione della mesh:  " << time_mesh.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la ricerca:  " << time_search.count() << " sec " << std::endl;
		UNPROTECT(1);
		return (result);
	}

}

}


extern "C" {
//! This function computes the point location with walking algorithm
/*!
	This function is than called from R code.
	\param Rlocation an R-vector containing the x-y coordinates of the points.
	\param Rnum_loc an R-integer containing the number of point to be located
	\param Rstart an R-vector containing the index of the starting triangles.
	\param Rnum_start an R-integer containing the number of starting triangles
	\param Rmesh an R-object containg the output mesh from Trilibrary
	\param Rorder an R-integer containing the order of the approximating basis.
	\return R-vector containg the index of the triangles
*/

SEXP PointLocWalk_c(SEXP Rlocations, SEXP Rnum_loc, SEXP Rstart, SEXP Rnum_start, SEXP Rmesh, SEXP Rorder)
{
	//set time information
	std::chrono::time_point<std::chrono::system_clock> start_time, end, start_mesh, end_mesh;
	//Set data
	int order = asInteger(Rorder); 
	int num_loc = asInteger(Rnum_loc); 
	int num_start = asInteger(Rnum_start); 
	Real location[2*num_loc];
	for(int i = 0; i < 2*num_loc; i++){
		location[i] = REAL(Rlocations)[i];
	}
	int start[num_start];
	for(int i = 0; i < num_start; i++){
		start[i] = REAL(Rstart)[i];
	}

	SEXP result;

	start_time = std::chrono::system_clock::now();
	start_mesh = std::chrono::system_clock::now();

	if( order ==1 ){
		MeshHandler<1> mesh(Rmesh);
		end_mesh = std::chrono::system_clock::now();
		//std::cout<< "Mesh loaded"<<std::endl;
		Triangle<3> triangle;
		vector<Triangle<3> > start_point(num_start);
		for(int i = 0; i < num_start; i++){
			start_point[i] = mesh.getTriangle(start[i]);
		}


		PROTECT(result=allocVector(INTSXP, num_loc));

		for (int i = 0; i < num_loc; i++) {
			Point search(location[2*i],location[2*i + 1]);	
		//	std::cout << "search for point " << std::endl;
		//	search.print(std::cout);
	   		triangle = mesh.findLocationWalking(search, start_point);
			INTEGER(result)[i] = triangle.getId() + 1;	//R indicizza i vettori partendo da 1!!
		}
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time_mesh = end_mesh-start_mesh;
		std::chrono::duration<double> time = end-start_time;
		std::chrono::duration<double> time_search = end-end_mesh;
		std::cout << std::endl;
		std::cout << "tempo totale impiegato:  " << time.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la costruzione della mesh:  " << time_mesh.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la ricerca:  " << time_search.count() << " sec " << std::endl;
		UNPROTECT(1);
		return (result);

	}else if(order == 2){
		MeshHandler<2> mesh(Rmesh);
		end_mesh = std::chrono::system_clock::now();
		//std::cout<< "Mesh loaded"<<std::endl;
		Triangle<6> triangle;
		vector<Triangle<6> > start_point(num_start);
		for(int i = 0; i < num_start; i++){
			start_point[i] = mesh.getTriangle(start[i]);
		}

		PROTECT(result=allocVector(INTSXP, num_loc));

		for (int i = 0; i < num_loc; i++) {
			Point search(location[2*i],location[2*i + 1]);	
			//std::cout << "search for point " << std::endl;
			//search.print(std::cout);
	   		triangle = mesh.findLocationWalking(search, start_point);
			INTEGER(result)[i] = triangle.getId() + 1;	//R indicizza i vettori partendo da 1!!
		}
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time_mesh = end_mesh-start_mesh;
		std::chrono::duration<double> time = end-start_time;
		std::chrono::duration<double> time_search = end-end_mesh;
		std::cout << std::endl;
		std::cout << "tempo totale impiegato:  " << time.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la costruzione della mesh:  " << time_mesh.count() << " sec " << std::endl;
		std::cout << "tempo impiegato per la ricerca:  " << time_search.count() << " sec " << std::endl;
		UNPROTECT(1);
		return (result);
	}

}

}
