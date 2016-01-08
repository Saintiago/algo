#include "stdafx.h"
#include "../AndOrTree/Tree.h"

struct TreeFixture
{
	CTree tree;
};

// Дерево
BOOST_FIXTURE_TEST_SUITE(tree, TreeFixture)

	// может быть записано в поток вывода
	BOOST_AUTO_TEST_CASE(can_be_written_to_file)
	{
	}

	// создается пустым
	BOOST_AUTO_TEST_CASE(is_empty_by_default)
	{

	}

	// может быть считано из потока ввода
	BOOST_AUTO_TEST_CASE(can_be_read_from_file)
	{
	}
	
BOOST_AUTO_TEST_SUITE_END()