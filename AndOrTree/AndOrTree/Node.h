#pragma once

class CNode;

typedef std::shared_ptr<CNode> NodePtr;
typedef std::vector<NodePtr> NodePtrVector;

class CNode
{

public:

	enum class NodeType
	{
		NO_TYPE,
		AND,
		OR
	};

	CNode(const NodeType type, std::string title, size_t level);
	~CNode();

	NodePtrVector GetSons() const;
	NodeType GetType() const;
	std::string GetTitle() const;
	size_t GetLevel() const;
	bool IsChosen();
	void SetChosen(bool chosen);
	NodePtr GetChosenSon();
	bool SetNextChosenSon();
	void SetParent(NodePtr parent);
	void AddSon(NodePtr son);
	bool IsParentChoosen();

private:
	NodePtrVector m_sons = {};
	NodeType m_type = NodeType::AND;
	std::string m_title = "";
	size_t m_level;
	bool m_chosen = false;
	NodePtr m_parent;

	NodePtr GetParent();
};

