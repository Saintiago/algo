#include "stdafx.h"
#include "../Dijkstra/DijkstraAlgorithm.h"

struct DijkstraAlgorithm_
{
	CDijkstraAlgorithm dijkstra;
	std::ifstream fin;
	DijkstraAlgorithm_()
	{
		fin.open("../Debug/input.txt");
		dijkstra.MakeGraph(fin);
		dijkstra.SetStartNode(0);
	}
};
// Алгоритм Дейкстры
BOOST_FIXTURE_TEST_SUITE(DijkstraAlgorithm, DijkstraAlgorithm_)

	// может получить граф из входящего потока
	BOOST_AUTO_TEST_CASE(can_get_graph_from_input_stream)
	{
		BOOST_CHECK_EQUAL(dijkstra.GetGraph().Size(), 6);
	}

	// может выбрать стартовую вершины графа
	BOOST_AUTO_TEST_CASE(can_set_start_node)
	{
		BOOST_CHECK_EQUAL(dijkstra.GetStartNode()->GetWeight(), 0);
		BOOST_CHECK_THROW(dijkstra.SetStartNode(7), std::out_of_range);
	}

	// может выбрать конечную вершину
	BOOST_AUTO_TEST_CASE(can_set_end_node)
	{
		BOOST_CHECK_NO_THROW(dijkstra.SetEndNode(5));
		BOOST_CHECK_EQUAL(dijkstra.GetEndNode()->GetWeight(), INFINITY);
		BOOST_CHECK_THROW(dijkstra.SetEndNode(7), std::out_of_range);
	}

	// может выбрать вершину с минимальным путем от данной
	BOOST_AUTO_TEST_CASE(can_chose_minimal_path_node_from_given)
	{
		BOOST_CHECK_EQUAL(dijkstra.GetGraph().GetNode(0)->GetWeight, 9);
	}

BOOST_AUTO_TEST_SUITE_END()