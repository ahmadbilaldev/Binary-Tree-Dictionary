#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Node
{
private:
	//data members of node class required in the dictionary
	bool bookmark;
	string word, synonym, definition;

public:
	//pointers to move towards leaf nodes
	Node *leftptr, *rightptr;
	//default constructor of node class
	Node();
	//Parametrized Constructor of Node class
	Node(string word, string synonym, string defination);
	//Function that is used to set the Data member that Contains the Word
	void setWord(string word);
	//Function that is used to set the Data member that Contains the meaning of the Word
	void setSynonym(string synOfWord);
	//Function that is used to EDIT an existing word
	void editWord(string s1);
	//Function to edit synonym
	void editSynonym(string newSynonym);
	//Funcion that returns the Word 
	string getWord();
	//Function that sets bookmark for a word
	void setBookMark();
	//Function tha tells whether a word has been bookmarked or not
	bool getMarked();
	//function that is used to output all the data members of a node
	void printWord();
	//function that returns the synonym if a word
	string getSynonym();
	//function that returns the definition if a word
	string getDefinition();

	//a function that is used to write all the data members of node to a file
	void writeToFile(ofstream &outFile);
	//function that outputs the Synonym of a word
	void printSynonym();
	//function that outputs the Definition of a word
	void printDefinition();
	//function that outputs the word
	void showWord();
};
