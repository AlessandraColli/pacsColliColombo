#include "FEMr.hpp"
#include "mesh_objects.hpp"
#include "bounding_box.hpp"
#include "domain.hpp"
#include "treenode.hpp"
#include "tree_header.hpp"
#include "adtree.hpp"
#include "mesh.hpp"

extern "C"{
void Test_Point_c(int *n){
	
	try{
	//2-dimen
	Point a(10,20);     //Point with coordinates
	Point b(1,2,15,25); //Point with Id, bcId and coordinates
	
	//3-dimen
	Point c;	//default constructor
	Point d(10,20,30);     //Point with coordinates
	Point e(1,2,15,25,35); //Point with Id, bcId and coordinates
	
	std::cout << std::endl << std::endl;
	std::cout << "Print the first point (inizialized by 2-dimen coordinates):  " <<std::endl;
	a.print(std::cout);
	std::cout << "physical dimension:  " << a.dp() <<std::endl;
	std::cout << "search dimension:  " << a.dt() << std::endl;
	std::cout << "coordsize():  " << a.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the second point (inizialized by 2-dimen coordinates and Ids):  " <<std::endl;
	b.print(std::cout);
	std::cout << "physical dimension:  " << b.dp() <<std::endl;
	std::cout << "search dimension:  " << b.dt() << std::endl;
	std::cout << "coordsize():  " << b.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the third point (default constructor):  " <<std::endl;
	c.print(std::cout);
	std::cout << "physical dimension:  " << c.dp() << std::endl;
	std::cout << "search dimension:  " << c.dt() << std::endl;
	std::cout << "coordsize():  " << c.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the fourth point (inizialized by 3-dimen coordinates):  " <<std::endl;
	d.print(std::cout);
	std::cout << "physical dimension:  " << d.dp() << std::endl;
	std::cout << "search dimension:  " << d.dt() << std::endl;
	std::cout << "coordsize():  " << d.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the fifth point (inizialized by 3-dimen coordinates and Ids):  " <<std::endl;
	e.print(std::cout);
	std::cout << "physical dimension:  " << e.dp() << std::endl;
	std::cout << "search dimension:  " << e.dt() << std::endl;
	std::cout << "coordsize():  " << e.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	*n = 0;

	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}	
}
}

extern "C"{
void Test_Element_c(int *n){
	try{
		////Point in 2-dimen
	Point a(1,2,1,1); //Point with Id, bcId and coordinates
	Point b(2,3,3,1); //Point with Id, bcId and coordinates
	Point c(3,4,2,2); //Point with Id, bcId and coordinates

	Point d(4,5,2.5,1.5); //Point with Id, bcId and coordinates
	Point e(5,6,1.5,1.5); //Point with Id, bcId and coordinates
	Point f(6,7,2,1); //Point with Id, bcId and coordinates

	Point test(2,1.5); //Point with coordinates
	std::vector<Point> vec{a,b,c};
	std::vector<Point> vec2{a,b,c,d,e,f};

	//case 1: Triangle in 2-dimen
	Element<3,2,2> Ta;		//default constructor
	Element<6,2,2> Tb;		//default constructor
	Element<3,2,2> Tc(1, vec);	//constructor from id and a vector of point
	Element<6,2,2> Td(2, vec2);	//constructor from id and a vector of point

	//Point in 3-dimen
	Point g(1,2,1,1,2); //Point with Id, bcId and coordinates
	Point h(2,3,3,1,3); //Point with Id, bcId and coordinates
	Point i(3,4,2,2,1); //Point with Id, bcId and coordinates
	Point j(4,5,4,3,2); //Point with Id, bcId and coordinates
	Point test2 (2.5,1.75,2);  //(2,1.5,2.5); //Point with coordinates

	std::vector<Point> vec3{g,h,i};
	std::vector<Point> vec4{g,h,i,j};
	
	//case 2: Triangle in 3-dimen
	Element<3,2,3> Te;		//default constructor
	Element<3,2,3> Tf(3, vec3);	//constructor from id and a vector of point

	//case 3: Tetrahedron in 3-dimen (there are 4 nodes for tetrahedron)
	Element<4,3,3> Tg(4, vec4);	//constructor from id and a vector of point
	

	std::cout << "Print the first triangle in 2 dimension (default constructor, 3 nodes):  " <<std::endl;
	Ta.print(std::cout);
	std::cout << "Print each node: " << std::endl;
	Ta[0].print(std::cout); 
	Ta[1].print(std::cout);
	Ta[2].print(std::cout);
	std::cout << "physical dimension:  " << Ta.dp() <<std::endl;
	std::cout << "search dimension:  " << Ta.dt() <<std::endl;
	std::cout << "test: is point (2, 1.5) inside? (1 if true): " << Ta.isPointInside(test)<<std::endl;
	std::cout << "coordsize():  " << Ta.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the second triangle 2 dimension (default constructor, 6 nodes):  " <<std::endl;
	Tb.print(std::cout);
	std::cout << "Print each node: " << std::endl;
	Tb[0].print(std::cout); 
	Tb[1].print(std::cout);
	Tb[2].print(std::cout);
	Tb[3].print(std::cout); 
	Tb[4].print(std::cout);
	Tb[5].print(std::cout);
	std::cout << "physical dimension:  " << Tb.dp() <<std::endl;
	std::cout << "search dimension:  " << Tb.dt() <<std::endl;
	std::cout << "test: is point (2, 1.5) inside? (1 if true): " << Tb.isPointInside(test)<<std::endl;
	std::cout << "coordsize():  " << Tb.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the third triangle 2 dimension (construct by coordinates Points a(1,2,1,1), b(2,3,3,1),c(3,4,2,2), 3 nodes):  " <<std::endl;
	Tc.print(std::cout);
	std::cout << "Print each node: " << std::endl;
	Tc[0].print(std::cout); 
	Tc[1].print(std::cout);
	Tc[2].print(std::cout);
	std::cout << "physical dimension:  " << Tc.dp() <<std::endl;
	std::cout << "search dimension:  " << Tc.dt() <<std::endl;
	std::cout << "test: is point (2, 1.5) inside? (1 if true): " << Tc.isPointInside(test)<<std::endl;
	std::cout << "coordsize():  " << Tc.coordsize() << std::endl;
	std::cout << std::endl << std::endl;
	
	std::cout << "Print the fourth triangle 2 dimension (construct by coordinates Points a(1,2,1,1), b(2,3,3,1), c(3,4,2,2), d(4,5,2.5,1.5), e(5,6,1.5,1.5), f(6,7,2,1), 6 nodes):  " <<std::endl;
	Td.print(std::cout);
	std::cout << "Print each node: " << std::endl;
	Td[0].print(std::cout);
	Td[1].print(std::cout);
	Td[2].print(std::cout);
	Td[3].print(std::cout);
	Td[4].print(std::cout);
	Td[5].print(std::cout);
	std::cout << "physical dimension:  " << Td.dp() <<std::endl;
	std::cout << "search dimension:  " << Td.dt() <<std::endl;
	std::cout << "test: is point (2, 1.5) inside? (1 if true): " << Td.isPointInside(test)<<std::endl;
	std::cout << "coordsize():  " << Td.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the fifth triangle in 3 dimension (default constructor):  " <<std::endl;
	Te.print(std::cout);
	std::cout << "Print each node: " << std::endl;
	Te[0].print(std::cout);
	Te[1].print(std::cout);
	Te[2].print(std::cout);
	std::cout << "physical dimension:  " << Te.dp() <<std::endl;
	std::cout << "search dimension:  " << Te.dt() <<std::endl;
	std::cout << "test: is point (2,1.5,2.5) inside? (1 if true): " << Te.isPointInside(test2)<<std::endl;
	std::cout << "coordsize():  " << Te.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the sixth triangle in 3 dimension (construct by coordinates Points):  " <<std::endl;
	Tf.print(std::cout);
	std::cout << "Print each node: " << std::endl;
	Tf[0].print(std::cout);
	Tf[1].print(std::cout);
	Tf[2].print(std::cout);
	std::cout << "physical dimension:  " << Tf.dp() <<std::endl;
	std::cout << "search dimension:  " << Tf.dt() <<std::endl;
	std::cout << "test: is point (2,1.5,2.5) inside? (1 if true): " << Tf.isPointInside(test2)<<std::endl;
	std::cout << "coordsize():  " << Tf.coordsize() << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the seventh tetrahedron in 3 dimension (construct by coordinates Points):  " <<std::endl;
	Tg.print(std::cout);
	std::cout << "Print each node: " << std::endl;
	Tg[0].print(std::cout);
	Tg[1].print(std::cout);
	Tg[2].print(std::cout);
	Tg[3].print(std::cout);
	std::cout << "physical dimension:  " << Tg.dp() <<std::endl;
	std::cout << "search dimension:  " << Tg.dt() <<std::endl;
	std::cout << "test: is point (2,1.5,2.5) inside? (1 if true): " << Tg.isPointInside(test2)<<std::endl;
	std::cout << "coordsize():  " << Tg.coordsize() << std::endl;
	std::cout << std::endl << std::endl;
	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}
}
}


