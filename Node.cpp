#include<string>
#include "Node.h"

Node::Node() : word(""),synonym(""),definition(""), leftptr(NULL), rightptr(NULL)
{
}

Node::Node(string word, string synonym, string definition) : word(word),synonym(synonym),definition(definition), leftptr(NULL), rightptr(NULL){}




void Node::setWord(string word)
{
	this->word = word;
}

void Node::setSynonym(string synonym)
{
	this->synonym = synonym;
}

void Node::editWord(string s1)
{
	word = s1;
}

string Node::getWord()
{
	return this->word;
}
void Node::setBookMark()
{
	bookmark = true;
}
bool Node::checkMarked()
{
	return bookmark;
}
void Node::printWord()
{
	cout << left << setw(30);
	cout << word;
	cout << setw(30);
	cout << synonym;
	cout << setw(30);
	cout << definition;
	cout << endl;
}


string Node::getSynonym() {
	return synonym;
}

string Node::getDefinition() {
	return defination;
}
