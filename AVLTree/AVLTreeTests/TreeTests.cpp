#include "stdafx.h"
#include "../AVLTree/TreeController.h"

using namespace std;

struct TreeController_
{
	CTreeController controller;
	ifstream fin;

	TreeController_()
	{
		fin.open("../input.txt");
		controller.ReadTree(fin);
		
	}
};

string StreamToString(istream & in)
{
	std::istreambuf_iterator<char> eos;
	std::string s(std::istreambuf_iterator<char>(in), eos);
	return s;
}

// АВЛ-дерево
BOOST_FIXTURE_TEST_SUITE(TreeController, TreeController_)

	// может вернуть запись по ключу
	BOOST_AUTO_TEST_CASE(can_return_record_by_key)
	{
		BOOST_CHECK_EQUAL(controller.GetRecord(98), "98 Trajan");
		BOOST_CHECK_THROW(controller.GetRecord(99), out_of_range);
	}

	// может добавить запись
	BOOST_AUTO_TEST_CASE(can_add_record)
	{
		controller.AddRecord(99, "Petya");
		BOOST_CHECK_EQUAL(controller.GetRecord(99), "99 Petya");
	}

BOOST_AUTO_TEST_SUITE_END()