#ifndef TREE_H
#define TREE_H
#include "Node.cpp"

class Tree
{
	Node *root;
	int count;

public:
	Tree();
	Tree(Node *&ptr);
	bool isEmpty();
	bool isNotEmpty();
	void insert(Node *&ptr);
	void printPreOrder();
	void printPostOrder();
	void printInfixOrder();
	Node *search(Node *&ptr);
	void deleteNode(Node *&ptr);
	int getMaxDegree();
	~Tree();
};
#endif
