#pragma once
#include "Tree.h"

class CTreeController
{
public:

	static const std::map<char, CNode::NodeType> typeChars;
	static const std::map<CNode::NodeType, char> typeCharsRev;

	CTreeController();
	~CTreeController();
	void ReadTree(std::ifstream & in);
	void WriteTree(std::ostream & out);
	void WriteElements(std::ostream & out, unsigned recursionLevel = 0);
	unsigned GetElementCount();

private:

	size_t CountLevel(std::string str);
	CNode::NodeType GetNodeType(std::string str);
	NodePtr MakeNode(std::string str);
	std::string GetLevelString(size_t level, CNode::NodeType type);
	void WriteNode(std::ostream & out, NodePtr node);
	void WriteElement(std::ostream & out, NodePtr node);
	std::vector<NodePtr> m_orNodes;
	bool AllOrNodesHaveChosen();

	TreePtr m_tree;
	unsigned m_elementCount = 0;
};

