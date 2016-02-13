#include "stdafx.h"
#include "../Dijkstra/DijkstraAlgorithm.h"

struct DijkstraAlgorithm_
{
	CDijkstraAlgorithm dijkstra;
	std::ifstream fin;
	DijkstraAlgorithm_()
	{
		fin.open("../input.txt");
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
		BOOST_CHECK_EQUAL(dijkstra.GetStartNode()->GetPath(), 0);
		BOOST_CHECK_THROW(dijkstra.SetStartNode(7), std::out_of_range);
	}

	// может найти кратчайший путь от начальной вершины до конечно
	BOOST_AUTO_TEST_CASE(can_find_shortest_path_from_start_node_to_end_node)
	{
		BOOST_CHECK_EQUAL(dijkstra.FindPathFromStartTo(5), 11);
		dijkstra.GetGraph().ResetPaths();
		dijkstra.SetStartNode(5);
		BOOST_CHECK_EQUAL(dijkstra.FindPathFromStartTo(0), 11);
	}

BOOST_AUTO_TEST_SUITE_END()