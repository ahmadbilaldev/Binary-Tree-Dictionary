#include <iostream>
#include <fstream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree t1;
	Node *node1 = new Node();
	Node *node2 = new Node();
	Node *node3 = new Node();
	Node *node4 = new Node();
	Node *node5 = new Node();
	Node *node6 = new Node();
	Node *node7 = new Node();
	t1.insert("Muhammad", "Praised", "Who speaks by divine inspiration").insert("Bilal", "Muizzen", "A man who").insert("Faisal", "Decider", "A man who decides between two parties");
	t1.insert("Zaheer", "Supporter", "A man who supports").insert("Dawood", "Islamic", "One of the names of Allah");
	t1.insert("Abdullah", "Servant of Allah", "Man who serves Allah").insert("Emad", "Support", "Supportive to everyone");
	t1.printInfixOrder();

	ofstream outFile;
	outFile.open("data.txt");
	if (outFile.is_open())
	{
		cout << "Writing to File";
		t1.writeToFile(outFile);
	}
	else
	{
		cout << "DEBUG: Not writing";
	}

	system("pause");
}
