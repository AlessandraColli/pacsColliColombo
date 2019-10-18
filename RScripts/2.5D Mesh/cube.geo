Mesh.MshFileVersion = 2.2;

h = 0.3;

Point(1) = {0, 0, 0, h};
Point(2) = {5, 0, 0, h};
Point(3) = {5, 5, 0, h};
Point(4) = {0, 5, 0, h};
Point(5) = {0, 0, 5, h};
Point(6) = {5, 0, 5, h};
Point(7) = {5, 5, 5, h};
Point(8) = {0, 5, 5, h};

Point(9) = {1, 1, 0, h};
Point(10) = {3, 1, 0, h};
Point(11) = {3, 3, 0, h};
Point(12) = {1, 3, 0, h};

Point(13) = {1, 1, 5, h};
Point(14) = {3, 1, 5, h};
Point(15) = {3, 3, 5, h};
Point(16) = {1, 3, 5, h};

Point(17) = {5, 1, 1, h};
Point(18) = {5, 3, 1, h};
Point(19) = {5, 3, 3, h};
Point(20) = {5, 1, 3, h};


Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Line(5) = {5, 8};
Line(6) = {8, 7};
Line(7) = {7, 6};
Line(8) = {6, 5};
Line(9) = {1, 5};
Line(10) = {2, 6};
Line(11) = {3, 7};
Line(12) = {4, 8};
Line(13) = {5, 1};
Line(14) = {6, 2};
Line(15) = {7, 3};
Line(16) = {8, 4};

Line(18) = {9, 10};
Line(19) = {10, 11};
Line(20) = {11, 12};
Line(21) = {12, 9};

Line(22) = {13, 14};
Line(23) = {14, 15};
Line(24) = {15, 16};
Line(25) = {16, 13};

Line(26) = {17, 18};
Line(27) = {18, 19};
Line(28) = {19, 20};
Line(29) = {20, 17};


Line Loop(1) = {1,2,3,4,18,19,20,21};
Line Loop(2) = {5,6,7,8,22,23,24,25};
Line Loop(3) = {1,10,8,13};
Line Loop(4) = {2,11,7,14,26,27,28,29};
Line Loop(5) = {3,12,6,15};
Line Loop(6) = {4,9,5,16};
Line Loop(7) = {18,19,20,21};
Line Loop(8) = {22,23,24,25};
Line Loop(9) = {26,27,28,29};


Plane Surface(1) = {1};
Plane Surface(2) = {2};
Plane Surface(3) = {3};
Plane Surface(4) = {4};
Plane Surface(5) = {5};
Plane Surface(6) = {6};
Plane Surface(7) = {7};
Plane Surface(8) = {8};
Plane Surface(9) = {9};

Surface Loop(1) = {1,2,3,4,5,6,7,8,9};
Surface Loop(2) = {7};
Surface Loop(3) = {8};
Surface Loop(4) = {9};

Physical Surface(1) = {1};
Physical Surface(2) = {2};
Physical Surface(3) = {3};
Physical Surface(4) = {4};