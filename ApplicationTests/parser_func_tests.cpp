#include "stdafx.h"
#include "../parser21/parser_func.h"

BOOST_AUTO_TEST_SUITE(ParserTests);

	BOOST_AUTO_TEST_CASE(ToLowerTest)
	{
		BOOST_CHECK_EQUAL(ToLower(""), "");
		BOOST_CHECK_EQUAL(ToLower("Q"), "q");
		BOOST_CHECK_EQUAL(ToLower("BEGIN"), "begin");
		BOOST_CHECK_EQUAL(ToLower("RePeAt_UNtil. "), "repeat_until. ");
	}

	BOOST_AUTO_TEST_CASE(TrimTest)
	{
		BOOST_CHECK_EQUAL(Trim("Q;"), "Q");
		BOOST_CHECK_EQUAL(Trim("BEGIN."), "BEGIN");
		BOOST_CHECK_EQUAL(Trim(".REPEAT_UNTIL"), ".REPEAT_UNTIL");
	}

	BOOST_AUTO_TEST_CASE(CheckWordTest)
	{
		Stack codeStack;
		BOOST_CHECK_EQUAL(CheckWord("BEGIN"), true);
		BOOST_CHECK_EQUAL(CheckWord("REPEAT"), true);
		BOOST_CHECK_EQUAL(CheckWord("UNTIL"), true);
		BOOST_CHECK_EQUAL(CheckWord("END"), true);
		codeStack.Clear();
		BOOST_CHECK_EQUAL(CheckWord("BEGIN"), true);
		BOOST_CHECK_EQUAL(CheckWord("UNTIL"), false);
		codeStack.Clear();
		BOOST_CHECK_EQUAL(CheckWord("END"), false);
	}

	BOOST_AUTO_TEST_CASE(FindFirstBoundaryTests)
	{
		BOOST_CHECK_EQUAL(FindFirstBoundary(""), string::npos);
		BOOST_CHECK_EQUAL(FindFirstBoundary("{"), 0);
		BOOST_CHECK_EQUAL(FindFirstBoundary("*)"), string::npos);
		BOOST_CHECK_EQUAL(FindFirstBoundary("qwerty(*"), 6);
		BOOST_CHECK_EQUAL(FindFirstBoundary("qwer\"ty(*{\""), 4);
		BOOST_CHECK_EQUAL(FindFirstBoundary("BEGIN '{(*REPEAT*)}' END."), 6);
	}

	BOOST_AUTO_TEST_CASE(RemoveBounadriesTests)
	{
		BOOST_CHECK_EQUAL(RemoveBounadries(""), "");
		BOOST_CHECK_EQUAL(RemoveBounadries("{}"), "");
		
		BOOST_CHECK_EQUAL(RemoveBounadries("}"), "}");
		BOOST_CHECK_EQUAL(RemoveBounadries("{"), "");
		BOOST_CHECK_EQUAL(RemoveBounadries("}"), "");
		BOOST_CHECK_EQUAL(RemoveBounadries("{}{}{}}"), "}");
		BOOST_CHECK_EQUAL(RemoveBounadries("BEGIN '{(*REPEAT*)}' END."), "BEGIN  END.");
		BOOST_CHECK_EQUAL(RemoveBounadries("BEGIN '{(*REPEAT*)}' } END.(* comment *)"), "BEGIN  } END.");

		BOOST_CHECK_EQUAL(RemoveBounadries("'REPEAT'"), "");
		BOOST_CHECK_EQUAL(RemoveBounadries(" \"REPEAT\""), " ");
		
	}


BOOST_AUTO_TEST_SUITE_END();