#include "stdafx.h"
#include "Node.h"

CNode::CNode(const NodeType type, std::string title, size_t level)
	: m_type(type)
	, m_title(title)
	, m_level(level)
{
}



NodePtrVector CNode::GetSons() const
{
	return m_sons;
}

CNode::NodeType CNode::GetType() const
{
	return m_type;
}

std::string CNode::GetTitle() const
{
	return	m_title;
}

size_t CNode::GetLevel() const
{
	return	m_level;
}

void CNode::AddSon(NodePtr son)
{
	m_sons.push_back(son);
}

bool CNode::IsChosen()
{
	return m_chosen;
}

void CNode::SetChosen(bool chosen)
{
	m_chosen = chosen;
}

NodePtr CNode::GetChosenSon()
{
	for (auto son : m_sons)
	{
		if (son->IsChosen())
		{
			return son;
		}
	}
	SetNextChosenSon();
	return GetChosenSon();
}

bool CNode::SetNextChosenSon()
{
	for (unsigned i = 0; i < m_sons.size(); i++)
	{
		if (m_sons.at(i)->IsChosen())
		{
			m_sons.at(i)->SetChosen(false);
			unsigned next = i + 1;
			if (next >= m_sons.size())
			{
				next = 0;
			}
			m_sons.at(next)->SetChosen(true);
			return (next == 0);
		}
	}
	m_sons.at(0)->SetChosen(true);
	return false;
}

CNode::~CNode()
{
}
