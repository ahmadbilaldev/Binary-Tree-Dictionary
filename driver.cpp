#include <iostream>
#include "Tree.h"
using namespace std;

int main() 
{
	Tree t1;
	Node* node1=new Node("Muhammad");
	Node* node2 = new Node("Bilal");
	Node* node3 = new Node("Faisal");
	Node* node4 = new Node("Zaheer");
	Node* node5 = new Node("Dawood");
	Node* node6 = new Node("Abdullah");
	Node* node7 = new Node("Emad"); 
	Node* node8 = new Node("Krona");
	Node* node9 = new Node("Saad");  
	t1.insert(node1).insert(node2).insert(node3).insert(node4).insert(node5).insert(node6).insert(node7).insert(node8).insert(node9);
	t1.printInfixOrder();
	system("pause");
}