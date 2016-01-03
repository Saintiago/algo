#include "stdafx.h"
#include "../parser21/Stack.h"

BOOST_AUTO_TEST_SUITE(StackTests);

	BOOST_AUTO_TEST_CASE(StackIsEmpty)
	{
		Stack stack;

		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
		stack.Push("Hello");
		BOOST_CHECK_EQUAL(stack.IsEmpty(), false);
	}

	BOOST_AUTO_TEST_CASE(StackPush)
	{
		Stack stack;
		stack.Push("1");
		BOOST_CHECK_EQUAL(stack.GetHeadData(), "1");
		stack.Push("2");
		BOOST_CHECK_EQUAL(stack.GetHeadData(), "2");
		stack.Push("3");
		BOOST_CHECK_EQUAL(stack.GetHeadData(), "3");
	}

	BOOST_AUTO_TEST_CASE(StackPop)
	{
		Stack stack;
		stack.Push("1");
		stack.Push("2");
		stack.Push("3");
		BOOST_CHECK_EQUAL(stack.Pop(), "3");
		BOOST_CHECK_EQUAL(stack.Pop(), "2");
		BOOST_CHECK_EQUAL(stack.Pop(), "1");
	}

	BOOST_AUTO_TEST_CASE(StackClear)
	{
		Stack stack;
		stack.Push("1");
		stack.Push("2");
		stack.Clear();
		BOOST_CHECK_EQUAL(stack.IsEmpty(), true);
	}

BOOST_AUTO_TEST_SUITE_END();