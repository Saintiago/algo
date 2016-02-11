#pragma once
#include "stdafx.h"
#include "Node.h"

class CGraph
{
public:
	CGraph();
	~CGraph();

	void CreateByAdjacencyMatrix(std::ifstream & adjacencyMatrix);
	size_t Size();
	NodePtr GetNode(unsigned index);
	NodePtrVector GetNodes();
	void ResetPaths();

private:
	NodePtrVector m_nodes;

	void AddNode();
	void CreateNodes(std::ifstream & is);
	void FillNodeLinks(std::ifstream & is, unsigned index);
};

