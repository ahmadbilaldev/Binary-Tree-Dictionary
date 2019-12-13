#include "Tree.h"
#include <string>
#include <fstream>

//Default constructor 
Tree::Tree() : root(NULL), count(0)
{
}

//Parameterized Constructor
Tree::Tree(Node*& ptr) : root(ptr), count(1)
{
	ptr = root->leftptr = root->rightptr = NULL;
}

//Function to check that if the dictionary empty
bool Tree::isEmpty()
{
	if (!root)
		return true;
	else
		return false;
}

//Function to check that if dictionary is not empty
bool Tree::isNotEmpty()
{
	if (!root)
		return false;
	else
		return true;
}

//Function to insert a new word in the dictionary
Tree& Tree::insert(string word, string synonym, string meaning)
{
	Node* ptr = new Node(word, synonym, meaning);
	if (!root) //Setting root when dictionary is empty
	{
		root = ptr;
		++count;
		return *this;
	}
	else
	{
		Node* rptr, * bptr; //runner pointers
		bptr = NULL;
		rptr = root; //initilizing the runner pointer from root
		while (rptr) //iterating through the dictionary to find the place of new word
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

//Inorder Tree traversal
void Tree::printInfixOrder()
{
	void prtInfixOrder(Node * root); //local function declaration

	if (!root) //tree is empty
		cout << "\nEmpty Tree\n";
	else
	{

		cout << left << setw(30);
		cout << "Words";
		cout << setw(30);
		cout << "Synonyms";
		cout << setw(30);
		cout << "Meaning";
		cout << endl;
		prtInfixOrder(root); //printing the dictionary in inorder
		cout << endl;
	}
}

//Definition of local function declared in Inorder traversal
void prtInfixOrder(Node* root)
{
	if (root)
	{
		prtInfixOrder(root->leftptr); //recursive call to go on left subtree
		root->printWord();
		prtInfixOrder(root->rightptr); //recursive call to go on right subtree
	}
}

//Dectructor
Tree::~Tree()
{
	void deleteNodes(Node * root); //declaration of a local function
	if (root)
		deleteNodes(root); //call to the local function
}

//defiition of function declared locally in destructor
void deleteNodes(Node* root)
{
	if (root)
	{
		deleteNodes(root->leftptr); //recursive call to go on left subtree
		deleteNodes(root->rightptr); //recursive call to go on right subtree
		delete root; //deleting node
	}
}

//Funcion to remove a word from dictionary
Node* Tree::removeWord(string word)
{
	Node* ptr, * temp;
	ptr = root;
	temp = NULL;

	if (!ptr) //tree is empty
	{
		cout << "The tree is empty thus returning NULL" << endl;
		return NULL;
	}

	while (ptr) //iterating through the dictionary
	{
		if (ptr->getWord() == word)
		{
			Node* rptr = ptr;
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

//Function to edit a word
void Tree::editWord(string existWord, string newWord)
{
	Node* nptr = removeWord(existWord); //call to find the word which is to be edited
	if (nptr)
	{
		nptr->editWord(newWord); //Calling node class function to edit the word
		insert(nptr->getWord(), nptr->getSynonym(), nptr->getMeaning()); //inserting the word in the dictionary
	}
}

//Function to set bookmark
void Tree::setBookMark(string s1)
{
	Node* ptr = search(s1); //searching the word
	if (ptr)
	{
		ptr->setBookMark(); //node class function is called to set bookmark
	}
}

//Function to print book marked words
void Tree::printMarked()
{
	void prtMarked(Node * &root); //declaration of a local function
	if (root)
	{
		prtMarked(root); //call to local function
	}
}

//definition of local function declared in the prtBookMark
void prtMarked(Node*& root)
{
	if (root)
	{
		prtMarked(root->leftptr); //To move to left subtree
		if (root->getMarked())
		{
			root->printWord(); //printing the word
		}
		prtMarked(root->rightptr); //recursive call to go on right subtree
	}
}

//Function to search a word in the dictionary
Node* Tree::search(string s1)
{
	if (isNotEmpty())
	{
		Node* rptr = root; //runner pointer
		while (rptr)
		{
			if (rptr->getWord() == s1) //word is found
				return rptr;
			if (rptr->getWord() < s1) //move to right subtree
				rptr = rptr->rightptr;
			else
				rptr = rptr->leftptr; //move to left subtree
		}
	}
	//word not in dictionary
	cout << "The Word you are trying to search does not appear to be in the Dictionay" << endl;
	return NULL;
}

//Function to write in file
void Tree::writeToFile(ofstream& outFile)
{

	void toFile(Node * root, ofstream & outFile);

	if (root)
	{
		toFile(root, outFile);
	}
}

//Function definition of Locally declared in wrioteToFile
void toFile(Node* root, ofstream& outFile)
{
	if (root)
	{
		toFile(root->leftptr, outFile);//recursive call to go on left subtree
		root->writeToFile(outFile); //writing in the file
		toFile(root->rightptr, outFile);//recursive call to go on right subtree
	}
}

//Function to read from file
void Tree::readFromFile(ifstream& inFile)
{
	string line = "";

	while (!(inFile.eof()))
	{
		getline(inFile, line);
		if (line == "") //If line is empty
		{
			break;
		}
		int character = 0;
		string word = "", synonym = "", def = ""; //local variables
		for (character; line[character] != ','; character++) //reading char by char for word from file
		{
			word += line[character];
		}
		character++;
		for (character; line[character] != ','; character++) //reading synonym from file
		{
			synonym += line[character];
		}
		character++;
		for (character; line[character] != ','; character++) //reading definition from file
		{
			def += line[character];
		}
		insert(word, synonym, def); //insert function is called to insert in dictionary
	}
}

//Function user control
bool Tree::logIn(ifstream& inFile)
{
	string userFile, passFile, userInput, passInput;
	//user prompt
	cout << "Enter the UserName\n";
	cin >> userInput;
	cout << "Enter the Password\n";
	cin >> passInput;
	bool logIn = false;
	while (!(inFile.eof()))
	{
		getline(inFile, userFile);
		getline(inFile, passFile);
		if ((userFile == userInput) && (passFile == passInput)) //password validation
		{
			logIn = true;
		}
	}
	inFile.close();
	if (logIn) //if password and user name is true
		cout << "Access Verified\n";
	else
		cout << "Access Denied\n"; //access not given
	return logIn;
}

//function to find word of the day
void Tree::wordOfTheDay()
{
	//generating a number between given range
	int random(int count);
	int index = 0;
	if (root)
	{
		index = random(count - 1);
	}
	int counter = 1;
	void searchWordByIndex(Node * &root, int counter, int index); //local declaration 
	searchWordByIndex(root, counter, index); //call to local funcion to print the word
}

//Definition of local function declared in wordOfTheDay
void searchWordByIndex(Node*& root, int counter, int index)
{
	if (root)
	{
		searchWordByIndex(root->leftptr, counter + 1, index); //recursive call to go on left subtree
		if (counter == index) { //If desired word is found
			root->printWord(); //printing word
		}
		searchWordByIndex(root->rightptr, counter + 1, index); //recursive call to go on right subtree
	}
}


//Definition of local function declared in wordOfTheDay
int random(int count)
{
	srand(time(0));
	return ((rand() % count) + 1); //generating a random number
}

//Function to show synonym and definition of selected word
void Tree::showSynonymAndMeaning(string word)
{
	Node* ptr = search(word); //searching the word
	if (ptr != NULL)
	{
		cout << "Synonym and Definition of the selected word are: \n";
		cout << "Word: ";
		ptr->showWord(); //displaying the word
		cout << "\nSynonym: ";
		ptr->printSynonym(); //displaying the synonym
		cout << "\nDefinition: ";
		ptr->printMeaning(); //displaying the definition
		cout << endl;
	}
	else
	{
		cout << "The Word which you have selected is not present in the dictionary\n";
	}
}
void Tree::editSynonym(string existWord, string newSynonym)
{

	Node* ptr = removeWord(existWord);
	if (ptr)
	{
		ptr->editSynonym(newSynonym);
		insert(ptr->getWord(), ptr->getSynonym(), ptr->getDefinition());
	}
}
