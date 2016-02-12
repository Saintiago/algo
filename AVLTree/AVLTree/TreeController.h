#pragma once
#include "stdafx.h"
#include "Node.h"

class CTreeController
{
public:

	CTreeController();
	~CTreeController();
	void ReadTree(std::ifstream & in);
	void WriteTree(std::ostream & out);
	void WriteNode(NodePtr root, std::ostream & out);
	std::string GetRecord(int key);
	void AddRecord(int key, std::string data);
	bool IsSet(int key);

private:

	NodePtr m_root = nullptr;

	NodePtr MakeNode(std::ifstream & in);
	NodePtr GetNode(NodePtr root, int key);
};

