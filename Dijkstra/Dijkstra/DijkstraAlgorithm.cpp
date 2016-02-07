#include "stdafx.h"
#include "DijkstraAlgorithm.h"

using namespace std;

CDijkstraAlgorithm::CDijkstraAlgorithm()
{
}


CDijkstraAlgorithm::~CDijkstraAlgorithm()
{
}

void CDijkstraAlgorithm::MakeGraph(ifstream & fin)
{
	m_graph.CreateByAdjacencyMatrix(fin);
}

CGraph CDijkstraAlgorithm::GetGraph()
{
	return m_graph;
}

void CDijkstraAlgorithm::SetStartNode(unsigned index)
{
	m_start = m_graph.GetNode(index);
	m_start->SetWeight(0);
}

NodePtr CDijkstraAlgorithm::GetStartNode()
{
	return m_start;
}

void CDijkstraAlgorithm::SetEndNode(unsigned index)
{
	m_end = m_graph.GetNode(index);
}

NodePtr CDijkstraAlgorithm::GetEndNode()
{
	return m_end;
}

NodePtr CDijkstraAlgorithm::GeMinPathNode(unsigned index)
{
	NodePtr currNode = m_graph.GetNode(index);
	return currNode->GetMinPathNode();
}