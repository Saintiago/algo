#include "stdafx.h"
#include "Tree.h"

using namespace std;

CTree::CTree(string TreeName)
{
	m_head = make_shared<CNode>(CNode::NodeType::AND, TreeName, 0);
}

NodePtr CTree::GetHead()
{
	return m_head;
}

CTree::~CTree()
{
}