extern "C"{
void Test_Box_c(int *n){
	
	try{
	//Point in 2-dimen
	Point a(1,2,1,1); //Point with Id, bcId and coordinates
	Point b(2,3,3,1); //Point with Id, bcId and coordinates
	Point c(3,4,2,2); //Point with Id, bcId and coordinates

	Point d(4,5,2.5,1.5); //Point with Id, bcId and coordinates
	Point e(5,6,1.5,1.5); //Point with Id, bcId and coordinates
	Point f(6,7,2,1); //Point with Id, bcId and coordinates

	//Triangle in 2-dimen
	std::vector<Point> vec{a,b,c};
	std::vector<Point> vec2{a,b,c,d,e,f};
	Element<3,2,2> Tb(1, vec);
	Element<6,2,2> Td(2, vec2);	
	
	
	//Point in 3-dimen
	Point g(1,2,1,1,2); //Point with Id, bcId and coordinates
	Point h(2,3,3,1,3); //Point with Id, bcId and coordinates
	Point i(3,4,2,2,1); //Point with Id, bcId and coordinates
	Point j(4,5,4,3,2); //Point with Id, bcId and coordinates
	
	//******* node validation to be tested
	// Point d(4,5,2.5,1.5); //Point with Id, bcId and coordinates
	// Point e(5,6,1.5,1.5); //Point with Id, bcId and coordinates
	// Point f(6,7,2,1); //Point with Id, bcId and coordinates

	//Triangle in 3-dimen
	std::vector<Point> vec3{g,h,i};
	Element<3,2,3> Ta(3, vec3);

	//Tetrahedron in 3-dimen
	std::vector<Point> vec4{g,h,i,j};
	Element<3,3,3> Tc(4, vec4);
	
	std::vector<Real> coord{1,1,4,3};
	std::vector<Real> coord2{1,1,1,4,3,5};
	std::vector<Real> coord3{2,2,5,4};
	std::vector<Real> coord4{2,2,2,5,4,6};
	
	//case 1: Triangle with 2-dimen Box
	Box<2,2> Ba;	//default constructor, 2D box
	Box<2,2> Bb(coord);	//construct by coordinates
	Box<2,2> Bc(Tb);	//construct from a Element<3,2,2>
	Box<2,2> Bd(Td);	//construct from a Element<6,2,2>
	Box<2,2> Be(Bb);	//copy constructor

	//case 2: Triangle with 3-dimen Box
	Box<2,3> Bf;	//default constructor, 3D box
	Box<2,3> Bg(coord2);	//construct by coordinates, 3D box
	Box<2,3> Bh(Ta);	//construct from a Element<3,2,3>

	//case 3: Tetrahedron with 3-dimen Box
	Box<3,3> Bi(Tc);	//construct from a Element<3,3,3>
	

	std::cout << "Print the first box (default constructor, NDIMP = 2):  " <<std::endl;
	Ba.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Ba[0] <<" , " << Ba[1] <<")" <<std::endl;
	std::cout << "(" << Ba[2] <<" , " << Ba[3] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Ba.dp() <<std::endl;
	std::cout << "search dimension:  " << Ba.dt() <<std::endl;
	std::cout << "vector dimension:  " << Ba.coordsize() <<std::endl;
	std::cout << "change coordinates to {2,2,5,4}:  " << std::endl;
	Ba.set(coord3);
	Ba.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Print the second box (construct from a vector {1,1,4,3}, NDIMP = 2):  " <<std::endl;
	Bb.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Bb[0] <<" , " << Bb[1] <<")" <<std::endl;
	std::cout << "(" << Bb[2] <<" , " << Bb[3] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Bb.dp() <<std::endl;
	std::cout << "search dimension:  " << Bb.dt() <<std::endl;
	std::cout << "vector dimension:  " << Bb.coordsize() <<std::endl;
	std::cout << "change coordinates to {2,2,5,4}:  " << std::endl;
	Bb.set(coord3);
	Bb.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Print the third box (construct from a 3 nodes triangle formed by (1,1),(3,1),(2,2), NDIMP = 2):  " <<std::endl;
	Bc.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Bc[0] <<" , " << Bc[1] <<")" <<std::endl;
	std::cout << "(" << Bc[2] <<" , " << Bc[3] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Bc.dp() <<std::endl;
	std::cout << "search dimension:  " << Bc.dt() <<std::endl;
	std::cout << "vector dimension:  " << Bc.coordsize() <<std::endl;
	std::cout << "change coordinates to {2,2,5,4}:  " << std::endl;
	Bc.set(coord3);
	Bc.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Print the fourth box (construct from 6 nodes triangle with vertex (1,1),(3,1),(2,2), NDIMP = 2):  " <<std::endl;
	Bd.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Bd[0] <<" , " << Bd[1] <<")" <<std::endl;
	std::cout << "(" << Bd[2] <<" , " << Bd[3] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Bd.dp() <<std::endl;
	std::cout << "search dimension:  " << Bd.dt() <<std::endl;
	std::cout << "vector dimension:  " << Bd.coordsize() <<std::endl;
	std::cout << "change coordinates to {2,2,5,4}  " << std::endl;
	Bd.set(coord3);
	Bd.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Print the fifth box (copy constructor from the first box {1,1,4,3}, NDIMP = 2):  " <<std::endl;
	Be.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Be[0] <<" , " << Be[1] <<")" <<std::endl;
	std::cout << "(" << Be[2] <<" , " << Be[3] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Be.dp() <<std::endl;
	std::cout << "search dimension:  " << Be.dt() <<std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "Print the sixth box (default constructor, NDIMP = 3):  " <<std::endl;
	Bf.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Bf[0] <<" , " << Bf[1] << " , " << Bf[2] <<")" <<std::endl;
	std::cout << "(" << Bf[3] <<" , " << Bf[4] << " , " << Bf[5] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Bf.dp() <<std::endl;
	std::cout << "search dimension:  " << Bf.dt() <<std::endl;
	std::cout << "vector dimension:  " << Bf.coordsize() <<std::endl;
	std::cout << "change coordinates {2,2,2,5,4,6} " << std::endl;
	Bf.set(coord4);
	Bf.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Print the seventh box (construct from a vector {1,1,1,4,3,5}, NDIMP = 3):  " <<std::endl;
	Bg.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Bg[0] <<" , " << Bg[1] << " , " << Bg[2] <<")" <<std::endl;
	std::cout << "(" << Bg[3] <<" , " << Bg[4] << " , " << Bg[5] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Bg.dp() <<std::endl;
	std::cout << "search dimension:  " << Bg.dt() <<std::endl;
	std::cout << "vector dimension:  " << Bg.coordsize() <<std::endl;
	std::cout << "change coordinates to {2,2,2,5,4,6}  " << std::endl;
	Bg.set(coord4);
	Bg.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Print the eighth box (construct from a 3 nodes triangle, NDIMP = 3):  " <<std::endl;
	Bh.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Bh[0] <<" , " << Bh[1] << " , " << Bh[2] <<")" <<std::endl;
	std::cout << "(" << Bh[3] <<" , " << Bh[4] << " , " << Bh[5] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Bh.dp() <<std::endl;
	std::cout << "search dimension:  " << Bh.dt() <<std::endl;
	std::cout << "vector dimension:  " << Bh.coordsize() <<std::endl;
	std::cout << "change coordinates to {2,2,2,5,4,6}  " << std::endl;
	Bh.set(coord4);
	Bh.print(std::cout);
	std::cout << std::endl << std::endl;

	std::cout << "Print the nineth box (construct from a 4 nodes Tetrahedron, NDIMP = 3):  " <<std::endl;
	Bi.print(std::cout);
	std::cout << "operator []: " << std::endl;
	std::cout << "(" << Bi[0] <<" , " << Bi[1] << " , " << Bi[2] <<")" <<std::endl;
	std::cout << "(" << Bi[3] <<" , " << Bi[4] << " , " << Bi[5] <<")" <<std::endl;
	std::cout << "physical dimension:  " << Bi.dp() <<std::endl;
	std::cout << "search dimension:  " << Bi.dt() <<std::endl;
	std::cout << "vector dimension:  " << Bi.coordsize() <<std::endl;
	std::cout << "change coordinates to {2,2,2,5,4,6}  " << std::endl;
	Bi.set(coord4);
	Bi.print(std::cout);
	std::cout << std::endl << std::endl;

	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}
}
}

