#pragma once
#include "Node.h"

class CTree;

typedef std::shared_ptr <CTree> TreePtr;
typedef std::vector<TreePtr> TreePtrVector;

class CTree
{
public:
	CTree(std::string TreeName);
	~CTree();

	NodePtr GetHead();
	TreePtrVector GetElements();

private:
	NodePtr m_head = nullptr;
};

