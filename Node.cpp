#include <iostream>
#include <iomanip>
#include <string>
#include "Node.h"

Node::Node() : data(NULL), left(NULL), right(NULL)
{
}

Node::Node(string data) : data(data), left(NULL), right(NULL)
{
}

/*
 * Main setter function
 */
void Node::setWord(string data)
{
	this->data = data;
}

void Node::setLeft(string data)
{
	left->setWord(data);
}

void Node::setRight(string data)
{
	right->setWord(data);
}

void Node::Print()
{
	cout << setw(14) << data << endl;
}
