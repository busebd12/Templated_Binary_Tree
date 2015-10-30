#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinaryTree<int> myTree;

	BinaryTreeNode<int> *tempRoot=myTree.getRoot();

	tempRoot=myTree.insert(tempRoot,9);

	tempRoot=myTree.insert(tempRoot,10);

	tempRoot=myTree.insert(tempRoot,20);

	tempRoot=myTree.insert(tempRoot,35);

	tempRoot=myTree.insert(tempRoot,8);

	tempRoot=myTree.insert(tempRoot,1);

	cout << "Your tree contains " << myTree.getNumberOfElements() << " elements:" << endl;

	myTree.printPreOrder(tempRoot);

	myTree.deleteNode(tempRoot,35);

	myTree.deleteNode(tempRoot,10);

	myTree.deleteNode(tempRoot,8);

	cout << endl;

	cout << "Now, your tree contains " << myTree.getNumberOfElements() << " elements:" << endl;

	myTree.printPreOrder(tempRoot);

	//cout << "The level order traversal of your tree is:" << endl;
	//myTree.levelOrderTraversal(tempRoot);

	int value;

	cout << endl;

	cout << "Please enter a number you would like to search for in the tree:" << endl;

	cin >> value;

	if(myTree.search(tempRoot,value)==true)
	{
	    cout << "We found " << value << " in the tree" << endl;
	}
	else
	{
	    cout << "We didn't find " << value << " in the tree" << endl;
	}
}