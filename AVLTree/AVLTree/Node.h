#pragma once
#include "stdafx.h"

class CNode;
typedef std::shared_ptr<CNode> NodePtr;

class CNode
{
public:
	CNode(int key, std::string data);
	~CNode();

	unsigned char height(NodePtr p);
	int bfactor(NodePtr p);
	void fixheight(NodePtr p);
	NodePtr rotateright(NodePtr p); // правый поворот вокруг p
	NodePtr rotateleft(NodePtr q); // левый поворот вокруг q
	NodePtr balance(NodePtr p); // балансировка узла p
	NodePtr insert(NodePtr p, NodePtr newNode);
	NodePtr findmin(NodePtr p); // поиск узла с минимальным ключом в дереве p 
	NodePtr removemin(NodePtr p); // удаление узла с минимальным ключом из дерева p
	NodePtr remove(NodePtr p, int k); // удаление ключа k из дерева p



	int m_key = 0;
	std::string m_data = "";
	unsigned char m_height = 0;
	NodePtr m_left;
	NodePtr m_right;
};

