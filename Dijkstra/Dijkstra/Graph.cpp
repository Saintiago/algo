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

void CGraph::CreateByAdjacencyMatrix(istream & is)
{
	unsigned index = 0;
	string line;
	while (!is.eof())
	{
		getline(is, line);
		stringstream ss(line);
		FillNodeLinks(ss, index);
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

void CGraph::FillNodeLinks(std::istream & links, unsigned index)
{
	if (index > (Size() - 1))
	{
		ThrowOutOfRange(index);
	}

	unsigned indexInner = 0;
	unsigned linkWeight;
	while (!links.eof())
	{
		if ((indexInner + 1) > Size())
		{
			AddNode();
		}
		links >> linkWeight;
		if (linkWeight > 0)
		{
			NodePtr tmpLink = make_shared<CNode>(*m_nodes[index]);
			m_nodes[indexInner]->AddLink(tmpLink, linkWeight);
		}
		indexInner++;
	}
}
