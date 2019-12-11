#include <iostream>
#include "Tree.h"
using namespace std;

int main() 
{
	Tree t1;
	Node* node1=new Node("Ghous");
	t1.insert(node1);
	t1.printInfixOrder();
	system("pause");
}