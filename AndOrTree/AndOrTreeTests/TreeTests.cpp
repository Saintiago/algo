#include "stdafx.h"
#include "../AndOrTree/Tree.h"

struct TreeFixture
{
	CTree tree;
};

// ������
BOOST_FIXTURE_TEST_SUITE(tree, TreeFixture)

	// ����� ���� �������� � ����� ������
	BOOST_AUTO_TEST_CASE(can_be_written_to_file)
	{
	}

	// ��������� ������
	BOOST_AUTO_TEST_CASE(is_empty_by_default)
	{

	}

	// ����� ���� ������� �� ������ �����
	BOOST_AUTO_TEST_CASE(can_be_read_from_file)
	{
	}
	
BOOST_AUTO_TEST_SUITE_END()