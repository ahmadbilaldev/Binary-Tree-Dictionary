#include <iostream>
#include <fstream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree t1;
	int selector;
	int option;
	do
	{
		cout << "Please select your option\n";
		cout << "1- Admin\n2- User\n3- Exit\n";
		cin >> selector;
		if (selector == 1)
		{
			ifstream inFile;
			inFile.open("control.txt");
			bool log = t1.logIn(inFile);
			if (log)
			{
				do
				{

					cout << "Please Select Your Option\n";
					cout << "1- Add a Word\n";
					cout << "2- Edit a Word\n";
					cout << "3- Remove a Word\n";
					cout << "4- Search a Word\n";
					cout << "5- Set BookMark\n";
					cout << "6- Show BookMarked\n";
					cout << "7- To Exit the Menu\n";
					cin >> option;
					switch (option)
					{
					case 1:
					{
						string word;
						string syn;
						string mean;
						cout << "Please Enter the Word :  ";
						cin >> word;
						cout << "Please Enter the Synonym of the Word :  ";
						cin >> syn;
						cout << "Please Enter the Meaning of the Word :  ";
						cin >> mean;
						t1.insert(word, syn, mean);
						break;
					}
					case 2:
					{
						string existWord, newWord;
						cout << "Please Enter the Word you Want to edit :  ";
						cin >> existWord;
						cout << "Please Enter the new Word :  ";
						cin >> newWord;
						t1.editWord(existWord, newWord);
						break;
					}
					case 3:
					{
						string word;
						cout << "Please Enter the word you want to Remove :  ";
						cin >> word;
						t1.removeWord(word);
						break;
					}
					case 4:
					{
						string word;
						cout << "Please Enter the Word you want to Search :  ";
						cin >> word;
						Node *ptr=t1.search(word);
						ptr->printWord();
						break;
					}
					case 5:
					{
						string word;
						cout << "Please enter the word you want to bookmark :  ";
						t1.setBookMark(word);
						break;
					}
					case 6:
					{
						cout << "The following Words have been Bookmarked : \n";
						t1.printMarked();
						break;
					}
					}

				} while (option != 7);
			}
		}
	

	else if (selector == 2)
	{
			int option;
			cout << "Please Select your Option\n";
			cout << "1- Search a Word\n";
			cout << "2- Set BookMark\n";
			cout << "3- Show BookMarked\n";
			cin >> option;
			switch (option)
			{
			case 1:
			{
				string word;
				cout << "Please enter the word you want to search :  ";
				cin >> word;
				t1.search(word);
			}
			
	}
	} while (selector != 3);

	
	
	system("pause");
}
