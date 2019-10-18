Mesh.MshFileVersion = 2.2;

h = 0.5;

Point(1) = {0, 0, 0, h};
Point(2) = {5, 0, 0, h};
Point(3) = {5, 5, 0, h};
Point(4) = {0, 5, 0, h};
Point(5) = {0, 0, 5, h};
Point(6) = {5, 0, 5, h};
Point(7) = {5, 5, 5, h};
Point(8) = {0, 5, 5, h};

Point(9) = {1, 1, 1, h};
Point(10) = {2, 1, 1, h};
Point(11) = {2, 2, 1, h};
Point(12) = {1, 2, 1, h};
Point(13) = {1, 1, 2, h};
Point(14) = {2, 1, 2, h};
Point(15) = {2, 2, 2, h};
Point(16) = {1, 2, 2, h};

Point(17) = {3, 3, 3, h};
Point(18) = {4, 3, 3, h};
Point(19) = {4, 4, 3, h};
Point(20) = {3, 4, 3, h};
Point(21) = {3, 3, 4, h};
Point(22) = {4, 3, 4, h};
Point(23) = {4, 4, 4, h};
Point(24) = {3, 4, 4, h};

Point(25) = {2.5, 1, 1, h};
Point(26) = {4, 1, 1, h};
Point(27) = {4, 2.5, 1, h};
Point(28) = {2.5, 2.5, 1, h};
Point(29) = {2.5, 1, 2.5, h};
Point(30) = {4, 1, 2.5, h};
Point(31) = {4, 2.5, 2.5, h};
Point(32) = {2.5, 2.5, 2.5, h};


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

Line(17) = {9, 10};
Line(18) = {10, 11};
Line(19) = {11, 12};
Line(20) = {12, 9};
Line(21) = {13, 16};
Line(22) = {16, 15};
Line(23) = {15, 14};
Line(24) = {14, 13};
Line(25) = {9, 13};
Line(26) = {10, 14};
Line(27) = {11, 15};
Line(28) = {12, 16};
Line(29) = {13, 9};
Line(30) = {14, 10};
Line(31) = {15, 11};
Line(32) = {16, 12};

Line(33) = {17, 18};
Line(34) = {18, 19};
Line(35) = {19, 20};
Line(36) = {20, 17};
Line(37) = {21, 24};
Line(38) = {24, 23};
Line(39) = {23, 22};
Line(40) = {22, 21};
Line(41) = {17, 21};
Line(42) = {18, 22};
Line(43) = {19, 23};
Line(44) = {20, 24};
Line(45) = {21, 17};
Line(46) = {22, 18};
Line(47) = {23, 19};
Line(48) = {24, 20};

Line(49) = {25, 26};
Line(50) = {26, 27};
Line(51) = {27, 28};
Line(52) = {28, 25};
Line(53) = {29, 32};
Line(54) = {32, 31};
Line(55) = {31, 30};
Line(56) = {30, 29};
Line(57) = {25, 29};
Line(58) = {26, 30};
Line(59) = {27, 31};
Line(60) = {28, 32};
Line(61) = {29, 25};
Line(62) = {30, 26};
Line(63) = {31, 27};
Line(64) = {32, 28};


Line Loop(1) = {1,2,3,4};
Line Loop(2) = {5,6,7,8};
Line Loop(3) = {1,10,8,13};
Line Loop(4) = {2,11,7,14};
Line Loop(5) = {3,12,6,15};
Line Loop(6) = {4,9,5,16};

Line Loop(7) = {17,18,19,20};
Line Loop(8) = {21,22,23,24};
Line Loop(9) = {17,26,24,29};
Line Loop(10) = {18,27,23,30};
Line Loop(11) = {19,28,22,31};
Line Loop(12) = {20,25,21,32};

Line Loop(13) = {33,34,35,36};
Line Loop(14) = {37,38,39,40};
Line Loop(15) = {33,42,40,45};
Line Loop(16) = {34,43,39,46};
Line Loop(17) = {35,44,38,47};
Line Loop(18) = {36,41,37,48};

Line Loop(19) = {49,50,51,52};
Line Loop(20) = {53,54,55,56};
Line Loop(21) = {49,58,56,61};
Line Loop(22) = {50,59,55,62};
Line Loop(23) = {51,60,54,63};
Line Loop(24) = {52,57,53,64};


Plane Surface(1) = {1};
Plane Surface(2) = {2};
Plane Surface(3) = {3};
Plane Surface(4) = {4};
Plane Surface(5) = {5};
Plane Surface(6) = {6};

Plane Surface(7) = {7};
Plane Surface(8) = {8};
Plane Surface(9) = {9};
Plane Surface(10) = {10};
Plane Surface(11) = {11};
Plane Surface(12) = {12};

Plane Surface(13) = {13};
Plane Surface(14) = {14};
Plane Surface(15) = {15};
Plane Surface(16) = {16};
Plane Surface(17) = {17};
Plane Surface(18) = {18};

Plane Surface(19) = {19};
Plane Surface(20) = {20};
Plane Surface(21) = {21};
Plane Surface(22) = {22};
Plane Surface(23) = {23};
Plane Surface(24) = {24};

Surface Loop(1) = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};
Surface Loop(2) = {7,8,9,10,11,12};
Surface Loop(3) = {13,14,15,16,17,18};
Surface Loop(4) = {19,20,21,22,23,24};

Volume(1) = {1};
Volume(2) = {2};
Volume(3) = {3};
Volume(4) = {4};

Physical Volume(1) = {1};
Physical Volume(2) = {2};
Physical Volume(3) = {3};
Physical Volume(4) = {4};

Coherence;