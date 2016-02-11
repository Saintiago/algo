#include "stdafx.h"
#include "../Dijkstra/Node.h"

struct Node_
{
	CNode node;
	Node_()
	{
		node.AddLink(0, 14);
		node.AddLink(1, 7);
		node.AddLink(2, 9);
	}
};
// Узел
BOOST_FIXTURE_TEST_SUITE(Node, Node_)

	// может добавлять новые связи
	BOOST_AUTO_TEST_CASE(can_add_new_links_to_itself)
	{
		node.AddLink(3, 3);
		BOOST_CHECK_EQUAL(node.GetLinks().size(), 4);
		BOOST_CHECK_EQUAL(node.GetLinks().at(0).second, 3);
		BOOST_CHECK_EQUAL(node.GetLinks().at(1).second, 7);
		BOOST_CHECK_EQUAL(node.GetLinks().at(2).second, 9);
		BOOST_CHECK_EQUAL(node.GetLinks().at(3).second, 14);
	}

BOOST_AUTO_TEST_SUITE_END()