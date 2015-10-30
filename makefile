a.out: main.cpp BinaryTreeNode.h BinaryTree.h
	g++ -std=c++11 main.cpp

clean:
	rm a.out

