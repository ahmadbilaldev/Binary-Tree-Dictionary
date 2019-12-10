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
	Node(string data);
	void setWord(string data);
	void setSynonym(string synData);
	void setLeft(string data);
	void setRight(string data);
	void Print();
};
#endif
