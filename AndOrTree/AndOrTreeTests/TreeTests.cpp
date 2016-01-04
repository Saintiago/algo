#include "stdafx.h"
#include "../AndOrTree/Tree.h"

struct TreeFixture
{
	CTree tree;
};

// Дерево
BOOST_FIXTURE_TEST_SUITE(tree, TreeFixture)

	// создается пустым
	BOOST_AUTO_TEST_CASE(is_empty_by_default)
	{

	}

	// может быть считано из файла
	BOOST_AUTO_TEST_CASE(can_be_read_from_file)
	{
	}

	// может быть записано в файл
	BOOST_AUTO_TEST_CASE(can_be_written_to_file)
	{
	}

BOOST_AUTO_TEST_SUITE_END()