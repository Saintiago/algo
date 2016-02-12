#pragma once
#include "stdafx.h"

class CNode;
typedef std::shared_ptr<CNode> NodePtr;

class CNode
{
public:
	CNode(int key, std::string data);
	~CNode();

	unsigned char height(NodePtr p);
	int bfactor(NodePtr p);
	void fixheight(NodePtr p);
	NodePtr rotateright(NodePtr p); // ������ ������� ������ p
	NodePtr rotateleft(NodePtr q); // ����� ������� ������ q
	NodePtr balance(NodePtr p); // ������������ ���� p
	NodePtr insert(NodePtr p, NodePtr newNode);
	NodePtr findmin(NodePtr p); // ����� ���� � ����������� ������ � ������ p 
	NodePtr removemin(NodePtr p); // �������� ���� � ����������� ������ �� ������ p
	NodePtr remove(NodePtr p, int k); // �������� ����� k �� ������ p



	int m_key = 0;
	std::string m_data = "";
	unsigned char m_height = 0;
	NodePtr m_left;
	NodePtr m_right;
};

