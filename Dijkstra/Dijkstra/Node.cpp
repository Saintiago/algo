#include "stdafx.h"
#include "Node.h"

using namespace std;

CNode::CNode(unsigned weight)
	: m_weight(weight)
{
}

CNode::~CNode()
{
}


unsigned CNode::GetWeight()
{
	return m_weight;
}

void CNode::SetWeight(unsigned weight)
{
	m_weight = weight;
}

void CNode::AddLink(NodePtr & node, unsigned weight)
{
	NodePathPairPtr tmpLink = make_shared<NodePathPair>(make_pair(node, weight));
	m_links.push_back(tmpLink);
}

NodePathPairPtrVector & CNode::GetLinks()
{
	return m_links;
}

bool CNode::GetVisited()
{
	return m_visited;
}

void CNode::SetVisited(bool visited)
{
	m_visited = visited;
}

NodePtr CNode::GetMinPathNode()
{
	unsigned minPath = INFINITY;
	for (auto & link : m_links)
	{
		if (link->second < )
	}
}