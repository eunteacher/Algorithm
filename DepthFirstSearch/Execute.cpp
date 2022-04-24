#include "Graph_AdjacencyMaterix.h"
#include "Graph_AdjacencyList.h"

int main()
{
	cout << "---------- 인접 행렬 ----------" << '\n';
	Graph_AdjacencyMaterix graph;
	graph.AddNodeData('A');
	graph.AddNodeData('B');
	graph.AddNodeData('C');
	graph.AddNodeData('D');
	graph.AddNodeData('E');

	graph.AddEdge(0, 1, true);
	graph.AddEdge(0, 2, true);

	graph.AddEdge(1, 2, true);
	graph.AddEdge(1, 3, true);

	graph.AddEdge(2, 4, true);

	graph.AddEdge(3, 2, true);
	graph.AddEdge(3, 4, true);

	graph.Print();
	cout << '\n';
	cout << "DFS : ";
	graph.DFS(0);
	cout << '\n';
	cout << "---------- 인접 리스트 ----------" << '\n';
	Graph_AdjacencyList<char> graph2;
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

	graph2.AddNode(node1);
	graph2.AddNode(node2);
	graph2.AddNode(node3);
	graph2.AddNode(node4);
	graph2.AddNode(node5);

	graph2.AddEdge(node1, edge1);
	graph2.AddEdge(node1, edge2);

	graph2.AddEdge(node2, edge3);
	graph2.AddEdge(node2, edge4);

	graph2.AddEdge(node3, edge5);

	graph2.AddEdge(node4, edge6);
	graph2.AddEdge(node4, edge7);

	graph2.Print();
	cout << "DFS : ";
	graph2.DFS(node1);

	return 0;
}