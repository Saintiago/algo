#pragma once
#include "stdafx.h"
#include "Node.h"

class CGraph
{
public:
	CGraph();
	~CGraph();

	void CreateByAdjacencyMatrix(std::istream & adjacencyMatrix);
	size_t Size();
	NodePtr GetNode(unsigned index);
	NodePtrVector GetNodes();

private:
	NodePtrVector m_nodes;

	void AddNode();
	void FillNodeLinks(std::istream & links, unsigned index);
};

