#pragma once
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <exception>
#include "Stack.h"

using namespace std;

void ProcessFile(ifstream & fileName);
bool ProcessLine(string line);
bool CheckWord(string word);
string RemoveBounadries(string word);
unsigned int FindFirstBoundary(string str);
unsigned int FindSecondBoundary(string str, unsigned int firstBoundaryPos);
string ToLower(string str);
string Trim(string str);