#ifndef Node_H
#define Node_H
#include <fstream>
#include <string>

using namespace std;

class Node
{
private:
	string data;

public:
	Node *left, *right;
	Node();
	Node(int data);
	void setLeft(int data);
	void setRight(int data);
	void Print();
};
#endif
