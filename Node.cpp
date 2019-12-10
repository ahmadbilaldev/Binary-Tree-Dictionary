#include <iostream>
#include <iomanip>
#include "cNode.h"

Node::Node() : Data(0), left(NULL), right(NULL)
{
}

Node::Node(int data) : Data(data), left(NULL), right(NULL)
{
}

void Node::Set_Data(int data)
{
	this->Data = data;
}

void Node::Set_Left(int data)
{
	left->Set_Data(data);
}

void Node::Set_Right(int data)
{
	right->Set_Data(data);
}
int Node::Get_Data() const
{
	return Data;
}

void Node::Print()
{
	cout << setw(14) << Data << endl;
}
