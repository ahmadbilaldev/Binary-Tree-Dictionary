#ifndef Node_H
#define Node_H
#include <fstream>

using namespace std;

class Node
{
private:
	int Data;
	int Priority;

public:
	Node *left, *right;
	Node();
	Node(int data);
	void Set_Left(int data);
	void Set_Right(int data);
	int Get_Data() const;
	void Set_Data(int data);

	void Print();
};
#endif