extern "C"{
void Test_Domain_c(int *n){
	
	try{
	std::vector<std::vector<Real>> coord;
	coord.resize(2);
	for (int i = 0; i < 2; i++) //2dimen
	{
		coord[i].resize(10);
		for(int j = 0; j < 10; j++)
			coord[i][j] = i+j;	
	}
	// 0 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9 10

	std::vector<std::vector<Real>> coord2;
	coord2.resize(3);
	for (int i = 0; i < 3; i++) //3dimen
	{
		coord2[i].resize(10);
		for(int j = 0; j < 10; j++)
			coord2[i][j] = i+j;
	}
	// 0 1 2 3 4 5 6 7 8  9
	// 1 2 3 4 5 6 7 8 9  10
	// 2 3 4 5 6 7 8 9 10 11

	
	
/* Domain<Point>
   Domain<Triangle> sono solo 2D
   Domain<Box> può essere 2D o 3D
*/
	// Domain<Point> Pa(coord); //1st
	Domain<Triangle<3>> Ta(coord); //2nd
	Domain<Box<2>> Ba(coord); //3rd

	// Domain<Point> Pb; //4th
	Domain<Triangle<3>> Tb; //5th
	Domain<Box<2>> Bb; //6th

	Domain<Box<3>> Bc(coord2); //7th
	Domain<Box<3>> Bd; //8th
	

	// std::cout << "Print the first domain (constructor from coordinates (x from 0 to 9, y from 1 to 10), shape = point, NDIMP = 2):  " <<std::endl;
	// std::cout << Pa <<std::endl;
	// std::cout << "origin of the object: " << std::endl;
	// std::cout << "(" << Pa.orig(0) <<" , " << Pa.orig(1) << ")" <<std::endl;
	// std::cout << "scaling factor:  " << std::endl;
	// std::cout << "(" << Pa.scal(0) <<" , " << Pa.scal(1) << ")" <<std::endl;
	// //**************added
	// std::cout << "size of origin coordiate:  " << std::endl;
	// std::cout << Pa.getoriginsize() <<std::endl;
	// std::cout << "size of scaling factor coordiate:  " << std::endl;
	// std::cout << Pa.getscalingsize() <<std::endl;
	// std::cout << "physical dimension size:  " << std::endl;
	// std::cout << Pa.getdp() <<std::endl;
	// std::cout << "search dimension size:  " << std::endl;
	// std::cout << Pa.getdt() <<std::endl;
	// std::cout << "print tolerance:  " << Pa.gettolerance() << std::endl;
	// std::cout << "change tolerance to 0.01:  " << std::endl;
	// Pa.settolerance(0.01);
	// std::cout << "print new tolerance:  " << Pa.gettolerance() << std::endl;
	// std::cout << "print minimum difference between coordinates:  " << Pa.getmindiff() << std::endl;
	// std::cout << "change minimum difference between coordinates to 0.003:  " << std::endl;
	// Pa.setmindiff(0.003);
	// std::cout << "print new minimum difference between coordinates:  " << Pa.getmindiff() << std::endl;
	// std::cout << std::endl << std::endl;



	std::cout << "Print the second domain (constructor from coordinates (x from 0 to 9, y from 1 to 10), shape = Triangle<3>, NDIMP = 2):  " <<std::endl;
	std::cout << Ta <<std::endl;
	std::cout << "origin of the object: " << std::endl;
	std::cout << "(" << Ta.orig(0) <<" , " << Ta.orig(1) << ")" <<std::endl;
	std::cout << "scaling factor:  " << std::endl;
	std::cout << "(" << Ta.scal(0) <<" , " << Ta.scal(1) << ")" <<std::endl;
	//**************added
	std::cout << "size of origin coordiate:  " << std::endl;
	std::cout << Ta.getoriginsize() <<std::endl;
	std::cout << "size of scaling factor coordiate:  " << std::endl;
	std::cout << Ta.getscalingsize() <<std::endl;
	std::cout << "physical dimension size:  " << std::endl;
	std::cout << Ta.getdp() <<std::endl;
	std::cout << "search dimension size:  " << std::endl;
	std::cout << Ta.getdt() <<std::endl;

	std::cout << "print tolerance:  " << Ta.gettolerance() << std::endl;
	std::cout << "change tolerance to 0.01:  " << std::endl;
	Ta.settolerance(0.01);
	std::cout << "print new tolerance:  " << Ta.gettolerance() << std::endl;
	std::cout << "print minimum difference between coordinates:  " << Ta.getmindiff() << std::endl;
	std::cout << "change minimum difference between coordinates to 0.003:  " << std::endl;
	Ta.setmindiff(0.003);
	std::cout << "print new minimum difference between coordinates:  " << Ta.getmindiff() << std::endl;
	std::cout << std::endl << std::endl;



	std::cout << "Print the third domain (constructor from coordinates (x from 0 to 9, y from 1 to 10), shape = Box<2>, NDIMP = 2):  " <<std::endl;
	std::cout << Ba <<std::endl;
	std::cout << "origin of the object: " << std::endl;
	std::cout << "(" << Ba.orig(0) <<" , " << Ba.orig(1) << ")" <<std::endl;
	std::cout << "scaling factor:  " << std::endl;
	std::cout << "(" << Ba.scal(0) <<" , " << Ba.scal(1) << ")" <<std::endl;
	//**************added
	std::cout << "size of origin coordiate:  " << std::endl;
	std::cout << Ba.getoriginsize() <<std::endl;
	std::cout << "size of scaling factor coordiate:  " << std::endl;
	std::cout << Ba.getscalingsize() <<std::endl;
	std::cout << "physical dimension size:  " << std::endl;
	std::cout << Ba.getdp() <<std::endl;
	std::cout << "search dimension size:  " << std::endl;
	std::cout << Ba.getdt() <<std::endl;

	std::cout << "print tolerance:  " << Ba.gettolerance() << std::endl;
	std::cout << "change tolerance to 0.01:  " << std::endl;
	Ba.settolerance(0.01);
	std::cout << "print new tolerance:  " << Ba.gettolerance() << std::endl;
	std::cout << "print minimum difference between coordinates:  " << Ba.getmindiff() << std::endl;
	std::cout << "change minimum difference between coordinates 0.003:  " << std::endl;
	Ba.setmindiff(0.003);
	std::cout << "print new minimum difference between coordinates:  " << Ba.getmindiff() << std::endl;
	std::cout << std::endl << std::endl;



	// std::cout << "Print the fourth domain (constructor default, shape = Point, NDIMP = 2):  " <<std::endl;
	// std::cout << Pb <<std::endl;
	// std::cout << "origin of the object: " << std::endl;
	// std::cout << "(" << Pb.orig(0) <<" , " << Pb.orig(1) << ")" <<std::endl;
	// std::cout << "scaling factor:  " << std::endl;
	// std::cout << "(" << Pb.scal(0) <<" , " << Pb.scal(1) << ")" <<std::endl;
	// //**************added
	// std::cout << "size of origin coordiate:  " << std::endl;
	// std::cout << Pb.getoriginsize() <<std::endl;
	// std::cout << "size of scaling factor coordiate:  " << std::endl;
	// std::cout << Pb.getscalingsize() <<std::endl;
	// std::cout << "physical dimension size:  " << std::endl;
	// std::cout << Pb.getdp() <<std::endl;
	// std::cout << "search dimension size:  " << std::endl;
	// std::cout << Pb.getdt() <<std::endl;

	// std::cout << "print tolerance:  " << Pb.gettolerance() << std::endl;
	// std::cout << "change tolerance to 0.05:  " << std::endl;
	// Pb.settolerance(0.05);
	// std::cout << "print new tolerance:  " << Pb.gettolerance() << std::endl;
	// std::cout << "print minimum difference between coordinates:  " << Pb.getmindiff() << std::endl;
	// std::cout << "change minimum difference between coordinates to 0.009:  " << std::endl;
	// Pb.setmindiff(0.009);
	// std::cout << "print new minimum difference between coordinates:  " << Pb.getmindiff() << std::endl;
	// std::cout << std::endl << std::endl;




	std::cout << "Print the fifth domain (constructor default, shape = Triangle<3>, NDIMP = 2):  " <<std::endl;
	std::cout << Tb <<std::endl;
	std::cout << "origin of the object: " << std::endl;
	std::cout << "(" << Tb.orig(0) <<" , " << Tb.orig(1) << ")" <<std::endl;
	std::cout << "scaling factor:  " << std::endl;
	std::cout << "(" << Tb.scal(0) <<" , " << Tb.scal(1) << ")" <<std::endl;
	//**************added
	std::cout << "size of origin coordiate:  " << std::endl;
	std::cout << Tb.getoriginsize() <<std::endl;
	std::cout << "size of scaling factor coordiate:  " << std::endl;
	std::cout << Tb.getscalingsize() <<std::endl;
	std::cout << "physical dimension size:  " << std::endl;
	std::cout << Tb.getdp() <<std::endl;
	std::cout << "search dimension size:  " << std::endl;
	std::cout << Tb.getdt() <<std::endl;

	std::cout << "print tolerance:  " << Tb.gettolerance() << std::endl;
	std::cout << "change tolerance to 0.01:  " << std::endl;
	Tb.settolerance(0.01);
	std::cout << "print new tolerance:  " << Tb.gettolerance() << std::endl;
	std::cout << "print minimum difference between coordinates:  " << Tb.getmindiff() << std::endl;
	std::cout << "change minimum difference between coordinates to 0.003:  " << std::endl;
	Tb.setmindiff(0.003);
	std::cout << "print new minimum difference between coordinates:  " << Tb.getmindiff() << std::endl;
	std::cout << std::endl << std::endl;



	std::cout << "Print the sixth domain (constructor default, shape = Box<2>, NDIMP = 2):  " <<std::endl;
	std::cout << Bb <<std::endl;
	std::cout << "origin of the object: " << std::endl;
	std::cout << "(" << Bb.orig(0) <<" , " << Bb.orig(1) << ")" <<std::endl;
	std::cout << "scaling factor:  " << std::endl;
	std::cout << "(" << Bb.scal(0) <<" , " << Bb.scal(1) << ")" <<std::endl;
	//**************added
	std::cout << "size of origin coordiate:  " << std::endl;
	std::cout << Bb.getoriginsize() <<std::endl;
	std::cout << "size of scaling factor coordiate:  " << std::endl;
	std::cout << Bb.getscalingsize() <<std::endl;
	std::cout << "physical dimension size:  " << std::endl;
	std::cout << Bb.getdp() <<std::endl;
	std::cout << "search dimension size:  " << std::endl;
	std::cout << Bb.getdt() <<std::endl;

	std::cout << "print tolerance:  " << Bb.gettolerance() << std::endl;
	std::cout << "change tolerance to 0.02:  " << std::endl;
	Bb.settolerance(0.02);
	std::cout << "print new tolerance:  " << Bb.gettolerance() << std::endl;
	std::cout << "print minimum difference between coordinates:  " << Bb.getmindiff() << std::endl;
	std::cout << "change minimum difference between coordinates to 0.005:  " << std::endl;
	Bb.setmindiff(0.005);
	std::cout << "print new minimum difference between coordinates:  " << Bb.getmindiff() << std::endl;
	std::cout << std::endl << std::endl;



	std::cout << "Print the seventh domain (constructor from coordinates (x from 0 to 9, y from 1 to 10, z from 2 to 11), shape = Box<3>, NDIMP = 3):  " <<std::endl;
	std::cout << Bc <<std::endl;
	std::cout << "origin of the object: " << std::endl;
	std::cout << "(" << Bc.orig(0) <<" , " << Bc.orig(1) <<" , " << Bc.orig(2) << ")" <<std::endl;
	std::cout << "scaling factor:  " << std::endl;
	std::cout << "(" << Bc.scal(0) <<" , " << Bc.scal(1) << " , " << Bc.scal(2) << ")" <<std::endl;
	//**************added
	std::cout << "size of origin coordiate:  " << std::endl;
	std::cout << Bc.getoriginsize() <<std::endl;
	std::cout << "size of scaling factor coordiate:  " << std::endl;
	std::cout << Bc.getscalingsize() <<std::endl;
	std::cout << "physical dimension size:  " << std::endl;
	std::cout << Bc.getdp() <<std::endl;
	std::cout << "search dimension size:  " << std::endl;
	std::cout << Bc.getdt() <<std::endl;

	std::cout << "print tolerance:  " << Bc.gettolerance() << std::endl;
	std::cout << "change tolerance to 0.02:  " << std::endl;
	Bc.settolerance(0.02);
	std::cout << "print new tolerance:  " << Bc.gettolerance() << std::endl;
	std::cout << "print minimum difference between coordinates:  " << Bc.getmindiff() << std::endl;
	std::cout << "change minimum difference between coordinates to 0.006:  " << std::endl;
	Bc.setmindiff(0.006);
	std::cout << "print new minimum difference between coordinates:  " << Bc.getmindiff() << std::endl;
	std::cout << std::endl << std::endl;




	std::cout << "Print the eigthth domain (constructor default, shape = Box<3>, NDIMP = 3):  " <<std::endl;
	std::cout << Bd <<std::endl;
	std::cout << "origin of the object: " << std::endl;
	std::cout << "(" << Bd.orig(0) <<" , " << Bd.orig(1) <<" , " << Bd.orig(2) << ")" <<std::endl;
	std::cout << "scaling factor:  " << std::endl;
	std::cout << "(" << Bd.scal(0) <<" , " << Bd.scal(1) << " , " << Bd.scal(2) << ")" <<std::endl;
	//**************added
	std::cout << "size of origin coordiate:  " << std::endl;
	std::cout << Bd.getoriginsize() <<std::endl;
	std::cout << "size of scaling factor coordiate:  " << std::endl;
	std::cout << Bd.getscalingsize() <<std::endl;
	std::cout << "physical dimension size:  " << std::endl;
	std::cout << Bd.getdp() <<std::endl;
	std::cout << "search dimension size:  " << std::endl;
	std::cout << Bd.getdt() <<std::endl;
	
	std::cout << "print tolerance:  " << Bd.gettolerance() << std::endl;
	std::cout << "change tolerance to 0.01:  " << std::endl;
	Bd.settolerance(0.01);
	std::cout << "print new tolerance:  " << Bd.gettolerance() << std::endl;
	std::cout << "print minimum difference between coordinates:  " << Bd.getmindiff() << std::endl;
	std::cout << "change minimum difference between coordinates to 0.003:  " << std::endl;
	Bd.setmindiff(0.003);
	std::cout << "print new minimum difference between coordinates:  " << Bd.getmindiff() << std::endl;
	std::cout << std::endl << std::endl;

	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}

}
}


