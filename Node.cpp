#include<string>
#include "Node.h"

Node::Node() : word(""),synonym(""),defination(""), left(NULL), right(NULL)
{
}

Node::Node(string word, string synonym, string defination) : word(word),synonym(synonym),defination(defination), left(NULL), right(NULL){}




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

void Node::printWord()
{
	cout << word << " ";
}
