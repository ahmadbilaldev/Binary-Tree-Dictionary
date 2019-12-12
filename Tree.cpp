#include "Tree.h"
#include <string>
#include <fstream>

Tree::Tree() : root(NULL), count(0)
{
}

Tree::Tree(Node *&ptr) : root(ptr), count(1)
{
	ptr = root->leftptr = root->rightptr = NULL;
}

bool Tree::isEmpty()
{
	if (!root)
		return true;
	else
		return false;
}

bool Tree::isNotEmpty()
{
	if (!root)
		return false;
	else
		return true;
}

Tree &Tree::insert(string word, string synonym, string defination)
{
	Node *ptr = new Node(word, synonym, defination);
	if (!root)
	{
		root = ptr;
		++count;
		return *this;
	}
	else
	{
		Node *rptr, *bptr;
		bptr = NULL;
		rptr = root;
		while (rptr)
		{
			bptr = rptr;
			if (rptr->getWord() < ptr->getWord())
				rptr = rptr->rightptr;
			else
				rptr = rptr->leftptr;
		}

		if (bptr->getWord() < ptr->getWord())
			bptr->rightptr = ptr;
		else
			bptr->leftptr = ptr;
	}
	ptr = ptr->leftptr = ptr->rightptr = NULL;
	++count;
	return *this;
}

void Tree::printInfixOrder()
{
	void prtInfixOrder(Node * root);

	if (!root)
		cout << "\nEmpty Tree\n";
	else
	{

		cout << left << setw(30);
		cout << "Words";
		cout << setw(30);
		cout << "Synonyms";
		cout << setw(30);
		cout << "Definitions";
		cout << endl;
		prtInfixOrder(root);
		cout << endl;
	}
}

void prtInfixOrder(Node *root)
{
	if (root)
	{
		prtInfixOrder(root->leftptr);
		root->printWord();
		prtInfixOrder(root->rightptr);
	}
}

Tree::~Tree()
{
	void deleteNodes(Node * root);
	if (root)
		deleteNodes(root);
}

void deleteNodes(Node *root)
{
	if (root)
	{
		deleteNodes(root->leftptr);
		deleteNodes(root->rightptr);
		delete root;
	}
}
Node *Tree::removeWord(string word)
{
	Node *ptr, *temp;
	ptr = root;
	temp = NULL;

	if (!ptr)
	{
		cout << "The tree is empty thus returning NULL" << endl;
		return NULL;
	}

	while (ptr)
	{
		if (ptr->getWord() == word)
		{
			Node *rptr = ptr;
			if (!ptr->leftptr)
			{
				if (!temp)
				{
					root = rptr->rightptr;
				}
				else if (temp->leftptr == rptr)
				{
					temp->leftptr = rptr->rightptr;
				}
				else
				{
					temp->rightptr = rptr->rightptr;
				}
				rptr->rightptr = rptr->leftptr = NULL;
			}
			else if (!ptr->rightptr)
			{
				if (!temp)
				{
					root = rptr->leftptr;
				}
				else if (temp->leftptr == rptr)
				{
					temp->leftptr = rptr->leftptr;
				}
				else
				{
					temp->rightptr = rptr->leftptr;
				}
				rptr->rightptr = rptr->leftptr = NULL;
			}
			else
			{
				ptr = ptr->rightptr;
				while (ptr->leftptr)
				{
					ptr = ptr->leftptr;
				}
				ptr->leftptr = rptr->leftptr;
				if (!temp)
				{
					root = rptr->rightptr;
				}
				else if (temp->leftptr == rptr)
				{
					temp->leftptr = rptr->leftptr;
				}
				else
				{
					temp->rightptr = rptr->leftptr;
				}
				rptr->rightptr = rptr->leftptr = NULL;
			}
			--count;
			return rptr;
		}
		temp = ptr;
		if (ptr->getWord() > word)
		{
			ptr = ptr->leftptr;
		}
		else
		{
			ptr = ptr->rightptr;
		}
	}
	return NULL;
}

void Tree::editWord(string existWord, string newWord)
{
	Node *nptr = removeWord(existWord);
	if (nptr)
	{
		nptr->editWord(newWord);
		insert(nptr->getWord(), nptr->getSynonym(), nptr->getDefinition());
	}
}

void Tree::setBookMark(string s1)
{
	Node *ptr = search(s1);
	if (ptr)
	{
		ptr->setBookMark();
	}
}

void Tree::printMarked()
{
	void prtMarked(Node * &root);
	if (root)
	{
		prtMarked(root);
	}
}

void prtMarked(Node *&root)
{
	if (root)
	{
		prtMarked(root->leftptr);
		if (root->getMarked())
		{
			root->printWord();
		}
		prtMarked(root->rightptr);
	}
}

Node *Tree::search(string s1)
{
	if (isNotEmpty())
	{
		Node *rptr = root;
		while (rptr)
		{
			if (rptr->getWord() == s1)
				return rptr;
			if (rptr->getWord() < s1)
				rptr = rptr->rightptr;
			else
				rptr = rptr->leftptr;
		}
	}
	cout << "The Word you are trying to search does not appear to be in the Dictionay" << endl;
	return NULL;
}

void Tree::writeToFile(ofstream &outFile)
{

	void toFile(Node * root, ofstream & outFile);

	if (root)
	{
		toFile(root, outFile);
	}
}

void toFile(Node *root, ofstream &outFile)
{
	if (root)
	{
		toFile(root->leftptr, outFile);
		root->writeToFile(outFile);
		toFile(root->rightptr, outFile);
	}
}

bool Tree::logIn(ifstream& inFile)
{
	string userFile, passFile, userInput, passInput;
	cout << "Enter the UserName\n";
	cin >> userInput;
	cout << "Enter the Password\n";
	cin >> passInput;
	bool logIn = false;
	while (!(inFile.eof()))
	{
		getline(inFile, userFile);
		getline(inFile, passFile);
		if ((userFile == userInput) && (passFile == passInput))
		{
			logIn = true;
		}
	}
	inFile.close();
	if (logIn) cout << "Access Verified\n";
	else cout << "Access Denied\n";
	return logIn;

}