extern "C"{
void Test_TreeNode_c(int *n){
	
	try{
	
	Point a(1,2,1,1); //Point with Id, bcId and coordinates
	Point b(2,3,3,1); //Point with Id, bcId and coordinates
	Point c(3,4,2,2); //Point with Id, bcId and coordinates
	std::vector<Point> vec{a,b,c};
	Triangle<3> triangle(1, vec);
	std::vector<int> key{3,2,1};
	std::vector<int> key2{1,2,3}; //used below to set new key

	std::vector<Real> coord{0,1,2,3}; //used below to set new coord
	// {100, 24, 35, 21}; ************doesn't validate xmin, ymin, xmax, ymax?!?!
	std::vector<Real> coord1 {1,1,4,3};
	// {4,3,1,1};  ************doesn't validate xmin, ymin, xmax, ymax?!?!
	std::vector<Real> coord2 {1,1,1,4,3,5};
	// {4,3,5,1,1,1}; ************doesn't validate xmin, ymin, xmax, ymax?!?!
	std::vector<Real> coord3{2,2,2,3,7,8}; //used below to set new coord
	// ************doesn't validate xmin, ymin, xmax, ymax?!?!
	Box<2> tmp;
	Box<3> tmp2;
	Box<2> ba(coord1);
	Box<3> bb(coord2);

	TreeNode<Box<2>> treea; //1st
	TreeNode<Triangle<3>> treeb(1, triangle, key); //2nd
	TreeNode<Box<2>> treec(2, ba, key); //3rd
	TreeNode<Box<3>> treed(3, bb, key); //4th
	TreeNode<Box<3>> treee; //5th

	std::cout << "Print the first TreeNode (constructor default, NDIMP = 2):  " <<std::endl;
	treea.print(std::cout);
	std::cout << "father of the treenode: " << std::endl;
	std::cout << treea.getfather() <<std::endl;
	std::cout << "change father to 3: " << std::endl;
	treea.setfather(3);
	std::cout << treea.getfather() <<std::endl;
	std::cout << "left child of the treenode:  " << std::endl;
	std::cout << treea.getchild(0) <<std::endl;
	std::cout << "change left child of the treenode to 1:  " << std::endl;
	treea.setchild(0,1);
	std::cout << treea.getchild(0) <<std::endl;
	std::cout << "right child of the treenode:  " << std::endl;
	std::cout << treea.getchild(1) <<std::endl;
	std::cout << "change right child of the treenode to 5:  " << std::endl;
	treea.setchild(1,5);
	std::cout << treea.getchild(1) <<std::endl;
	std::cout << "Box coordinates of the treenode:  " << std::endl;
	std::cout << "Min_Point:  ( " << treea.getcoord(0) << " , " << treea.getcoord(1) << " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treea.getcoord(2) << " , " << treea.getcoord(3) << " )" <<std::endl;
	std::cout << "change the coordinates to {0,1,2,3}:  " << std::endl;
	treea.setcoords(coord);
	std::cout << "Min_Point:  ( " << treea.getcoord(0) << " , " << treea.getcoord(1) << " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treea.getcoord(2) << " , " << treea.getcoord(3) << " )" <<std::endl;
	std::cout << "id of the treenode:  " << std::endl;
	std::cout << treea.getid() <<std::endl;
	std::cout << "change id of the treenode to 10:  " << std::endl;
	treea.setid(10);
	std::cout << treea.getid() <<std::endl;
	std::cout << "keys child of the treenode:  " << std::endl;
	for (size_t i=0; i<(treea.getkeys()).size(); ++i) //***********changed from UInt to size_t
		std::cout<< treea.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "change keys of the treenode to {1,2,3}:  " << std::endl;
	treea.setkeys(key2);
	for (size_t i=0; i<(treea.getkeys()).size(); ++i)
		std::cout<< treea.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "get Box:  " << std::endl;
	tmp = treea.getbox();
	tmp.print(std::cout);



	std::cout << "Print the second TreeNode (constructor from Triangle<3> Points a(1,2,1,1), b(2,3,3,1), c(3,4,2,2), NDIMP = 2):  " <<std::endl;
	treeb.print(std::cout);
	std::cout << "father of the treenode: " << std::endl;
	std::cout << treeb.getfather() <<std::endl;
	std::cout << "change father: " << std::endl;
	treeb.setfather(3);
	std::cout << treeb.getfather() <<std::endl;
	std::cout << "left child of the treenode:  " << std::endl;
	std::cout << treeb.getchild(0) <<std::endl;
	std::cout << "change left child of the treenode:  " << std::endl;
	treeb.setchild(0,1);
	std::cout << treeb.getchild(0) <<std::endl;
	std::cout << "right child of the treenode:  " << std::endl;
	std::cout << treeb.getchild(1) <<std::endl;
	std::cout << "change right child of the treenode:  " << std::endl;
	treeb.setchild(1,5);
	std::cout << treeb.getchild(1) <<std::endl;
	std::cout << "Box coordinates of the treenode:  " << std::endl;
	std::cout << "Min_Point:  ( " << treeb.getcoord(0) << " , " << treeb.getcoord(1) << " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treeb.getcoord(2) << " , " << treeb.getcoord(3) << " )" <<std::endl;
	std::cout << "change the coordinates:  " << std::endl;
	treeb.setcoords(coord);
	std::cout << "Min_Point:  ( " << treeb.getcoord(0) << " , " << treeb.getcoord(1) << " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treeb.getcoord(2) << " , " << treeb.getcoord(3) << " )" <<std::endl;
	std::cout << "id of the treenode:  " << std::endl;
	std::cout << treeb.getid() <<std::endl;
	std::cout << "change id of the treenode:  " << std::endl;
	treeb.setid(10);
	std::cout << treeb.getid() <<std::endl;
	std::cout << "keys child of the treenode:  " << std::endl;
	for (size_t i=0; i<(treeb.getkeys()).size(); ++i)
		std::cout<< treeb.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "change keys of the treenode:  " << std::endl;
	treeb.setkeys(key2);
	for (size_t i=0; i<(treeb.getkeys()).size(); ++i)
		std::cout<< treeb.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "get Box:  " << std::endl;
	tmp = treeb.getbox();
	tmp.print(std::cout);



	std::cout << "Print the third TreeNode (constructor from Box<2>, {1,1,4,3}, NDIMP = 2):  " <<std::endl;
	treec.print(std::cout);
	std::cout << "father of the treenode: " << std::endl;
	std::cout << treec.getfather() <<std::endl;
	std::cout << "change father: " << std::endl;
	treec.setfather(3);
	std::cout << treec.getfather() <<std::endl;
	std::cout << "left child of the treenode:  " << std::endl;
	std::cout << treec.getchild(0) <<std::endl;
	std::cout << "change left child of the treenode:  " << std::endl;
	treec.setchild(0,1);
	std::cout << treec.getchild(0) <<std::endl;
	std::cout << "right child of the treenode:  " << std::endl;
	std::cout << treec.getchild(1) <<std::endl;
	std::cout << "change right child of the treenode:  " << std::endl;
	treec.setchild(1,5);
	std::cout << treec.getchild(1) <<std::endl;
	std::cout << "Box coordinates of the treenode:  " << std::endl;
	std::cout << "Min_Point:  ( " << treec.getcoord(0) << " , " << treec.getcoord(1) << " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treec.getcoord(2) << " , " << treec.getcoord(3) << " )" <<std::endl;
	std::cout << "change the coordinates:  " << std::endl;
	treec.setcoords(coord);
	std::cout << "Min_Point:  ( " << treec.getcoord(0) << " , " << treec.getcoord(1) << " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treec.getcoord(2) << " , " << treec.getcoord(3) << " )" <<std::endl;
	std::cout << "id of the treenode:  " << std::endl;
	std::cout << treec.getid() <<std::endl;
	std::cout << "change id of the treenode:  " << std::endl;
	treec.setid(10);
	std::cout << treec.getid() <<std::endl;
	std::cout << "keys child of the treenode:  " << std::endl;
	for (size_t i=0; i<(treec.getkeys()).size(); ++i)
		std::cout<< treec.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "change keys of the treenode:  " << std::endl;
	treec.setkeys(key2);
	for (size_t i=0; i<(treec.getkeys()).size(); ++i)
		std::cout<< treec.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "get Box:  " << std::endl;
	tmp = treec.getbox();
	tmp.print(std::cout);



	std::cout << "Print the fourth TreeNode (constructor from Box<3> {1,1,1,4,3,5}, NDIMP = 3):  " <<std::endl;
	treed.print(std::cout);
	std::cout << "father of the treenode: " << std::endl;
	std::cout << treed.getfather() <<std::endl;
	std::cout << "change father: " << std::endl;
	treed.setfather(3);
	std::cout << treed.getfather() <<std::endl;
	std::cout << "left child of the treenode:  " << std::endl;
	std::cout << treed.getchild(0) <<std::endl;
	std::cout << "change left child of the treenode:  " << std::endl;
	treed.setchild(0,1);
	std::cout << treed.getchild(0) <<std::endl;
	std::cout << "right child of the treenode:  " << std::endl;
	std::cout << treed.getchild(1) <<std::endl;
	std::cout << "change right child of the treenode:  " << std::endl;
	treed.setchild(1,5);
	std::cout << treed.getchild(1) <<std::endl;
	std::cout << "Box coordinates of the treenode:  " << std::endl;
	std::cout << "Min_Point:  ( " << treed.getcoord(0) << " , " << treed.getcoord(1) << " , " << treed.getcoord(2)<< " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treed.getcoord(3) << " , " << treed.getcoord(4)<< " , " << treed.getcoord(5) << " )" <<std::endl;
	std::cout << "change the coordinates to {2,2,2,3,7,8}:  " << std::endl;
	treed.setcoords(coord3);
	std::cout << "Min_Point:  ( " << treed.getcoord(0) << " , " << treed.getcoord(1) << " , " << treed.getcoord(2)<< " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treed.getcoord(3) << " , " << treed.getcoord(4)<< " , " << treed.getcoord(5) << " )" <<std::endl;
	std::cout << "id of the treenode:  " << std::endl;
	std::cout << treed.getid() <<std::endl;
	std::cout << "change id of the treenode:  " << std::endl;
	treed.setid(10);
	std::cout << treed.getid() <<std::endl;
	std::cout << "keys child of the treenode:  " << std::endl;
	for (size_t i=0; i<(treed.getkeys()).size(); ++i)
		std::cout<< treed.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "change keys of the treenode:  " << std::endl;
	treed.setkeys(key2);
	for (size_t i=0; i<(treed.getkeys()).size(); ++i)
		std::cout<< treed.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "get Box:  " << std::endl;
	tmp2 = treed.getbox();
	tmp2.print(std::cout);



	std::cout << "Print the fifth TreeNode (constructor default, NDIMP = 3):  " <<std::endl;
	treee.print(std::cout);
	std::cout << "father of the treenode: " << std::endl;
	std::cout << treee.getfather() <<std::endl;
	std::cout << "change father: " << std::endl;
	treee.setfather(3);
	std::cout << treee.getfather() <<std::endl;
	std::cout << "left child of the treenode:  " << std::endl;
	std::cout << treee.getchild(0) <<std::endl;
	std::cout << "change left child of the treenode:  " << std::endl;
	treee.setchild(0,1);
	std::cout << treee.getchild(0) <<std::endl;
	std::cout << "right child of the treenode:  " << std::endl;
	std::cout << treee.getchild(1) <<std::endl;
	std::cout << "change right child of the treenode:  " << std::endl;
	treee.setchild(1,5);
	std::cout << treee.getchild(1) <<std::endl;
	std::cout << "Box coordinates of the treenode:  " << std::endl;
	std::cout << "Min_Point:  ( " << treee.getcoord(0) << " , " << treee.getcoord(1) << " , " << treee.getcoord(2)<< " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treee.getcoord(3) << " , " << treee.getcoord(4)<< " , " << treee.getcoord(5) << " )" <<std::endl;
	std::cout << "change the coordinates:  " << std::endl;
	treee.setcoords(coord3);
	std::cout << "Min_Point:  ( " << treee.getcoord(0) << " , " << treee.getcoord(1) << " , " << treee.getcoord(2)<< " )" <<std::endl;
	std::cout << "Max_Point:  ( " << treee.getcoord(3) << " , " << treee.getcoord(4)<< " , " << treee.getcoord(5) << " )" <<std::endl;
	std::cout << "id of the treenode:  " << std::endl;
	std::cout << treee.getid() <<std::endl;
	std::cout << "change id of the treenode:  " << std::endl;
	treee.setid(10);
	std::cout << treee.getid() <<std::endl;
	std::cout << "keys child of the treenode:  " << std::endl;
	for (size_t i=0; i<(treee.getkeys()).size(); ++i)
		std::cout<< treee.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "change keys of the treenode:  " << std::endl;
	treee.setkeys(key2);
	for (size_t i=0; i<(treee.getkeys()).size(); ++i)
		std::cout<< treee.getkeys()[i] <<" - ";
	std::cout<<std::endl;
	std::cout << "get Box:  " << std::endl;
	tmp2 = treee.getbox();
	tmp2.print(std::cout);

	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}	
}
}

