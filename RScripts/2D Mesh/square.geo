Mesh.MshFileVersion = 2.2;

h = 0.1;

Point(1) = {0, 0, 0, h};
Point(2) = {5, 0, 0, h};
Point(3) = {5, 5, 0, h};
Point(4) = {0, 5, 0, h};
Point(5) = {3, 3, 0, h};
Point(6) = {4, 3, 0, h};
Point(7) = {4, 4, 0, h};
Point(8) = {3, 4, 0, h};
Point(9) = {3.5, 1, 0, h};
Point(10) = {4.5, 1, 0, h};
Point(11) = {4.5, 2, 0, h};
Point(12) = {3.5, 2, 0, h};
Point(13) = {1.5, 1.5, 0, h};
Point(14) = {2.5, 1.5, 0, h};
Point(15) = {1.5, 2.5, 0, h};
Point(16) = {0.5, 1.5, 0, h};
Point(17) = {1.5, 0.5, 0, h};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Line(5) = {5, 6};
Line(6) = {6, 7};
Line(7) = {7, 8};
Line(8) = {8, 5};
Line(9) = {9, 10};
Line(10) = {10, 11};
Line(11) = {11, 12};
Line(12) = {12, 9};

Circle(13) = {14, 13, 15};
Circle(14) = {15, 13, 16};
Circle(15) = {16, 13, 17};
Circle(16) = {17, 13, 14};

Line Loop(1) = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
Line Loop(2) = {5,6,7,8};
Line Loop(3) = {9,10,11,12};
Line Loop(4) = {13,14,15,16};

Plane Surface(1) = {1};
Plane Surface(2) = {2};
Plane Surface(3) = {3};
Plane Surface(4) = {4};

Physical Surface(1) = {1};
Physical Surface(2) = {2};
Physical Surface(3) = {3};
Physical Surface(4) = {4};
