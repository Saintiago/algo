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

		int levelDiff = node->GetLevel() - parents.top()->GetLevel(); // int - cause can be less than 0
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

	MakeBaseElement();

	do
	{
		m_elementCount++;
		out << endl << "Element " << m_elementCount << endl << "-----------------------------" << endl;
		WriteElement(out, m_tree->GetHead());
	} 
	while (GetNextElement());
}

bool CTreeController::GetNextElement()
{
	if (!m_orNodes.top()->SetNextChosenSon())
	{
		do
		{
			m_orNodes.pop();
		}
		while(m_orNodes.size() > 0 && !m_orNodes.top()->SetNextChosenSon());
	}

	if (!m_orNodes.empty())
	{
		NodePtr chosen = m_orNodes.top()->GetChosenSon();
		if (chosen->GetType() == CNode::NodeType::OR && chosen->GetChosenSon() == nullptr)
		{
			MakeChoice(chosen);
		}
		ResetOrNodesList();
		BuildOrNodesList(m_tree->GetHead());
	}

	return (!m_orNodes.empty());
}

void CTreeController::MakeBaseElement()
{
	MakeChoice(m_tree->GetHead());
	BuildOrNodesList(m_tree->GetHead());
}

void CTreeController::MakeChoice(NodePtr node)
{
	if (node->GetSons().size() > 0)
	{
		if (node->GetType() == CNode::NodeType::OR)
		{
			node->SetNextChosenSon();
			MakeChoice(node->GetChosenSon());
		}
		else
		{
			for (auto son : node->GetSons())
			{
				son->SetChosen(true);
				MakeChoice(son);
			}
		}
	}
}

void CTreeController::BuildOrNodesList(NodePtr node)
{
	if (node->GetSons().size() > 0)
	{
		if (node->GetType() == CNode::NodeType::OR)
		{
			m_orNodes.push(node);
			BuildOrNodesList(node->GetChosenSon());
		}
		else
		{
			for (auto son : node->GetSons())
			{
				BuildOrNodesList(son);
			}
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

void CTreeController::ResetOrNodesList()
{
	std::stack<NodePtr> emptyStack;
	m_orNodes.swap(emptyStack);
}