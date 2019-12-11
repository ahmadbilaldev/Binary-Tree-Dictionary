#include "Tree.h"



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

Tree& Tree::insert(Node*& ptr)
{
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

Node* Tree::search(Node*& ptr)
{
	if (isNotEmpty())
	{
		Node* rptr = root;
		while (rptr)
		{
			if (rptr == ptr)
				return ptr;
			if (rptr->getWord() < ptr->getWord())
				rptr = rptr->right;
			else
				rptr = rptr->left;
		}
	}
	return NULL;
}
