#pragma once
#include <string>
#include <iostream>

using namespace std;

class Node
{
private:
	string word,synonym;
	bool bookmark;

public:
	Node* left, * right;
	Node();
	Node(string word);
	void setWord(string word);
	void setSynonym(string synOfWord);
	void editWord(string s1);
	string getWord();
	void setBookMark();
	bool checkMarked();
	void printWord();
};
