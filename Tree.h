#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Tree
{
	Node* root;
	int count;

public:
	Tree();
	Tree(Node*& ptr);
	bool isEmpty();
	bool isNotEmpty();
	Tree& insert(string word, string synonym, string defination);
	void editWord(string existWord, string newWord);
	Node* removeWord(string word);
	void printInfixOrder();
	void setBookMark(string s1);
	void printMarked();
	Node* search(string s1);
	void writeToFile(ofstream& outFile);
	void readFromFile(ifstream& inFile);
	bool logIn(ifstream& InFile);
	void showSynonymAndDefinition(string word);
	void wordOfTheDay();
	~Tree();
};