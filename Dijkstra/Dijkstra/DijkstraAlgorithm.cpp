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
	//m_graph.CreateByAdjacencyMatrix(fin);
	m_graph.CreateByArcList(fin);
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
	cout << "Searching path to " << index << "th node..." << endl;
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
			cout << "Path from start to " << link.first << "th node: " << newPath << endl;
			if (newPath < linkNode->GetPath())
			{
				cout << "New path are better than old (" << linkNode->GetPath()  <<") and we replace it. " << endl;
				linkNode->SetPath(newPath);
			}
			else
			{
				cout << "New path aren't better than old (" << linkNode->GetPath() << ") and we stick with the old path. " << endl;
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