/**
 *	\file adtree.hpp
 *	\author Cardani Alessandra
 *	\author Pigoli Davide
 *	\author Prada Daniele
 */

#ifndef ADTREE_HPP_
#define ADTREE_HPP_



#include "FEMr.hpp"
#include "tree_header.hpp"
#include "mesh_objects.hpp"
#include "bounding_box.hpp"
#include "domain.hpp"
#include "treenode.hpp"
#include "exception_handling.hpp"


/**	\class ADTree
 * 	\brief Alternating binary range searching tree.
 *	\param Shape: template parameter, the original shape
 */
template<class Shape>
class ADTree {
protected:
  /** The header.
   *
   *  It contains general information about the tree.
   */
  Tree_Header<Shape> header_;
  /// Vector of tree nodes.
  std::vector<TreeNode<Shape> > data_;
  /** \brief Adds a point to the tree.
   * 	It throws:
   * 	<ul>
   * 	<li> a TreeDomainError exception if the point is out of domain;
   * 	<li> a TreeAlloc exception if there is no more space in the tree to add the node;
   * 	<li> a LevRuntimeError if you exceed the limit set for the tree levels due to the inclusion of the node.
   * 	</ul>
   */
  int adtrb(Id shapeid, std::vector<Real> const & coords, std::vector<int> const & keys);
  /// Handles a TreeDomainError exception.
  int handledomerr(Id shapeid, std::vector<Real> const & coords, std::vector<int> const & keys);
  /// Handles a TreeAlloc exception.
  int handletreealloc(Id shapeid, std::vector<Real> const & coords, std::vector<int> const & keys);
  /// Handles a LevRuntimeError exception.
  int handleleverr(Id shapeid, std::vector<Real> const & coords, std::vector<int> const & keys);
  /** Searches dimension associated to a given level.
   *
   * 	\param[in] lev The given level.
   * 	\param[in] dim The number of dimensions used for the search.
   */
  inline int searchdim(int const & lev, int const & dim) const {
    return (lev % dim);
  }
  /** Finds delta associated to division at a given level.
   *
   * 	\param[in] lev The given level.
   * 	\param[in] dim The number of dimensions used for the search.
   */
  inline double delta(int const & lev, int const & dim) const {
    return std::pow(0.5, int(lev/dim)+1);
  }
public:
  /**	A default constructor.
   *
   *	It initializes the tree header and reserve a suitable number of memory
   *	locations to store tree nodes. It doesn't fill the tree.
   */
  ADTree():header_()
	{
 	data_.reserve(header_.gettreeloc()+1);

	std::vector<int> foo_k(header_.getnkey(), 0);
	Shape obj;
	Id id = std::numeric_limits<UInt>::max();
	data_.push_back(TreeNode<Shape>(id,obj, foo_k));
	
	};
  /**	A base constructor.
   *
   *	It initializes the tree header and reserve a suitable number of memory
   *	locations to store tree nodes. It doesn't fill the tree.
   */
  ADTree(Tree_Header<Shape> const & header);
  /** A constructor especially designed for building the tree associated to 2D mesh object, the mesh is formed by Triangle<3/6>.
   *
   *	It fills all the locations of the tree. Object's coordinates are stored to perform
   *	searching operations. 
   *	Template parameter must be equal to Triangle<3>
   * 	see mesh_handler to verify what points and triangle must contatin
   */
  ADTree(Real const * const points, UInt const * const triangle, UInt num_nodes, UInt num_triangle);

  /// Returns a reference to the tree header.
  inline Tree_Header<Shape> gettreeheader() const { return header_; }
  /** Adds a node to the tree.
   * 	It calls the handlers of the exceptions that can be thrown by adtrb().
   *
   * 	\param[in] coords Coordinates of the point.
   *	\param[in] keys Additional informations associated to the point.
   *
   *	The location of the current node in the tree is returned.
   */
  int addtreenode(Id shapeid, std::vector<Real> const & coords, std::vector<int> const & keys);
  /** Gets out the informations stored at a given node.
   *
   * 	\param[in] loc Location of the searched node.
   * 	\param[out] info Additional informations stored in the searched node.
   * 	\param[out] coord Bounding box coordinates of the object stored in the loc-th location.
   */
  inline void gettri(int const & loc, std::vector<int> & info, std::vector<Real> & coord, Id & id);
  /** Gets out the node stored at a given location.
   *
   * 	\param[in] loc Location of the searched node.
   */
  inline TreeNode<Shape> gettreenode(int const & loc) const{return data_[loc];};

  /** Finds all points or (bounding) boxes that intersect a given box.
   *
   * 	\param[in] region Box where searching described by the representative point obtained through a corner transformation.
   * 	\param[out] found Indices of the found elements.
   *
   * 	This function returns true if it has completed successfully, false otherwise.
   */
  bool search(std::vector<Real> const & region, std::set<int> & found)const;
  /// Deletes a specified location in the tree.
  void deltreenode(int const & index);
  /// Gets the j-th coordinate of the bounding box of the p-th object stored in the node.
  inline Real pointcoord(int const & p, int const & j) const { return data_[p].getcoord(j); }
  /// Gets the the Id of the original object of the p-th treenode.
  inline Id pointId (int const & p) const { return data_[p].getid(); }
  /// Outputs informations contained in the tree header.
  template<class S>
  friend std::ostream & operator<<(std::ostream & ostr, ADTree<S> const & myadt);

};

#include "adtree_imp.hpp"

#endif /* ADTREE_HPP_ */
