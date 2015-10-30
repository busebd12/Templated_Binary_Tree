#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BinaryTreeNode.h"
template <typename T>
class BinaryTree
{
	private:
		BinaryTreeNode<T> *root;
		int numberOfElements;
	public:
		BinaryTree():root(nullptr),numberOfElements(0) {}

		~BinaryTree()
		{
			if(root!=nullptr)
			{
				delete root->leftChild;

				delete root->rightChild;
			}
		}

		BinaryTreeNode<T>* insert(BinaryTreeNode<T> *root, const T Data)
		{
			BinaryTreeNode<T> *newNode=new BinaryTreeNode<T>(Data);

			if(root==nullptr)
			{
				root=newNode;

				numberOfElements++;
			}
			else if(Data < root->data)
			{
				root->leftChild=insert(root->leftChild, Data);
			}
			else
			{
				root->rightChild=insert(root->rightChild, Data);
			}

			return root;
		}

		BinaryTreeNode<T>* deleteNode(BinaryTreeNode<T> *root, const T Data)
		{
			if(root==nullptr)
			{
				return root;
			}
			else if(Data < root->data)
			{
				root->leftChild=deleteNode(root->leftChild, Data);
			}
			else if(Data > root->data)
			{
				root->rightChild=deleteNode(root->rightChild, Data);
			}
			else
			{
				if(root->rightChild==nullptr && root->leftChild==nullptr)
				{
					root=nullptr;

					delete root;
				}
				else if(root->rightChild==nullptr)
				{
					BinaryTreeNode<T> *temp=root;

					root=root->leftChild;

					delete temp;
				}
				else if(root->leftChild==nullptr)
				{
					BinaryTreeNode<T> *temp=root;

					root=root->rightChild;

					delete temp;
				}
				else
				{
					BinaryTreeNode<T> *temp=findMinimum(root->rightChild);

					root->data=temp->data;

					root->rightChild=deleteNode(root->rightChild, temp->data);
				}
				numberOfElements--;
			}
			return root;
		}

		BinaryTreeNode<T>* findMinimum(BinaryTreeNode<T> *root)
		{
			if(root==nullptr)
			{
				throw std::runtime_error("Can't find the minimum since the tree is empty");
			}

			BinaryTreeNode<T> *current=root;

			while(current!=nullptr)
			{
				current=current->leftChild;
			}

			return current;
		}

		BinaryTreeNode<T>* findMaximum(BinaryTreeNode<T> *root)
		{
			if(root!=nullptr)
			{
				throw std::runtime_error("Can't find the maximum since the tree is empty");
			}

			BinaryTreeNode<T> *current=root;

			while(current!=nullptr)
			{
				current=current->rightChild;
			}

			return current;
		}

		bool search(BinaryTreeNode<T> *root, const T Data)
		{
			if(root==nullptr)
			{
				return false;
			}
			else if(root->data==Data)
			{
				return true;
			}
			else if(Data < root->data)
			{
				return search(root->leftChild, Data);
			}
			else
			{
				return search(root->rightChild, Data);
			}
		}

		BinaryTreeNode<T>* getRoot() const
		{
			return root;
		}

		int getNumberOfElements() const
		{
			return numberOfElements;
		}

		void printPreOrder(BinaryTreeNode<T> *root) const
		{
			if(root!=nullptr)
			{
				std::cout << root->data << std::endl;

				printPreOrder(root->leftChild);

				printPreOrder(root->rightChild);
			}
		}

		void printInOrder(BinaryTreeNode<T>* root) const
		{
			if(root!=nullptr)
			{
				printInOrder(root->leftChild);

				std::cout << root->data << std::endl;

				printInOrder(root->rightChild);
			}
		}

		void printPostOrder(BinaryTreeNode<T> *root) const
		{
			if(root!=nullptr)
			{
				printPostOrder(root->leftChild);

				printPostOrder(root->rightChild);

				std::cout << root->data << std::endl;
			}
		}
};
#endif