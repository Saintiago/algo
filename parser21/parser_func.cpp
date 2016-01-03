#include"stdafx.h"
#include "parser_func.h"

Stack codeStack;
Stack boundariesStack;

map <string, string> pushPopMap =
{
	{ "end", "begin" },
	{ "until", "repeat" }
};

const map <string, string> boundaries =
{
	{ "\"", "\"" },
	{ "'", "'" },
	{ "{", "}" },
	{ "(*", "*)"},
	{ "(", ")" },
	{ "//", ""}
};

void ProcessFile(ifstream & file)
{
	string line;
	unsigned int lineCount = 0;

	while (getline(file, line))
	{
		lineCount++;
		if (!ProcessLine(line))
		{
			string message = "Error on line ";
			message += to_string(lineCount);
			throw exception(message.c_str());
		}
	}

	if (!codeStack.IsEmpty())
	{
		throw exception("Unexpected file end");
	}
}

bool ProcessLine(string line)
{
	line = RemoveBounadries(line);
	if (line.empty())
	{
		return true;
	}

	istringstream iss(line);
	string word;
	while (iss >> word)
	{

		if (!CheckWord(word))
		{
			return false;
		}
	}

	return true;
}

bool CheckWord(string word)
{
	word = ToLower(Trim(word));

	if (pushPopMap.find(word) != pushPopMap.end())
	{
		if (codeStack.IsEmpty() || (codeStack.Pop() != pushPopMap[word]))
		{
			return false;
		}
	}
	else
	{
		codeStack.Push(word);
	}

	return true;
}

string RemoveBounadries(string line)
{
	string currentBound;
	unsigned int firstBoundaryPos = FindFirstBoundary(line);
	if (firstBoundaryPos != string::npos)
	{
		currentBound = boundariesStack.GetHeadData();
	}
	unsigned int secondBoundaryPos = FindSecondBoundary(line, firstBoundaryPos);
	while (firstBoundaryPos != string::npos || secondBoundaryPos != string::npos)
	{
		if (firstBoundaryPos != string::npos && secondBoundaryPos != string::npos)
		{
			line.erase(firstBoundaryPos, (secondBoundaryPos - firstBoundaryPos + currentBound.length()));
		}
		else if (firstBoundaryPos != string::npos)
		{
			line.erase(firstBoundaryPos, string::npos);
		}
		else if (secondBoundaryPos != string::npos)
		{
			line.erase(0, (secondBoundaryPos - firstBoundaryPos));
		}
		firstBoundaryPos = FindFirstBoundary(line);
		if (firstBoundaryPos != string::npos)
		{
			currentBound = boundariesStack.GetHeadData();
		}
		secondBoundaryPos = FindSecondBoundary(line, firstBoundaryPos);
	}
	return line;
}

unsigned int FindFirstBoundary(string str)
{
	unsigned int firstBoundaryPos = string::npos;
	unsigned int currBoundaryPos;
	string firstBound;
	string secondBound;
	for (auto const boundary : boundaries)
	{
		firstBound = boundary.first;
		currBoundaryPos = str.find(firstBound);
		if (currBoundaryPos != string::npos && (currBoundaryPos < firstBoundaryPos || firstBoundaryPos == string::npos))
		{
			firstBoundaryPos = currBoundaryPos;
			secondBound = boundary.second;
		}
	}

	if (firstBoundaryPos != string::npos)
	{
		if (secondBound != "")
		{
			boundariesStack.Push(secondBound);
		}
	}

	return firstBoundaryPos;
}

unsigned int FindSecondBoundary(string str, unsigned int firstPos)
{
	unsigned int secondBoundaryPos = string::npos;
	if (!boundariesStack.IsEmpty())
	{
		string secBound = boundariesStack.GetHeadData();
		if (secBound.empty())
		{
			secondBoundaryPos = str.length() - 1;
		}
		else
		{
			secondBoundaryPos = str.find(secBound, (firstPos + 1));
		}
		
		if (secondBoundaryPos != string::npos)
		{
			boundariesStack.Pop();
		}
	}
	return secondBoundaryPos;
}

string ToLower(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

string Trim(string str)
{
	char lastChar = str.at(str.length() - 1);
	string toTrim = ";.";
	if (toTrim.find(lastChar) != string::npos)
	{
		str = str.substr(0, str.length() - 1);
	}
	return str;
}