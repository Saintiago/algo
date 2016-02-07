#include "stdafx.h"
#include "../Dijkstra/Node.h"

struct Node_
{
	CNode node;
	Node_()
	{
		node.AddLink(std::make_shared<CNode>(), 14);
		node.AddLink(std::make_shared<CNode>(), 7);
		node.AddLink(std::make_shared<CNode>(), 9);
	}
};
// Узел
BOOST_FIXTURE_TEST_SUITE(Node, Node_)

	// может добавлять новые связи
	BOOST_AUTO_TEST_CASE(can_add_new_links_to_itself)
	{
		node.AddLink(std::make_shared<CNode>(), 3);
		BOOST_CHECK_EQUAL(node.GetLinks().size(), 4);
		BOOST_CHECK_EQUAL(node.GetLinks().at(3)->second, 3);
	}

	// @TODO может отсортировать свои связи по длине пути
	BOOST_AUTO_TEST_CASE(can_sort_own_links_by_path)
	{
		//BOOST_CHECK_NO_THROW(node.SortLinks());
	}

BOOST_AUTO_TEST_SUITE_END()