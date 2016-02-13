// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TreeController.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			throw exception("Usage: search.exe <file-name> <search-string>");
		}

		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			throw exception("Cannot open file.");
		}

		CTreeController controller;
		cout << "Getting tree from " << argv[1] << "..." << endl;
		controller.ReadTree(fin);
		
		int key;
		string value, again;
		do
		{
			cout << "Our tree:" << endl;
			controller.WriteTree(cout);
			cout << endl << endl << "Please, enter key:" << endl;
			cin >> key;

			if (cin.fail())
			{
				cout << "Please, enter correct integer for key." << endl;
				cin.clear();
				cin.ignore(); 
			}
			else
			{
				if (controller.IsSet(key))
				{
					cout << "Record found: ";
					cout << controller.GetRecord(key) << endl;
				}
				else
				{
					cout << "Record not found. Adding new record. Enter value for key " << key << ":" << endl;
					cin >> value;
					controller.AddRecord(key, value);
					cout << "New record added." << endl;
				}
			}
			cout << "Want to check another key? (press 'y' to continue)" << endl;
			cin >> again;
		} 
		while (again == "y");

		cout << "Bye!" << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}
