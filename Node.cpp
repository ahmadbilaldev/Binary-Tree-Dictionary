#include<string>
#include "Node.h"

Node::Node() : word(""),synonym(""),defination(""), leftptr(NULL), rightptr(NULL)
{
}

Node::Node(string word, string synonym, string defination) : word(word),synonym(synonym),defination(defination), leftptr(NULL), rightptr(NULL){}




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
bool Node::getMarked()
{
	
	return bookmark;
}
void Node::printWord()
{
	cout << word << " ";
}


string Node::getSynonym() {
	return synonym;
}

string Node::getDefinition() {
	return defination;
}
