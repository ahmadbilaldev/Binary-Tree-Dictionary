#include <iostream>
#include <iomanip>
#include <string>
#include "Node.h"

Node::Node() : data(0), left(NULL), right(NULL)
{
}

Node::Node(int data) : data(data), left(NULL), right(NULL)
{
}

void Node::setData(int data)
{
	this->data = data;
}

void Node::setLeft(int data)
{
	left->setData(data);
}

void Node::setRight(int data)
{
	right->setData(data);
}

void Node::Print()
{
	cout << setw(14) << data << endl;
}
