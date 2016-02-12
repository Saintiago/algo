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
	TreePtr rotateright(TreePtr p); // ������ ������� ������ p
	TreePtr rotateleft(TreePtr q); // ����� ������� ������ q
	TreePtr balance(TreePtr p); // ������������ ���� p
	TreePtr insert(TreePtr p, int k); // ������� ����� k � ������ � ������ p
	TreePtr findmin(TreePtr p); // ����� ���� � ����������� ������ � ������ p 
	TreePtr removemin(TreePtr p); // �������� ���� � ����������� ������ �� ������ p
	TreePtr remove(TreePtr p, int k); // �������� ����� k �� ������ p

private:
	int m_key;
	unsigned char m_height;
	TreePtr m_left;
	TreePtr m_right;
};

