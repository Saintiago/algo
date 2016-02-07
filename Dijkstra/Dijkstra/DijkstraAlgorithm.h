#pragma once
#include "stdafx.h"
#include "Graph.h"

class CDijkstraAlgorithm
{
public:
	CDijkstraAlgorithm();
	~CDijkstraAlgorithm();

	void MakeGraph(std::ifstream & fin);
	CGraph GetGraph();

	void SetStartNode(unsigned index);
	NodePtr GetStartNode();

	void SetEndNode(unsigned index);
	NodePtr GetEndNode();
	NodePtr GeMinPathNode(unsigned index);

private:
	CGraph m_graph;
	NodePtr m_start, m_end;
};

