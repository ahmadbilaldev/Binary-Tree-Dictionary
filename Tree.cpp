#include "Tree.h"
#include<string>


Tree::Tree() : root(NULL),count(0)
{
}

Tree::Tree(Node*& ptr) : root(ptr), count(1)
{
	ptr = root->left = root->right = NULL;
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


Tree& Tree::insert(string word, string synonym, string defination)
{
	Node* ptr = new Node(word, synonym, defination);
	if (!root)
	{
		root = ptr;
		++count;
		return *this;
	}
	else
	{
		Node* rptr, * bptr;
		bptr = NULL;
		rptr = root;
		while (rptr)
		{
			bptr = rptr;
			if (rptr->getWord() < ptr->getWord())
				rptr = rptr->right;
			else
				rptr = rptr->left;
		}

		if (bptr->getWord() < ptr->getWord())
			bptr->right = ptr;
		else
			bptr->left = ptr;
	}
	ptr = ptr->left = ptr->right = NULL;
	++count;
	return* this;
}

void Tree::printInfixOrder()
{
	void prtInfixOrder(Node * root);

	if (!root)
		cout << "\nEmpty Tree\n";
	else
		prtInfixOrder(root);
}

void prtInfixOrder(Node* root)
{
	if (root)
	{
		prtInfixOrder(root->left);
		root->printWord();
		prtInfixOrder(root->right);
	}
}

Tree::~Tree()
{
	void deleteNodes(Node * root);
	if (root)
		deleteNodes(root);
}

void deleteNodes(Node* root)
{
	if (root)
	{
		deleteNodes(root->left);
		deleteNodes(root->right);
		delete root;
	}
}
Node* Tree::removeWord(string word) {
	Node* ptr, * temp;
	ptr = root;
	temp = NULL;

	if (!ptr) {
		cout << "The tree is empty thus returning NULL" << endl;
		return NULL;
	}

	while (ptr) {
		if (ptr->getWord() == word) {
			Node* rptr = ptr;
			if (!ptr->left) {
				if (!temp) {
					root = rptr->right;
				}
				else if (temp->left == rptr) {
					temp->left = rptr->right;
				}
				else {
					temp->right = rptr->right;
				}
				rptr->right = rptr->left = NULL;
			}
			else if (!ptr->right) {
				if (!temp) {
					root = rptr->left;
				}
				else if (temp->left == rptr) {
					temp->left = rptr->left;
				}
				else {
					temp->right = rptr->left;
				}
				rptr->right = rptr->left = NULL;
			}
			else {
				ptr = ptr->right;
				while (ptr->left) {
					ptr = ptr->left;
				}
				ptr->left = rptr->left;
				if (!temp) {
					root = rptr->right;
				}
				else if (temp->left == rptr) {
					temp->left = rptr->left;
				}
				else {
					temp->right = rptr->left;
				}
				rptr->right = rptr->left = NULL;
			}
			--count;
			return rptr;
		}
		temp = ptr;
		if (ptr->getWord() > word) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	return NULL;
}

void Tree::editWord(string existWord,string newWord)
{
	Node* nptr=removeWord(existWord);
	if (nptr)
	{
		nptr->editWord(newWord);
		insert(nptr);
	}
}


Node* Tree::search(string s1)
{
	if (isNotEmpty())
	{
		Node* rptr = root;
		while (rptr)
		{
			if (rptr->getWord() == s1)
				return rptr;
			if (rptr->getWord() < s1)
				rptr = rptr->right;
			else
				rptr = rptr->left;
		}
	}
	cout << "The Word you are trying to search does not appear to be in the Dictionay" << endl;
	return NULL;
	
}
