#include "stdafx.h"
#include "Tree.h"

using namespace std;

CTree::CTree(int k)
{
	m_key = k; 
	m_left = m_right = 0; 
	m_height = 1;
}


CTree::~CTree()
{
}

unsigned char CTree::height(TreePtr p)
{
	return p ? p->m_height : 0;
}

int CTree::bfactor(TreePtr p)
{
	return height(p->m_right) - height(p->m_left);
}

void CTree::fixheight(TreePtr p)
{
	unsigned char hl = height(p->m_left);
	unsigned char hr = height(p->m_right);
	p->m_height = (hl>hr ? hl : hr) + 1;
}

TreePtr CTree::rotateright(TreePtr p) // правый поворот вокруг p
{
	TreePtr q = p->m_left;
	p->m_left = q->m_right;
	q->m_right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

TreePtr CTree::rotateleft(TreePtr q) // левый поворот вокруг q
{
	TreePtr p = q->m_right;
	q->m_right = p->m_left;
	p->m_left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

TreePtr CTree::balance(TreePtr p) // балансировка узла p
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

TreePtr CTree::insert(TreePtr p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return make_shared<CTree>(k);
	if (k<p->m_key)
		p->m_left = insert(p->m_left, k);
	else
		p->m_right = insert(p->m_right, k);
	return balance(p);
}

TreePtr CTree::findmin(TreePtr p) // поиск узла с минимальным ключом в дереве p 
{
	return p->m_left ? findmin(p->m_left) : p;
}

TreePtr CTree::removemin(TreePtr p) // удаление узла с минимальным ключом из дерева p
{
	if (p->m_left == 0)
		return p->m_right;
	p->m_left = removemin(p->m_left);
	return balance(p);
}

TreePtr CTree::remove(TreePtr p, int k) // удаление ключа k из дерева p
{
	if (!p) return 0;
	if (k < p->m_key)
		p->m_left = remove(p->m_left, k);
	else if (k > p->m_key)
		p->m_right = remove(p->m_right, k);
	else //  k == p->key 
	{
		TreePtr q = p->m_left;
		TreePtr r = p->m_right;
		p = nullptr;
		if (!r) return q;
		TreePtr min = findmin(r);
		min->m_right = removemin(r);
		min->m_left = q;
		return balance(min);
	}
	return balance(p);
}