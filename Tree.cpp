#include "Tree.h"

Tree::Tree() : root(NULL)
{
}

Tree::Tree(Node *&ptr) : root(ptr), count(1)
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

void Tree::insert(Node *&ptr)
{
	if (!root)
		root = ptr;
	else
	{
		Node *rptr, *bptr;
		rptr = root;
		while (rptr)
		{
			bptr = rptr;
			if (rptr->getData() < ptr->getData())
				rptr = rptr->right;
			else
				rptr = rptr->left;
		}

		if (bptr->getData() < ptr->getData())
			bptr->right = ptr;
		else
			bptr->left = ptr;

		++count;
	}

	ptr = ptr->left = ptr->right = NULL;
}

void Tree::printPreOrder()
{
	void prtPreOrder(Node * root);

	if (!root)
		cout << "\nEmpty Tree\n";
	else
		prtPreOrder(root);
}

void prtPreOrder(Node *root)
{
	if (root)
	{
		root->Print();
		prtPreOrder(root->left);
		prtPreOrder(root->right);
	}
}

void Tree::printPostOrder()
{
	void prtPostOrder(Node * root);

	if (!root)
		cout << "\nEmpty Tree\n";
	else
		prtPostOrder(root);
}

void prtPostOrder(Node *root)
{
	if (root)
	{
		prtPostOrder(root->left);
		prtPostOrder(root->right);
		root->Print();
	}
}

void Tree::printInfixOrder()
{
	void prtInfixOrder(Node * root);

	if (!root)
		cout << "\nEmpty Tree\n";
	else
		prtInfixOrder(root);
}

void prtInfixOrder(Node *root)
{
	if (root)
	{
		prtInfixOrder(root->left);
		root->Print();
		prtInfixOrder(root->right);
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
		deleteNodes(root->left);
		deleteNodes(root->right);
		delete root;
	}
}

Node *Tree::search(Node *&ptr)
{
	if (isNotEmpty())
	{
		Node *rptr = root;
		while (rptr)
		{
			if (rptr == ptr)
				return ptr;
			if (rptr->getData() < ptr->getData())
				rptr = rptr->right;
			else
				rptr = rptr->left;
		}
	}
	return NULL;
}

void Tree::deleteNode(Node *&ptr)
{
	Node *dPtr, *rPtr;
	if (root)
	{
		if (isNotEmpty())
		{
			Node *rptr = root;
			while (rptr)
			{
				if (rptr == ptr)
					break; // return
				if (rptr->getData() < ptr->getData())
					rptr = rptr->right;
				else
					rptr = rptr->left;
			}
		}
	}
}

// int Tree::getMaxDegree()
// {
// 	void getDegree(Node * root, int &degree);
// 	int degree = 1;
// 	getDegree(root, degree);
// }

void getDegree(Node *root, int &degree)
{
	if (root)
	{
		if (root->left && root->right)
			degree = 2;
		else
		{
			getDegree(root->left, degree);
			getDegree(root->right, degree);
		}
	}
}
