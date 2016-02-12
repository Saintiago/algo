#include "stdafx.h"
#include "Node.h"

using namespace std;

CNode::CNode(int key, string data)
	: m_key(key)
	, m_data(data)
	, m_left(nullptr)
	, m_right(nullptr)
{
}


CNode::~CNode()
{
}

unsigned char CNode::height(NodePtr p)
{
	return p ? p->m_height : 0;
}

int CNode::bfactor(NodePtr p)
{
	return height(p->m_right) - height(p->m_left);
}

void CNode::fixheight(NodePtr p)
{
	unsigned char hl = height(p->m_left);
	unsigned char hr = height(p->m_right);
	p->m_height = (hl>hr ? hl : hr) + 1;
}

NodePtr CNode::rotateright(NodePtr p) // правый поворот вокруг p
{
	NodePtr q = p->m_left;
	p->m_left = q->m_right;
	q->m_right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

NodePtr CNode::rotateleft(NodePtr q) // левый поворот вокруг q
{
	NodePtr p = q->m_right;
	q->m_right = p->m_left;
	p->m_left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

NodePtr CNode::balance(NodePtr p) // балансировка узла p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->m_right) < 0)
			p->m_right = rotateright(p->m_right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->m_left) > 0)
			p->m_left = rotateleft(p->m_left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

NodePtr CNode::insert(NodePtr root, NodePtr newNode) // вставка ключа k в дерево с корнем p
{
	if (!root) return newNode;
	if (newNode->m_key < root->m_key)
		root->m_left = insert(root->m_left, newNode);
	else
		root->m_right = insert(root->m_right, newNode);
	return balance(root);
}

NodePtr CNode::findmin(NodePtr p) // поиск узла с минимальным ключом в дереве p 
{
	return p->m_left ? findmin(p->m_left) : p;
}

NodePtr CNode::removemin(NodePtr p) // удаление узла с минимальным ключом из дерева p
{
	if (p->m_left == 0)
		return p->m_right;
	p->m_left = removemin(p->m_left);
	return balance(p);
}

NodePtr CNode::remove(NodePtr p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->m_key)
		p->m_left = remove(p->m_left, k);
	else if (k > p->m_key)
		p->m_right = remove(p->m_right, k);
	else //  k == p->key 
	{
		NodePtr q = p->m_left;
		NodePtr r = p->m_right;
		p = nullptr;
		if (!r) return q;
		NodePtr min = findmin(r);
		min->m_right = removemin(r);
		min->m_left = q;
		return balance(min);
	}
	return balance(p);
}