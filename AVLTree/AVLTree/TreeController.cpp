#include "stdafx.h"
#include "TreeController.h"

using namespace std;

CTreeController::CTreeController()
{
}


CTreeController::~CTreeController()
{
}


void CTreeController::ReadTree(ifstream & in)
{
	while (!in.eof())
	{
		m_root = m_root->insert(m_root, MakeNode(in));
	}
}

void CTreeController::WriteTree(ostream & out)
{
	WriteNode(m_root, out);
}

void CTreeController::WriteNode(NodePtr root, ostream & out)
{
	if (root->m_left != nullptr)
	{
		WriteNode(root->m_left, out);
		out << endl;
	}
	
	out << root->m_key << " " << root->m_data;

	if (root->m_right != nullptr)
	{
		out << endl;
		WriteNode(root->m_right, out);
	}
}

NodePtr CTreeController::MakeNode(std::ifstream & in)
{
	string lineOfText;
	getline(in, lineOfText);
	stringstream ss(lineOfText);
	int key;
	string name;
	ss >> key >> name;
	return make_shared<CNode>(key, name);
}

std::string CTreeController::GetRecord(int key)
{
	NodePtr node = GetNode(m_root, key);
	stringstream ss;
	ss << node->m_key << " " << node->m_data;
	return ss.str();
}

NodePtr CTreeController::GetNode(NodePtr root, int key)
{
	if (root->m_left != nullptr && key < root->m_key)
	{
		return GetNode(root->m_left, key);
	}
	if (root->m_key == key)
	{
		return root;
	}
	if (root->m_right != nullptr && key > root->m_key)
	{
		return GetNode(root->m_right, key);
	}
	throw out_of_range("There is no element with key " + key);
}

void CTreeController::AddRecord(int key, std::string data)
{
	m_root->insert(m_root, make_shared<CNode>(key, data));
}

bool CTreeController::IsSet(int key)
{
	try
	{
		GetNode(m_root, key);
		return true;
	}
	catch (out_of_range e)
	{
		return false;
	}
}