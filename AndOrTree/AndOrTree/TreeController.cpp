#include "stdafx.h"
#include "TreeController.h"

using namespace std;

const map<char, CNode::NodeType> CTreeController::typeChars =
{
	{ '.', CNode::NodeType::NO_TYPE },
	{ '-', CNode::NodeType::AND },
	{ '+', CNode::NodeType::OR }
};

const map<CNode::NodeType, char> CTreeController::typeCharsRev =
{
	{ CNode::NodeType::NO_TYPE, '.' },
	{ CNode::NodeType::AND, '-' },
	{ CNode::NodeType::OR, '+' }
};

CTreeController::CTreeController()
{
}


CTreeController::~CTreeController()
{
}


void CTreeController::ReadTree(ifstream & in)
{
	istream & is(in);
	string title;
	getline(is, title);
	m_tree = make_shared<CTree> (title);

	stack <NodePtr> parents;
	parents.push(m_tree->GetHead());
	size_t prevLevel = 0;
	NodePtr prevNode = parents.top();
	
	string lineOfText;
	while (getline(is, lineOfText))
	{
		if (lineOfText.empty())
		{
			continue;
		}

		NodePtr node = MakeNode(lineOfText);

		if (node->GetType() == CNode::NodeType::OR)
		{
			m_orNodes.push_back(node);
		}

		int levelDiff = node->GetLevel() - parents.top()->GetLevel();
		if (levelDiff == 1)
		{
			parents.top()->AddSon(node);
		}
		else if (levelDiff == 2)
		{
			parents.push(prevNode);
			parents.top()->AddSon(node);
		}
		else if (levelDiff < 1)
		{
			for (int i = levelDiff; i < 1; i++)
			{
				parents.pop();
			}
			parents.top()->AddSon(node);
		}
		prevNode = node;
	}
}


void CTreeController::WriteTree(ostream & out)
{
	NodePtr head = m_tree->GetHead();
	WriteNode(out, head);
}

void CTreeController::WriteElements(ostream & out, unsigned recursionLevel)
{
	unsigned elementCount = 0;
	while (!m_orNodes.at(recursionLevel)->SetNextChosenSon())
	{
		out << endl << "-----------------------------" << endl;
		WriteElement(out, m_tree->GetHead());
		m_elementCount++;
		if ((recursionLevel + 1) < m_orNodes.size())
		{
			WriteElements(out, (recursionLevel + 1));
		}
	}
}

unsigned CTreeController::GetElementCount()
{
	return m_elementCount;
}

size_t CTreeController::CountLevel(std::string str)
{
	return std::count(str.begin(), str.end(), str[0]);
}

CNode::NodeType CTreeController::GetNodeType(std::string str)
{
	return typeChars.at(str[0]);
}

NodePtr CTreeController::MakeNode(std::string str)
{
	return make_shared<CNode>(GetNodeType(str), str.substr(CountLevel(str)), CountLevel(str));
}

void CTreeController::WriteNode(std::ostream & out, NodePtr node)
{
	out << GetLevelString(node->GetLevel(), node->GetType()) << node->GetTitle() << endl;
	for (auto son : node->GetSons())
	{
		WriteNode(out, son);
	}
}

void CTreeController::WriteElement(std::ostream & out, NodePtr node)
{
	out << GetLevelString(node->GetLevel(), node->GetType()) << node->GetTitle() << endl;
	if (node->GetType() == CNode::NodeType::OR)
	{
		WriteElement(out, node->GetChosenSon());
	}
	else
	{
		for (auto son : node->GetSons())
		{
			WriteElement(out, son);
		}
	}
}

string CTreeController::GetLevelString(size_t level, CNode::NodeType type)
{
	string levelStr = "";
	for (size_t i = 0; i < level; i++)
	{
		levelStr += typeCharsRev.at(type);
	}
	return levelStr;
}