extern "C"{
void Test_TreeHeader_c(int *n){
	
	try{
	std::vector<std::vector<Real>> coord;
	coord.resize(2);
	for (int i = 0; i < 2; i++)
	{
		coord[i].resize(10);
		for(int j = 0; j < 10; j++)
			coord[i][j] = i+j;	
	}
	// 0 1 2 3 4 5 6 7 8 9
	// 1 2 3 4 5 6 7 8 9 10

	std::vector<std::vector<Real>> coord2;
	coord2.resize(3);
	for (int i = 0; i < 3; i++)
	{
		coord2[i].resize(10);
		for(int j = 0; j < 10; j++)
			coord2[i][j] = i+j;
	}
	// 0 1 2 3 4 5 6 7 8  9
	// 1 2 3 4 5 6 7 8 9  10
	// 2 3 4 5 6 7 8 9 10 11

	Domain<Triangle<3>> mydomb(coord);
	Domain<Box<2>> mydomd(coord);
	Domain<Box<3>> mydomf(coord2);


	Tree_Header<Triangle<3>> THa; //1st
	Tree_Header<Triangle<3>> THb = createtreeheader(10, 0, mydomb); //2nd
	Tree_Header<Box<2>> THc; //3rd
	Tree_Header<Box<2>> THd = createtreeheader(8,0,mydomd); //4th
	Tree_Header<Box<3>> THe; //5th
	Tree_Header<Box<3>> THf = createtreeheader(6,0,mydomf); //6th
	//Tree_Header(int const & ntree, int const & nk, Domain<T> const & d); constructor is used within createtreeheader

	std::cout << "Print the first tree_header (constructor default, shape = Triangle<3>):  " <<std::endl;
	std::cout << THa <<std::endl;
	std::cout << "number of tree memory locations: " << std::endl;
	std::cout  << THa.gettreeloc() <<std::endl;
	std::cout << "change number of tree memory locations to 3: " << std::endl;
	THa.settreeloc(3);
	std::cout  << THa.gettreeloc() <<std::endl;
	std::cout << "number of tree levels: " << std::endl;
	std::cout  << THa.gettreelev() <<std::endl;
	std::cout << "change number of tree levels to 4: " << std::endl;
	THa.settreelev(4);
	std::cout  << THa.gettreelev() <<std::endl;
	std::cout << "physical dimension: " << std::endl;
	std::cout  << THa.getndimp() <<std::endl;
	std::cout << "search dimension: " << std::endl;
	std::cout  << THa.getndimt() <<std::endl;
	std::cout << "number of pieces of information carried: " << std::endl;
	std::cout  << THa.getnkey() <<std::endl;
	std::cout << "number of location currently used: " << std::endl;
	std::cout  << THa.getnele() <<std::endl;
	std::cout << "change number of location currently used to 2: " << std::endl;
	THa.setnele(2);
	std::cout  << THa.getnele() <<std::endl;
	std::cout << "number of next available location: " << std::endl;
	std::cout  << THa.getiava() <<std::endl;
	std::cout << "change number of next available location to 3: " << std::endl;
	THa.setiava(3);
	std::cout  << THa.getiava() <<std::endl;
	std::cout << "number next available location in the tree free store: " << std::endl;
	std::cout  << THa.getiend() <<std::endl;
	std::cout << "change number next available location in the tree free store to 4: " << std::endl;
	THa.setiend(4);
	std::cout  << THa.getiend() <<std::endl;
	std::cout << "origin of the domain bbox:  " << std::endl;
	std::cout << "(" << THa.domainorig(0) <<" , " << THa.domainorig(1)  << ")" <<std::endl;
	std::cout << "scaling factor of the domain bbox:  " << std::endl;
	std::cout << "(" << THa.domainscal(0) <<" , " << THa.domainscal(1)  << ")" <<std::endl;
	std::cout << std::endl << std::endl;
	

	std::cout << "Print the second tree_header (constructor from domain " << mydomb << " shape = Triangle<3>):  " <<std::endl;
	std::cout << THb <<std::endl;
	std::cout << "number of tree memory locations: " << std::endl;
	std::cout  << THb.gettreeloc() <<std::endl;
	std::cout << "change number of tree memory locations: " << std::endl;
	THb.settreeloc(3);
	std::cout  << THb.gettreeloc() <<std::endl;
	std::cout << "number of tree levels: " << std::endl;
	std::cout  << THb.gettreelev() <<std::endl;
	std::cout << "change number of tree levels: " << std::endl;
	THb.settreelev(4);
	std::cout  << THb.gettreelev() <<std::endl;
	std::cout << "physical dimension: " << std::endl;
	std::cout  << THb.getndimp() <<std::endl;
	std::cout << "search dimension: " << std::endl;
	std::cout  << THb.getndimt() <<std::endl;
	std::cout << "number of pieces of information carried: " << std::endl;
	std::cout  << THb.getnkey() <<std::endl;
	std::cout << "number of location currently used: " << std::endl;
	std::cout  << THb.getnele() <<std::endl;
	std::cout << "change number of location currently used: " << std::endl;
	THb.setnele(2);
	std::cout  << THb.getnele() <<std::endl;
	std::cout << "number of next available location: " << std::endl;
	std::cout  << THb.getiava() <<std::endl;
	std::cout << "change number of next available location: " << std::endl;
	THb.setiava(3);
	std::cout  << THb.getiava() <<std::endl;
	std::cout << "number next available location in the tree free store: " << std::endl;
	std::cout  << THb.getiend() <<std::endl;
	std::cout << "change number next available location in the tree free store: " << std::endl;
	THb.setiend(4);
	std::cout  << THb.getiend() <<std::endl;
	std::cout << "origin of the domain bbox:  " << std::endl;
	std::cout << "(" << THb.domainorig(0) <<" , " << THb.domainorig(1)  << ")" <<std::endl;
	std::cout << "scaling factor of the domain bbox:  " << std::endl;
	std::cout << "(" << THb.domainscal(0) <<" , " << THb.domainscal(1)  << ")" <<std::endl;
	std::cout << std::endl << std::endl;


	std::cout << "Print the third tree_header (constructor default, shape = Box<2>):  " <<std::endl;
	std::cout << THc <<std::endl;
	std::cout << "number of tree memory locations: " << std::endl;
	std::cout  << THc.gettreeloc() <<std::endl;
	std::cout << "change number of tree memory locations: " << std::endl;
	THc.settreeloc(3);
	std::cout  << THc.gettreeloc() <<std::endl;
	std::cout << "number of tree levels: " << std::endl;
	std::cout  << THc.gettreelev() <<std::endl;
	std::cout << "change number of tree levels: " << std::endl;
	THc.settreelev(4);
	std::cout  << THc.gettreelev() <<std::endl;
	std::cout << "physical dimension: " << std::endl;
	std::cout  << THc.getndimp() <<std::endl;
	std::cout << "search dimension: " << std::endl;
	std::cout  << THc.getndimt() <<std::endl;
	std::cout << "number of pieces of information carried: " << std::endl;
	std::cout  << THc.getnkey() <<std::endl;
	std::cout << "number of location currently used: " << std::endl;
	std::cout  << THc.getnele() <<std::endl;
	std::cout << "change number of location currently used: " << std::endl;
	THc.setnele(2);
	std::cout  << THc.getnele() <<std::endl;
	std::cout << "number of next available location: " << std::endl;
	std::cout  << THc.getiava() <<std::endl;
	std::cout << "change number of next available location: " << std::endl;
	THc.setiava(3);
	std::cout  << THc.getiava() <<std::endl;
	std::cout << "number next available location in the tree free store: " << std::endl;
	std::cout  << THc.getiend() <<std::endl;
	std::cout << "change number next available location in the tree free store: " << std::endl;
	THc.setiend(4);
	std::cout  << THc.getiend() <<std::endl;
	std::cout << "origin of the domain bbox:  " << std::endl;
	std::cout << "(" << THc.domainorig(0) <<" , " << THc.domainorig(1)  << ")" <<std::endl;
	std::cout << "scaling factor of the domain bbox:  " << std::endl;
	std::cout << "(" << THc.domainscal(0) <<" , " << THc.domainscal(1)  << ")" <<std::endl;
	std::cout << std::endl << std::endl;


	std::cout << "Print the fourth tree_header (constructor from domain " << mydomd << " shape = Box<2>):  " <<std::endl;
	std::cout << THd <<std::endl;
	std::cout << "number of tree memory locations: " << std::endl;
	std::cout  << THd.gettreeloc() <<std::endl;
	std::cout << "change number of tree memory locations: " << std::endl;
	THd.settreeloc(3);
	std::cout  << THd.gettreeloc() <<std::endl;
	std::cout << "number of tree levels: " << std::endl;
	std::cout  << THd.gettreelev() <<std::endl;
	std::cout << "change number of tree levels: " << std::endl;
	THd.settreelev(4);
	std::cout  << THd.gettreelev() <<std::endl;
	std::cout << "physical dimension: " << std::endl;
	std::cout  << THd.getndimp() <<std::endl;
	std::cout << "search dimension: " << std::endl;
	std::cout  << THd.getndimt() <<std::endl;
	std::cout << "number of pieces of information carried: " << std::endl;
	std::cout  << THd.getnkey() <<std::endl;
	std::cout << "number of location currently used: " << std::endl;
	std::cout  << THd.getnele() <<std::endl;
	std::cout << "change number of location currently used: " << std::endl;
	THd.setnele(2);
	std::cout  << THd.getnele() <<std::endl;
	std::cout << "number of next available location: " << std::endl;
	std::cout  << THd.getiava() <<std::endl;
	std::cout << "change number of next available location: " << std::endl;
	THd.setiava(3);
	std::cout  << THd.getiava() <<std::endl;
	std::cout << "number next available location in the tree free store: " << std::endl;
	std::cout  << THd.getiend() <<std::endl;
	std::cout << "change number next available location in the tree free store: " << std::endl;
	THd.setiend(4);
	std::cout  << THd.getiend() <<std::endl;
	std::cout << "origin of the domain bbox:  " << std::endl;
	std::cout << "(" << THd.domainorig(0) <<" , " << THd.domainorig(1)  << ")" <<std::endl;
	std::cout << "scaling factor of the domain bbox:  " << std::endl;
	std::cout << "(" << THd.domainscal(0) <<" , " << THd.domainscal(1)  << ")" <<std::endl;
	std::cout << std::endl << std::endl;


	std::cout << "Print the fifth tree_header (constructor default, shape = Box<3>):  " <<std::endl;
	std::cout << THe <<std::endl;
	std::cout << "number of tree memory locations: " << std::endl;
	std::cout  << THe.gettreeloc() <<std::endl;
	std::cout << "change number of tree memory locations: " << std::endl;
	THe.settreeloc(3);
	std::cout  << THe.gettreeloc() <<std::endl;
	std::cout << "number of tree levels: " << std::endl;
	std::cout  << THe.gettreelev() <<std::endl;
	std::cout << "change number of tree levels: " << std::endl;
	THe.settreelev(4);
	std::cout  << THe.gettreelev() <<std::endl;
	std::cout << "physical dimension: " << std::endl;
	std::cout  << THe.getndimp() <<std::endl;
	std::cout << "search dimension: " << std::endl;
	std::cout  << THe.getndimt() <<std::endl;
	std::cout << "number of pieces of information carried: " << std::endl;
	std::cout  << THe.getnkey() <<std::endl;
	std::cout << "number of location currently used: " << std::endl;
	std::cout  << THe.getnele() <<std::endl;
	std::cout << "change number of location currently used: " << std::endl;
	THe.setnele(2);
	std::cout  << THe.getnele() <<std::endl;
	std::cout << "number of next available location: " << std::endl;
	std::cout  << THe.getiava() <<std::endl;
	std::cout << "change number of next available location: " << std::endl;
	THe.setiava(3);
	std::cout  << THe.getiava() <<std::endl;
	std::cout << "number next available location in the tree free store: " << std::endl;
	std::cout  << THe.getiend() <<std::endl;
	std::cout << "change number next available location in the tree free store: " << std::endl;
	THe.setiend(4);
	std::cout  << THe.getiend() <<std::endl;
	std::cout << "origin of the domain bbox:  " << std::endl;
	std::cout << "(" << THe.domainorig(0) <<" , " << THe.domainorig(1) <<" , " << THe.domainorig(2) << ")" <<std::endl;
	std::cout << "scaling factor of the domain bbox:  " << std::endl;
	std::cout << "(" << THe.domainscal(0) <<" , " << THe.domainscal(1) << " , " << THe.domainscal(2)  << ")" <<std::endl;
	std::cout << std::endl << std::endl;


	std::cout << "Print the sixth tree_header (constructor from domain " << mydomf << " shape = Triangle<3>):  " <<std::endl;
	std::cout << THf <<std::endl;
	std::cout << "number of tree memory locations: " << std::endl;
	std::cout  << THf.gettreeloc() <<std::endl;
	std::cout << "change number of tree memory locations: " << std::endl;
	THf.settreeloc(3);
	std::cout  << THf.gettreeloc() <<std::endl;
	std::cout << "number of tree levels: " << std::endl;
	std::cout  << THf.gettreelev() <<std::endl;
	std::cout << "change number of tree levels: " << std::endl;
	THf.settreelev(4);
	std::cout  << THf.gettreelev() <<std::endl;
	std::cout << "physical dimension: " << std::endl;
	std::cout  << THf.getndimp() <<std::endl;
	std::cout << "search dimension: " << std::endl;
	std::cout  << THf.getndimt() <<std::endl;
	std::cout << "number of pieces of information carried: " << std::endl;
	std::cout  << THf.getnkey() <<std::endl;
	std::cout << "number of location currently used: " << std::endl;
	std::cout  << THf.getnele() <<std::endl;
	std::cout << "change number of location currently used: " << std::endl;
	THf.setnele(2);
	std::cout  << THf.getnele() <<std::endl;
	std::cout << "number of next available location: " << std::endl;
	std::cout  << THf.getiava() <<std::endl;
	std::cout << "change number of next available location: " << std::endl;
	THf.setiava(3);
	std::cout  << THf.getiava() <<std::endl;
	std::cout << "number next available location in the tree free store: " << std::endl;
	std::cout  << THf.getiend() <<std::endl;
	std::cout << "change number next available location in the tree free store: " << std::endl;
	THf.setiend(4);
	std::cout  << THf.getiend() <<std::endl;
	std::cout << "origin of the domain bbox:  " << std::endl;
	std::cout << "(" << THf.domainorig(0) <<" , " << THf.domainorig(1)  << " , " << THf.domainorig(2) << ")" <<std::endl;
	std::cout << "scaling factor of the domain bbox:  " << std::endl;
	std::cout << "(" << THf.domainscal(0) <<" , " << THf.domainscal(1) << " , " << THf.domainscal(2)  << ")" <<std::endl;
	std::cout << std::endl << std::endl;


	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}	
}
}


