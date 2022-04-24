#include "Graph_AdjacencyList.h"

int main()
{
	Graph_AdjacencyList<char> graph;
	Graph_AdjacencyList<char>::Node* node1 = Graph_AdjacencyList<char>::CreateNode('A');
	Graph_AdjacencyList<char>::Node* node2 = Graph_AdjacencyList<char>::CreateNode('B');
	Graph_AdjacencyList<char>::Node* node3 = Graph_AdjacencyList<char>::CreateNode('C');
	Graph_AdjacencyList<char>::Node* node4 = Graph_AdjacencyList<char>::CreateNode('D');
	Graph_AdjacencyList<char>::Node* node5 = Graph_AdjacencyList<char>::CreateNode('E');

	Graph_AdjacencyList<char>::Edge* edge1 = Graph_AdjacencyList<char>::CreateEdge(node1, node2);
	Graph_AdjacencyList<char>::Edge* edge2 = Graph_AdjacencyList<char>::CreateEdge(node1, node3);

	Graph_AdjacencyList<char>::Edge* edge3 = Graph_AdjacencyList<char>::CreateEdge(node2, node3);
	Graph_AdjacencyList<char>::Edge* edge4 = Graph_AdjacencyList<char>::CreateEdge(node2, node4);

	Graph_AdjacencyList<char>::Edge* edge5 = Graph_AdjacencyList<char>::CreateEdge(node3, node4);

	Graph_AdjacencyList<char>::Edge* edge6 = Graph_AdjacencyList<char>::CreateEdge(node4, node2);
	Graph_AdjacencyList<char>::Edge* edge7 = Graph_AdjacencyList<char>::CreateEdge(node4, node5);

	graph.AddNode(node1);
	graph.AddNode(node2);
	graph.AddNode(node3);
	graph.AddNode(node4);
	graph.AddNode(node5);

	graph.AddEdge(node1, edge1);
	graph.AddEdge(node1, edge2);

	graph.AddEdge(node2, edge3);
	graph.AddEdge(node2, edge4);

	graph.AddEdge(node3, edge5);

	graph.AddEdge(node4, edge6);
	graph.AddEdge(node4, edge7);

	graph.Print();
	cout << "DFS : ";
	graph.DFS(node1);
	cout << '\n';
	graph.TopologySort(node1);
	cout << "TopologySort : ";
	graph.TopologySortPrint();

	return 0;
}