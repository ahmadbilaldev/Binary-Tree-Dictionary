#include <iostream>
#include <fstream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree t1;
	ifstream inFile;
	inFile.open("data.txt");
	if (inFile.is_open())
	{
		t1.readFromFile(inFile);
	}
	else
	{
		cout << "Not Opening file for input";
	}
	t1.printInfixOrder();
	system("pause");
}
