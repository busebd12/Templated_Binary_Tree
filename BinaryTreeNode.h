#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <iostream>
#include <cstdlib>

//forward delcration since BinaryTree needs access to the private data members of BinaryTreeNode class
template <typename T>
class BinaryTree;

template <typename T>
class BinaryTreeNode
{
	friend class BinaryTree<T>;
	private:
		BinaryTreeNode *leftChild;
		BinaryTreeNode *rightChild;
		T data;
	public:
		BinaryTreeNode(const T Data):data(Data),rightChild(nullptr),leftChild(nullptr) {}

		T getData() const
		{
			return data;
		}

		BinaryTreeNode* getRightChild() const
		{
			return rightChild;
		}

		BinaryTreeNode* getLeftChild() const
		{
			return leftChild;
		}
};
#endif