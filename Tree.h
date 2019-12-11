#pragma once
#include "Node.h"
#include <iostream>
using namespace std;


class Tree
{
	Node* root;
	int count;

public:
	Tree();
	Tree(Node*& ptr);
	bool isEmpty();
	bool isNotEmpty();
	void insert(Node*& ptr);
	void printInfixOrder();
	Node* search(Node*& ptr);
	~Tree();
};
