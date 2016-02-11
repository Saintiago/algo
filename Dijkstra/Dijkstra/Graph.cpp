#include "stdafx.h"
#include "Graph.h"

using namespace std;

void ThrowOutOfRange(size_t pos)
{
	std::stringstream ss;
	ss << "There is no " << pos << "th node in graph!";
	throw std::out_of_range(ss.str());
}

CGraph::CGraph()
{
}


CGraph::~CGraph()
{
}

void CGraph::CreateByAdjacencyMatrix(ifstream & is)
{
	CreateNodes(is);
	string line;
	unsigned index = 0;
	while (!is.eof())
	{
		
		FillNodeLinks(is, index);
		index++;
	}
}

size_t CGraph::Size()
{
	return m_nodes.size();
}

NodePtr CGraph::GetNode(unsigned index)
{
	if (index > (Size() - 1))
	{
		ThrowOutOfRange(index);
	}
	return m_nodes.at(index);
}

void CGraph::AddNode()
{
	m_nodes.push_back(make_shared<CNode>());
}

void CGraph::FillNodeLinks(std::ifstream & is, unsigned index)
{
	if (index > (Size() - 1))
	{
		ThrowOutOfRange(index);
	}

	string line;
	getline(is, line);
	stringstream links(line);

	unsigned indexInner = 0;
	unsigned linkWeight;
	while (!links.eof())
	{
		links >> linkWeight;
		if (linkWeight > 0)
		{
			m_nodes.at(index)->AddLink(indexInner, linkWeight);
		}
		indexInner++;
	}
}

NodePtrVector CGraph::GetNodes()
{
	return m_nodes;
}

void CGraph::CreateNodes(std::ifstream & is)
{
	string str, weight;
	getline(is, str);
	stringstream ss(str);
	while (!ss.eof())
	{
		AddNode();
		ss >> weight;
	}
	is.seekg(0);
}

void CGraph::ResetPaths()
{
	for (auto & node : m_nodes)
	{
		node->ResetPath();
	}
}