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

	CNode(unsigned weight = INT_MAX);
	~CNode();

	unsigned GetWeight();
	void SetWeight(unsigned weight);

	void AddLink(NodePtr & node, unsigned weight);
	NodePathPairPtrVector & GetLinks();

private:
	unsigned m_weight;
	NodePathPairPtrVector m_links;
};
