#pragma once
#include "stdafx.h"

class CNode;
typedef std::shared_ptr<CNode> NodePtr;
typedef std::vector<NodePtr> NodePtrVector;
typedef std::pair<NodePtr, unsigned> NodePathPair;
typedef std::shared_ptr<NodePathPair> NodePathPairPtr;
typedef std::vector<NodePathPairPtr> NodePathPairPtrVector;


class CNode
{
public:

	CNode(unsigned weight = 1);
	~CNode();

	unsigned GetPath();
	void SetPath(unsigned weight);

	void AddLink(NodePtr & node, unsigned weight);
	NodePathPairPtrVector & GetLinks();

	bool GetVisited();
	void SetVisited(bool visited);

private:
	unsigned m_weight;
	NodePathPairPtrVector m_links;
	bool m_visited = false;
};
