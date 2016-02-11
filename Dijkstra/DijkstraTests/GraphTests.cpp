#include "stdafx.h"
#include "../Dijkstra/Graph.h"

struct Graph_
{
	CGraph graph;
	std::ifstream fin;
	Graph_()
	{
		fin.open("../Debug/input.txt");
	}
};
// Граф
BOOST_FIXTURE_TEST_SUITE(Graph, Graph_)

	// может создавать узлы на основе матрицы смежности во входящем потоке
	BOOST_AUTO_TEST_CASE(can_create_nodes_via_adjacency_matrix_in_input_stream)
	{
		graph.CreateByAdjacencyMatrix(fin);
		BOOST_CHECK_EQUAL(graph.Size(), 6);
		BOOST_CHECK_EQUAL(graph.GetNode(0)->GetLinks().size(), 3);

		BOOST_CHECK_EQUAL(graph.GetNode(graph.GetNode(0)->GetLinks().at(0).first)->GetLinks().size(), 3);

		BOOST_CHECK_EQUAL(graph.GetNode(1)->GetLinks().size(), 3);
		BOOST_CHECK_EQUAL(graph.GetNode(2)->GetLinks().size(), 4);
		BOOST_CHECK_EQUAL(graph.GetNode(3)->GetLinks().size(), 3);
		BOOST_CHECK_EQUAL(graph.GetNode(4)->GetLinks().size(), 2);
		BOOST_CHECK_EQUAL(graph.GetNode(5)->GetLinks().size(), 3);
	}

BOOST_AUTO_TEST_SUITE_END()