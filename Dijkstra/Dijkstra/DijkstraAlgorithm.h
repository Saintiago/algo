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
	unsigned FindPathFromStartTo(unsigned index);
	NodePtr GetStartNode();
	

private:
	CGraph m_graph;
	NodePtr m_start, m_end;
	
	void FindPaths(NodePtr node);
};

