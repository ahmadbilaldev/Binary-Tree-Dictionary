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
	Node* root; //Root of the tree
	int count; //Private data member to record count

public:

	Tree(); //default construtor
	Tree(Node*& ptr); //parameterized constructor
	bool isEmpty(); //To check if the tree is empty
	bool isNotEmpty(); //To Check if the tree is not empty
	Tree& insert(string word, string synonym, string meaning); //To insert a new word in dictionary
	void editWord(string existWord, string newWord); //To edit a existing word in  dictionary
	void editSynonym(string word, string newSynonym); //to edit synonym
	Node* removeWord(string word); //To remove a word from dictionary
	void printInfixOrder(); //To display dictionary
	void setBookMark(string s1); //to set bookmarks
	void printMarked(); //To print book marks
	Node* search(string s1); //To search a word in the dictionary
	void writeToFile(ofstream& outFile); //To write in the file
	void readFromFile(ifstream& inFile); //To read from file
	bool logIn(ifstream& InFile); //To login
	void showSynonymAndMeaning(string word); //To show synonyms and definition of a word
	void wordOfTheDay(); //to show word of the day
	~Tree(); //destructor
};

