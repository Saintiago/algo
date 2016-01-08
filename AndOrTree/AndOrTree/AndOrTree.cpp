// AndOrTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TreeController.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		if (argc < 2)
		{
			throw exception("Usage: AndOrTree.exe <filename>.");
		}

		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			throw exception("Cannot open file.");
		}

		CTreeController TreeController;
		TreeController.ReadTree(fin);
		TreeController.WriteElements(cout);
		cout << endl << "Found elements: " << TreeController.GetElementCount() << endl;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}

