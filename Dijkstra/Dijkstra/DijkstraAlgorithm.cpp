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
	m_start->SetPath(0);
}

NodePtr CDijkstraAlgorithm::GetStartNode()
{
	return m_start;
}

unsigned CDijkstraAlgorithm::FindPathFromStartTo(unsigned index)
{
	FindPaths(GetStartNode());
	return GetGraph().GetNode(index)->GetPath();
}

void CDijkstraAlgorithm::FindPaths(NodePtr node)
{
	unsigned currentPath = node->GetPath();
	
	for (auto & link : node->GetLinks())
	{
		auto linkNode = GetGraph().GetNode(link.first);
		if (!linkNode->GetVisited())
		{
			unsigned newPath = currentPath + link.second;
			if (newPath < linkNode->GetPath())
			{
				linkNode->SetPath(newPath);
			}
		}
	}

	node->SetVisited(true);

	for (auto & link : node->GetLinks())
	{
		auto linkNode = GetGraph().GetNode(link.first);
		if (!linkNode->GetVisited())
		{
			FindPaths(linkNode);
		}
	}
}