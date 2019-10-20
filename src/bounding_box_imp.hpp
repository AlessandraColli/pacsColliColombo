#ifndef __BOUNDING_BOX_IMP_HPP__
#define __BOUNDING_BOX_IMP_HPP__


template<int NDIMP>
Box<NDIMP>::Box() {
	x_.resize(2*NDIMP);
	for(int i = 0; i < 2*NDIMP; ++i) {
		x_[i] = 0;
	}
}

template<int NDIMP>
Box<NDIMP>::Box(std::vector<Real> const & coord) {
	x_.resize(2*NDIMP);
	for(int i = 0; i < 2*NDIMP; ++i) {
		x_[i] = coord[i];
	}
}
template<int NDIMP>
template <UInt NNODES>
Box<NDIMP>::Box(Triangle<NNODES> const & triangle) {
	if(typeid(NDIMP) != typeid(2)) {
    std::cout << std::endl << std::endl;
    std::cout << "error! Box<NDIMP>::Box(Triangle<NNODES> const & triangle) : bad template parameter" << std::endl << std::endl;
    std::cout << "In order to build the bounding box associated to the triangle" << std::endl;
    std::cout << "template parameter must be equal to '2' and not to " << typeid(NDIMP).name() << std::endl;
    std::exit(EXIT_FAILURE);
  } else {
	x_.resize(4);
	x_[0] = std::min(std::min(triangle[0][0], triangle[1][0]), triangle[2][0]);
	x_[1] = std::min(std::min(triangle[0][1], triangle[1][1]), triangle[2][1]);
	x_[2] = std::max(std::max(triangle[0][0], triangle[1][0]), triangle[2][0]);
	x_[3] = std::max(std::max(triangle[0][1], triangle[1][1]), triangle[2][1]);
  }
}


template<int NDIMP>
void Box<NDIMP>::set(std::vector<Real> const & data) {
	for(int i = 0; i < 2*NDIMP; ++i) {
		x_[i] = data[i];
	}
}


template<int NDIMP>
void Box<NDIMP>::print(std::ostream & out) const
{
	out << "Min_Point:  ( - ";
	for (UInt i=0; i<NDIMP; ++i)
		out<< x_[i] <<" - ";
	out << " ) " << std::endl;
	out << "Max_Point:  ( - ";
	for (UInt i=0; i<NDIMP; ++i)
		out<< x_[i + NDIMP] <<" - ";
	out << " ) " << std::endl;
	out<<std::endl;
}

#endif //__BOUNDING_BOX_IMP_HPP__


