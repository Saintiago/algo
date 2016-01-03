#pragma once
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Stack
{
public:

	Stack();
	~Stack();

	struct StackStruct;

	typedef shared_ptr<StackStruct> StackPtr;

	struct StackStruct
	{
		string data;
		StackPtr next;
	};
	
	enum class StackError
	{
		AccessToEmptyStack
	};

	void Push(string str);
	string Pop();
	string GetHeadData();
	bool IsEmpty();
	void Clear();

private:
	StackPtr m_head;
};

