#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Node
{
private:
	bool bookmark;
	string word,synonym,definition;

public:
	Node* leftptr, * rightptr;
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
