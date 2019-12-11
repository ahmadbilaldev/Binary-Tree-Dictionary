#pragma once
#include <string>
#include <iostream>

using namespace std;

class Node
{
private:
	bool bookmark;
	string word,synonym,defination;

public:
	Node* left, * right;
	Node();
	Node(string word, string synonym, string defination);
	void setWord(string word);
	void setSynonym(string synOfWord);
	void editWord(string s1);
	string getWord();
	void setBookMark();
	bool getMarked();
	string getSynonym();
	string getDefinition();
	void printWord();
};