extern "C"{
void Test_ADTree1_c(int *n){
	
	try{
		//costruisco una mesh semplice a mano salvata come quella che serve al costruttore
	UInt num_nodes = 9;
	UInt num_triangle = 8;
	Real points[] = {0., 0.5, 1., 0.,  0.5, 1.,  0., 0.5, 1.,
					 0., 0.,  0., 0.5, 0.5, 0.5, 1., 1.,  1.}; //total 18
	UInt triangle[] = {0, 0, 1, 1, 3, 3, 4, 4,
					   4, 1, 5, 2, 7, 4, 8, 5,
					   3, 4, 4, 5, 6, 7, 7, 8}; //total 24

	std::vector<Real> coord = {0.3,0.3,0.3,0.6,0.6,0.3};
	std::vector<int> keys(0);	
	std::vector<Real> coord2;
	std::vector<int> key2;
	Id id, id2;
	std::vector<Real> region1 = {0.5,0.5,0.5,0.5};
	std::vector<Real> region2 = {1.,1.,1.,1.};
	std::vector<Real> region3 = {0.3,0.3, 0.3,0.3};
	std::vector<Real> region4 = {3,3, 3,3};
	std::set<int> found;
	int loc;

	Tree_Header<Box<2>> THb;
	Tree_Header<Box<3>> THc;
	Tree_Header<Triangle<3>> THd;

	//only possible for triangle to have this kind of constructor
	ADTree<Triangle<3>> ADTa(points, triangle, num_nodes, num_triangle);   //constructor from 2Dmesh, 1st
	ADTree<Box<2>> ADTb(THb);				          //constructor from header, 2nd
	ADTree<Box<3>> ADTc(THc);					//constructor from header, 3rd
	ADTree<Triangle<3>> ADTd(THd);				//constructor from header, 4th
	ADTree<Triangle<3>> ADTe;					//default constructor, 5th

/* the simple mesh is:
	 ___ ___
	|  /|  /|
	| / | / |
	|/__|/__|
	|  /|  /|
	| / | / |
	|/__|/__|

	nodes are numbered:
	6 7 8
	3 4 5
	0 1 2

	triangle are numbered:
	 ___ ___
	|4 /|6 /|
	| /5| /7|
	|/__|/__|
	|0 /|2 /|
	| /1| /3|
	|/__|/__|



*/ 

	std::cout << std::endl << std::endl;
	std::cout << "Print the first ADTree (construct from 2D mesh, Shape = Triangle<3>):  " <<std::endl;
	std::cout << ADTa <<std::endl;
	std::cout << "print Tree_Header:  " <<std::endl;
	std::cout << ADTa.gettreeheader() <<std::endl;
	std::cout << "print number of nodes (location) occupied:  " <<std::endl;
	std::cout << "tree head + " << (ADTa.gettreeheader()).getnele() << " tree nodes" <<std::endl;
	std::cout << "treenodes visualize as a vector:  " << std::endl;
	for (int i = 0; i < (ADTa.gettreeheader()).getnele()+1; i++)
	(ADTa.gettreenode(i)).print(std::cout);
	std::cout << "visualize information about a node, for example node number 5: " << std::endl;
	ADTa.gettri(5, key2, coord2, id);
	std::cout << "coordinate:  " ;
	for (size_t i = 0; i < coord2.size(); i++)
		std::cout << " - " << coord2[i] << " - ";
	std::cout << std::endl;
	for (size_t i = 0; i < key2.size(); i++)
		std::cout << " - " << key2[i] << " - ";
	std::cout << std::endl;
	std::cout << "Id :  " << id << std::endl;
	std::cout << "treenode:  " << std::endl;
	(ADTa.gettreenode(5)).print(std::cout);
	std::cout << "get box coord: " << std::endl;
	std::cout << "( " << ADTa.pointcoord(5+1, 0) << " , " << ADTa.pointcoord(5, 1) << " )" << std::endl;
	std::cout << "( " << ADTa.pointcoord(5+1, 2) << " , " << ADTa.pointcoord(5, 3) << " )" <<std::endl;
	std::cout << "get id: " << std::endl;
	std::cout <<  ADTa.pointId(5) <<std::endl <<std::endl;
	std::cout << "search point (0.5,0.5):  " <<std::endl;
	std::cout << ADTa.search(region1, found) << std::endl;
	for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
  	 std::cout << " - " << *i << " - ";
	(ADTa.gettreenode(*i)).print(std::cout);
	}

	std::cout << "search point (1,1):  " <<std::endl;
	std::cout << ADTa.search(region2, found) << std::endl;
	for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
  	 std::cout << " - " << *i << " - ";
	(ADTa.gettreenode(*i)).print(std::cout);
	}
	std::cout << "search point (0.3,0.3):  " <<std::endl;
	std::cout << ADTa.search(region3, found) << std::endl;
	for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
  	 std::cout << " - " << *i << " - ";
	(ADTa.gettreenode(*i)).print(std::cout);
	}
	std::cout << "search point (3,3):  " <<std::endl;
	std::cout << ADTa.search(region4, found) << std::endl;
	for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
  	 std::cout << " - " << *i << " - ";
	(ADTa.gettreenode(*i)).print(std::cout);
	}

	std::cout << "add and visualize a treenode: " << std::endl;
	loc = ADTa.addtreenode(100, coord, keys);
	std::cout << loc <<std::endl;
	std::cout << "treenode:  " << std::endl;
	(ADTa.gettreenode(loc)).print(std::cout);
	std::cout << "father treenode:  " << std::endl;
	loc = (ADTa.gettreenode(loc)).getfather();
	(ADTa.gettreenode(loc)).print(std::cout);
	std::cout << "print all the treenodes as a vector:  " << std::endl;
	for (int i = 0; i < (ADTa.gettreeheader()).getnele()+2; i++)
	(ADTa.gettreenode(i)).print(std::cout);

	ADTa.deltreenode(3);
	std::cout << "print all the treenodes as a vector after deleting node number 3:  " << std::endl;
	for (int i = 0; i < (ADTa.gettreeheader()).getnele()+2; i++)
	(ADTa.gettreenode(i)).print(std::cout);
	std::cout << std::endl << std::endl;




	// std::cout << "******************************************* " << std::endl;
	// std::cout << "Print the second ADTree (construct from header, Shape = Box<2>):  " <<std::endl;
	// std::cout << ADTb <<std::endl;
	// std::cout << "print number of nodes (location) occupied:  " <<std::endl;
	// std::cout << "tree head + " << (ADTb.gettreeheader()).getnele() << " tree nodes" <<std::endl;
	// std::cout << "treenodes as a vector:  " << std::endl;
	// for (int i = 0; i < (ADTb.gettreeheader()).getnele()+1; i++)
	// (ADTb.gettreenode(i)).print(std::cout);
	// std::cout << std::endl << std::endl;



	// std::cout << "******************************************* " << std::endl;
	// std::cout << "Print the third ADTree (construct from header, Shape = Box<3>):  " <<std::endl;
	// std::cout << ADTc <<std::endl;
	// std::cout << "print number of nodes (location) occupied:  " <<std::endl;
	// std::cout << "tree head + " << (ADTc.gettreeheader()).getnele() << " tree nodes" <<std::endl;
	// std::cout << "treenodes as a vector:  " << std::endl;
	// for (int i = 0; i < (ADTc.gettreeheader()).getnele()+1; i++)
	// (ADTc.gettreenode(i)).print(std::cout);
	// std::cout << std::endl << std::endl;



	// std::cout << "******************************************* " << std::endl;
	// std::cout << "Print the fourth ADTree (construct from header, Shape = Triangle<3>):  " <<std::endl;
	// std::cout << ADTd <<std::endl;
	// std::cout << "print number of nodes (location) occupied:  " <<std::endl;
	// std::cout << "tree head + " << (ADTd.gettreeheader()).getnele() << " tree nodes" <<std::endl;
	// std::cout << "treenodes as a vector:  " << std::endl;
	// for (int i = 0; i < (ADTd.gettreeheader()).getnele()+1; i++)
	// (ADTd.gettreenode(i)).print(std::cout);
	// std::cout << std::endl << std::endl;



	// std::cout << "******************************************* " << std::endl;
	// std::cout << "Print the fifth ADTree (construct default, Shape = Triangle<3>):  " <<std::endl;
	// std::cout << ADTe <<std::endl;
	// std::cout << "print number of nodes (location) occupied:  " <<std::endl;
	// std::cout << "tree head + " << (ADTe.gettreeheader()).getnele() << " tree nodes" <<std::endl;
	// std::cout << "treenodes as a vector:  " << std::endl;
	// for (int i = 0; i < (ADTe.gettreeheader()).getnele()+1; i++)
	// (ADTe.gettreenode(i)).print(std::cout);
	// std::cout << std::endl << std::endl;


	// std::cout << "******************************************* " << std::endl;
	// ADTe = ADTa;
	// std::cout << "ADTree operator = (from the first ADTree, Shape = Triangle<3>):  " <<std::endl;
	// std::cout << ADTe <<std::endl;
	// std::cout << "print number of nodes (location) occupied:  " <<std::endl;
	// std::cout << "tree head + " << (ADTe.gettreeheader()).getnele() << " tree nodes" <<std::endl;
	// std::cout << "treenodes as a vector:  " << std::endl;
	// for (int i = 0; i < (ADTe.gettreeheader()).getnele()+2; i++)
	// (ADTe.gettreenode(i)).print(std::cout);
	// std::cout << std::endl << std::endl;


	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}	
}
}


