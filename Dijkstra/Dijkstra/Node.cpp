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


unsigned CNode::GetPath()
{
	return m_weight;
}

void CNode::SetPath(unsigned weight)
{
	m_weight = weight;
}

void CNode::AddLink(NodePtr & node, unsigned weight)
{
	NodePathPairPtr tmpLink = make_shared<NodePathPair>(make_pair(node, weight));
	m_links.push_back(tmpLink);

	if (m_links.size() > 1)
	{
		for (size_t i = (m_links.size() - 1); i > 0 ; i--)
		{
			if (m_links.at(i)->second < m_links.at(i - 1)->second)
			{
				m_links.at(i).swap(m_links.at(i - 1));
			}
			else
			{
				break;
			}
		}
	}
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