#pragma once

class CTree;
typedef std::shared_ptr<CTree> TreePtr;

class CTree
{
public:
	CTree(int k);
	~CTree();

	unsigned char height(TreePtr p);
	int bfactor(TreePtr p);
	void fixheight(TreePtr p);
	TreePtr rotateright(TreePtr p); // правый поворот вокруг p
	TreePtr rotateleft(TreePtr q); // левый поворот вокруг q
	TreePtr balance(TreePtr p); // балансировка узла p
	TreePtr insert(TreePtr p, int k); // вставка ключа k в дерево с корнем p
	TreePtr findmin(TreePtr p); // поиск узла с минимальным ключом в дереве p 
	TreePtr removemin(TreePtr p); // удаление узла с минимальным ключом из дерева p
	TreePtr remove(TreePtr p, int k); // удаление ключа k из дерева p

private:
	int m_key;
	unsigned char m_height;
	TreePtr m_left;
	TreePtr m_right;
};