extern "C"{
void Test_ADTree2_c(int *n){
	
	try{
	//costruisco una mesh semplice a mano salvata come quella che serve al costruttore
	UInt num_nodes = 25;
	UInt num_triangle = 32;
	Real points[] = {0., 0.25, 0.5, 0.75, 1., 0.,   0.25, 0.5,  0.75,  1.,   0.,  0.25, 0.5, 0.75, 1.,  0.,   0.25, 0.5,  0.75, 1.,   0., 0.25, 0.5, 0.75, 1.,
					 0., 0.,   0.,  0,    0,  0.25, 0.25, 0.25, 0.25,  0.25, 0.5, 0.5,  0.5, 0.5,  0.5, 0.75, 0.75, 0.75, 0.75, 0.75, 1,  1.,   1.,  1.,   1}; //total 25*2=50
	UInt triangle[] = {0, 0, 1, 1, 2, 2, 3, 3, 5,   5, 6,  6,  7, 7,  8,  8,  10, 10, 11, 11, 12, 12, 13, 13, 15, 15, 16, 16, 17, 17, 18, 18,
					   5, 1, 6, 2, 7, 3, 8, 4, 10,  6, 11, 7, 12, 8,  13, 9,  15, 11, 16, 12, 17, 13, 18, 14, 20, 16, 21, 17, 22, 18, 23, 19,
					   6, 6, 7, 7, 8, 8, 9, 9, 11, 11, 12, 12,13, 13, 14, 14, 16, 16, 17, 17, 18, 18, 19, 19, 21, 21, 22, 22, 23, 23, 24, 24}; //total 32*3=96

	std::vector<Real> coord = {0.3,0.3,0.3,0.6,0.6,0.3};
	std::vector<int> keys(0);	
	std::vector<Real> coord2;
	std::vector<int> key2;
	Id id, id2;
	std::vector<Real> region1 = {0.5,0.5,0.5,0.5};
	std::vector<Real> region2 = {1.,1.,1.,1.};
	std::vector<Real> region3 = {0.3,0.3, 0.3,0.3};
	std::vector<Real> region4 = {3,3, 3,3};
	std::set<int> found;
	int loc;

	Tree_Header<Box<2>> THb;
	Tree_Header<Box<3>> THc;
	Tree_Header<Triangle<3>> THd;

	//only possible for triangle to have this kind of constructor
	ADTree<Triangle<3>> ADTa(points, triangle, num_nodes, num_triangle);   //constructor from 2Dmesh, 1st
	ADTree<Box<2>> ADTb(THb);				          //constructor from header, 2nd
	ADTree<Box<3>> ADTc(THc);					//constructor from header, 3rd
	ADTree<Triangle<3>> ADTd(THd);				//constructor from header, 4th
	ADTree<Triangle<3>> ADTe;					//default constructor, 5th

/* the simple mesh is:
	 ___ ___ ___ ___
	|  /|  /|  /|  /|
	| / | / | / | / |
	|/__|/__|/__|/__|
	|  /|  /|  /|  /|
	| / | / | / | / |
	|/__|/__|/__|/__|
	|  /|  /|  /|  /|
	| / | / | / | / |
	|/__|/__|/__|/__|
	|  /|  /|  /|  /|
	| / | / | / | / |
	|/__|/__|/__|/__|


	nodes are numbered:
	20 21 22 23 24
	15 16 17 18 19
	10 11 12 13 14
	5  6  7  8  9
	0  1  2  3  4

	triangle are numbered:
	 ___ ___ ___ ___
	|24/|26/|28/|30/|
	| / | / | / | / |
	|/25|/27|/29|/31|
	|16/|18/|20/|22/|
	| / | / | / | / |
	|/17|/19|/21|/23|
	|8 /|10/|12/|14/|
	| / | / | / | / |
	|/_9|/11|/13|/15|
	|0 /|2 /|4 /|6 /|
	| / | / | / | / |
	|/_1|/_3|/_5|/_7|



*/ 

	std::cout << std::endl << std::endl;
	std::cout << "Print the first ADTree (construct from 2D mesh, Shape = Triangle<3>):  " <<std::endl;
	std::cout << ADTa <<std::endl;
	std::cout << "print Tree_Header:  " <<std::endl;
	std::cout << ADTa.gettreeheader() <<std::endl;
	std::cout << "print number of nodes (location) occupied:  " <<std::endl;
	std::cout << "tree head + " << (ADTa.gettreeheader()).getnele() << " tree nodes" <<std::endl;
	std::cout << "treenodes visualize as a vector:  " << std::endl;
	for (int i = 0; i < (ADTa.gettreeheader()).getnele()+1; i++)
	(ADTa.gettreenode(i)).print(std::cout);
	std::cout << "visualize information about a node, for example node number 5: " << std::endl;
	ADTa.gettri(5, key2, coord2, id);
	std::cout << "coordinate:  " ;
	for (size_t i = 0; i < coord2.size(); i++)
		std::cout << " - " << coord2[i] << " - ";
	std::cout << std::endl;
	for (size_t i = 0; i < key2.size(); i++)
		std::cout << " - " << key2[i] << " - ";
	std::cout << std::endl;
	std::cout << "Id :  " << id << std::endl;
	std::cout << "treenode:  " << std::endl;
	(ADTa.gettreenode(5)).print(std::cout);
	std::cout << "get box coord: " << std::endl;
	std::cout << "( " << ADTa.pointcoord(5+1, 0) << " , " << ADTa.pointcoord(5, 1) << " )" << std::endl;
	std::cout << "( " << ADTa.pointcoord(5+1, 2) << " , " << ADTa.pointcoord(5, 3) << " )" <<std::endl;
	std::cout << "get id: " << std::endl;
	std::cout <<  ADTa.pointId(5) <<std::endl <<std::endl;


	// std::cout << "search point (0.5,0.5):  " <<std::endl;
	// std::cout << ADTa.search(region1, found) << std::endl;
	// for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
 //  	 std::cout << " - " << *i << " - ";
	// (ADTa.gettreenode(*i)).print(std::cout);
	// }

	// std::cout << "search point (1,1):  " <<std::endl;
	// std::cout << ADTa.search(region2, found) << std::endl;
	// for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
 //  	 std::cout << " - " << *i << " - ";
	// (ADTa.gettreenode(*i)).print(std::cout);
	// }
	// std::cout << "search point (0.3,0.3):  " <<std::endl;
	// std::cout << ADTa.search(region3, found) << std::endl;
	// for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
 //  	 std::cout << " - " << *i << " - ";
	// (ADTa.gettreenode(*i)).print(std::cout);
	// }
	// std::cout << "search point (3,3):  " <<std::endl;
	// std::cout << ADTa.search(region4, found) << std::endl;
	// for (std::set<int>::iterator i = found.begin(); i != found.end(); i++) {
 //  	 std::cout << " - " << *i << " - ";
	// (ADTa.gettreenode(*i)).print(std::cout);
	// }

	// std::cout << "add and visualize a treenode: " << std::endl;
	// loc = ADTa.addtreenode(100, coord, keys);
	// std::cout << loc <<std::endl;
	// std::cout << "treenode:  " << std::endl;
	// (ADTa.gettreenode(loc)).print(std::cout);
	// std::cout << "father treenode:  " << std::endl;
	// loc = (ADTa.gettreenode(loc)).getfather();
	// (ADTa.gettreenode(loc)).print(std::cout);
	// std::cout << "print all the treenodes as a vector:  " << std::endl;
	// for (int i = 0; i < (ADTa.gettreeheader()).getnele()+2; i++)
	// (ADTa.gettreenode(i)).print(std::cout);

	// ADTa.deltreenode(3);
	// std::cout << "print all the treenodes as a vector after deleting node number 3:  " << std::endl;
	// for (int i = 0; i < (ADTa.gettreeheader()).getnele()+2; i++)
	// (ADTa.gettreenode(i)).print(std::cout);
	// std::cout << std::endl << std::endl;


	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}	
}
}


