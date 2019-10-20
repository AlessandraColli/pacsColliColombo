#ifndef TREENODE_IMP_HPP_
#define TREENODE_IMP_HPP_


template<class T>
void TreeNode<T>::print(std::ostream & out) const
{
	out << "Tree Node   --" << id_ << "--" <<std::endl;
	out << "Father:  " << father_ << std::endl;
	out << "Left Children:  " << children_[0] << std::endl;
	out << "Rigth Children:  " << children_[1] << std::endl;
	out << "Box: ";
	box_.print(std::cout);
	out << std::endl;
	out << "Keys:  - ";
	for (UInt i=0; i<keys_.size(); ++i)
		out<< keys_[i] <<" - ";
	out<<std::endl;
}

#endif /* TREENODE_IMP_HPP_ */
