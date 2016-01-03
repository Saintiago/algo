#include "stdafx.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <fstream>


Stack::Stack()
{
	Clear();
}


Stack::~Stack()
{
}



void Stack::Push(string data)
{
	StackPtr stackElement (new StackStruct);
	stackElement->data = data;

	stackElement->next = m_head;
	if (IsEmpty())
	{
		m_head = stackElement;
		stackElement->next = nullptr;
	}
	else
	{
		stackElement->next = m_head;
		m_head = stackElement;
	}
}

bool Stack::IsEmpty()
{
	return (m_head == nullptr);
}

string Stack::GetHeadData()
{
	if (IsEmpty())
	{
		throw StackError::AccessToEmptyStack;
	}
	return m_head->data;
}

string Stack::Pop()
{
	string data = m_head->data;
	m_head = m_head->next;
	return data;
}

void Stack::Clear()
{
	m_head = nullptr;
}