extern "C"{
void Test_MeshHandler_c(int *n){
	
	try{
	//costruisco una mesh semplice a mano salvata come quella che serve al costruttore
	Real points[] = {0., 0.5, 1.,  0., 0.5,  1.,  0., 0.5, 1., 
					 0., 0.,  0., 0.5, 0.5,  0.5, 1., 1.,  1.};
	UInt triangle[] = {0,0,1,1,3,3,4,4,
					   4,1,5,2,7,4,8,5,
					   3,4,4,5,6,7,7,8};
	UInt * edge;
	UInt * neighbors;
	UInt num_nodes = 9;
	UInt num_triangle = 8;
	UInt num_edges = 16;
	std::vector<Real> coord = {0.3,0.3,0.3,0.6,0.6,0.3};
	Point point1(0.5,0.5);
	Point point2(1.,1.);
	Point point3(0.8,0.3);
	Point point4(4.,4.);


/* the simple mesh is:
	 ___ ___
	|  /|  /|
	| / | / |
	|/__|/__|
	|  /|  /|
	| / | / |
	|/__|/__|

	nodes are numbered:
	6 7 8
	3 4 5
	0 1 2

	triangle are numbered:
	 ___ ___
	|4 /|6 /|
	| /5| /7|
	|/__|/__|
	|0 /|2 /|
	| /1| /3|
	|/__|/__|



*/ 
	MeshHandler<1> mesh(points, edge, triangle, neighbors, num_nodes, num_edges, num_triangle, 1);
	Triangle<3> res;

	std::cout << "Triangle<3> mesh: " << std::endl;
	mesh.printPoints(std::cout);
	mesh.printTriangles(std::cout);
	std::cout << "find point 1: (0.5,0.5)   " << std::endl;
	res = mesh.findLocationTree(point1);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
/*	std::cout << "find location naive: "<<std::endl;
	res = mesh.findLocationNaive(point1);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
*/

	std::cout << "find point 1: (1.,1.)   " << std::endl;
	res = mesh.findLocationTree(point2);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
/*	std::cout << "find location naive: "<<std::endl;
	res = mesh.findLocationNaive(point2);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
*/
	std::cout << "find point 1: (0.8,0.3)   " << std::endl;
	res = mesh.findLocationTree(point3);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
/*	std::cout << "find location naive: "<<std::endl;
	res = mesh.findLocationNaive(point3);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
*/
	std::cout << "find point 1: (4.,4.)   " << std::endl;
	res = mesh.findLocationTree(point4);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
/*	std::cout << "find location naive: "<<std::endl;
	res = mesh.findLocationNaive(point4);
	res.print(std::cout);
	res[0].print(std::cout);
	std::cout << std::endl; 
	res[1].print(std::cout);
	std::cout << std::endl;
	res[2].print(std::cout);
	std::cout << std::endl;
	std::cout <<std::endl << std::endl;
*/
//	MeshHandler<2> mesh2(points, edge, triangle, neighbors, num_nodes, num_edges, num_triangle, 1);
//	Triangle<6> res2;

	delete[] edge;
	delete[] neighbors;
	*n = 0;
	}
	catch(...)
	{
	std::cout <<"Exception caugth " << std::endl;
	*n = 1;	
	}	
}
}







