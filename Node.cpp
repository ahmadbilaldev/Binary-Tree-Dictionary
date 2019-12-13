#include <string>
#include <fstream>
#include "Node.h"
//default constructor of node class
Node::Node() : word(""), synonym(""), meaning(""), leftptr(NULL), rightptr(NULL),bookmark(false) {}
//Parametrized Constructor of Node class
Node::Node(string word, string synonym, string meaning) : word(word), synonym(synonym), meaning(meaning), leftptr(NULL), rightptr(NULL),bookmark(false) {}
//Function that is used to set the Data member that Contains the Word
void Node::setWord(string word)
{
	this->word = word;
}
//Function that is used to set the Data member that Contains the meaning of the Word
void Node::setSynonym(string synonym)
{
	this->synonym = synonym;
}
//Function that is used to EDIT an existing word
void Node::editWord(string s1)
{
	word = s1;
}
//Funcion that returns the Word 
string Node::getWord()
{
	return this->word;
}
//Function that sets bookmark for a word
void Node::setBookMark()
{
	bookmark = true;
}
//Function tha tells whether a word has been bookmarked or not
bool Node::getMarked()
{

	return bookmark;
}
//function that is used to output all the data members of a node
void Node::printWord()
{
	cout << left << setw(30);
	cout << word;
	cout << setw(30);
	cout << synonym;
	cout << setw(30);
	cout << meaning;
	cout << endl;
}
//function that returns the synonym if a word
string Node::getSynonym()
{
	return synonym;
}
//function that returns the definition if a word
string Node::getMeaning()
{
	return meaning;
}
//a function that is used to write all the data members of node to a file
void Node::writeToFile(ofstream &outFile)
{
	outFile << word;
	outFile << ",";
	outFile << synonym;
	outFile << ",";
	outFile << meaning << ",";
}
//function that outputs the Synonym of a word
void Node::printSynonym()
{
	cout << synonym;
}
//function that outputs the Definition of a word
void Node::printMeaning()
{
	cout << meaning;
}
//function that outputs the word
void Node::showWord()
{
	cout << word;
}
