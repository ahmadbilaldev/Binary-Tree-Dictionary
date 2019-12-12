#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Tree
{
	Node *root;
	int count;

public:
	Tree();
	Tree(Node *&ptr);
	bool isEmpty();
	bool isNotEmpty();
	Tree &insert(string word, string synonym, string defination);
	void editWord(string existWord, string newWord);
	Node *removeWord(string word);
	void printInfixOrder();
	void setBookMark(string s1);
	void printMarked();
	Node *search(string s1);
	bool logIn(string userInput, string passInput, ifstream &InFile);
	void writeToFile(ofstream &outFile);
	~Tree();
};
