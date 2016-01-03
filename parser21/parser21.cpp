#include "stdafx.h"
#include "parser_func.h"

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
		{
			throw exception("Usage: parser21.exe <file-name>");
		}

		ifstream fin(argv[1]);
		if (!fin.is_open())
		{
			throw exception("Cannot open file.");
		}

		ProcessFile(fin);

		cout << "All is fine" << endl;
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}