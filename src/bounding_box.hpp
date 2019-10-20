
#ifndef BOUNDING_BOX_HPP_
#define BOUNDING_BOX_HPP_


#include "FEMr.hpp"
#include "mesh_objects.hpp"

/*#include "intersection.hpp" */

/**	\class Box
 * 	\brief Policy used when boxes have to be stored in the tree.
 */
/**
 *	\template parameter NDIMP is the physical dimension: 2 -> 2D, 3 -> 3D
*/
template<int NDIMP>
class Box {
protected:
	/** A vector of rectangle corner coordinates.
	 * 	First NDIMP values are the coordinates of the rectangle corner with minimum coordinates,
	 *  followed by the coordinates of the opposite corner.
	 */
	std::vector<Real> x_;
public:
	/**	Default constructor.
	 *
	 *	It's fundamental in creating a vector of Box objects.
	 *  Sets coordinate values to zero.
	 */
	Box();
	/**	Another constructor.
	 *
	 *	\param[in] coord Pointer to an array containing input coordinates.
	 *					 Make sure that its size is equal to the size of
	 *					 protected member x_.
	 */
	Box(std::vector<Real> const & coord);

/**	Another constructor.
	 *
	 *	\param[in] a 2D Triangle
	 *					 Make sure that NDIMP = 2.

 * it's possible create new constructor for the new element that we may need (for example 3D Triangle or Tetrahedron)
	 */
	template <UInt NNODES>
	Box(Triangle<NNODES> const & triangle);
	/// Returns the i-th coordinate value.
	inline Real operator[](int const & i) { return x_[i]; }
	inline Real operator[](int const & i) const { return x_[i]; }
	/// Returns the number of physical space dimension.
	inline static constexpr int dp() { return NDIMP; }
	/// Returns the number of dimensions used for the search (2*NDIMP).
	inline static constexpr int dt() { return 2*NDIMP; }
	/// Returns the size of coordinate array.
	inline static constexpr int coordsize() { return 2*NDIMP; }
	/** Sets coordinate values.
	 *
	 *	\param[in] data Pointer to an array containing new coordinates.
	 *					Make sure that its size is equal to the size of
	 *					protected member x.
	 */
	void set(std::vector<Real> const & data);
	/** print the two bbox point
	* specialized for NDIMP = 2,3
	*/
	void print(std::ostream & out) const;
};

#include "bounding_box_imp.hpp"

#endif /* BOUNDING_BOX_HPP_ */
