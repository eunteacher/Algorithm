#include "Graph.h"

int main()
{
	// 그래프와 노드 생성 
	Graph<char> graph;
	Graph<char>::Node* A = Graph<char>::CreateNode('A');
	Graph<char>::Node* B = Graph<char>::CreateNode('B');
	Graph<char>::Node* C = Graph<char>::CreateNode('C');
	Graph<char>::Node* D = Graph<char>::CreateNode('D');
	Graph<char>::Node* E = Graph<char>::CreateNode('E');
	Graph<char>::Node* F = Graph<char>::CreateNode('F');
	Graph<char>::Node* G = Graph<char>::CreateNode('G');
	Graph<char>::Node* H = Graph<char>::CreateNode('H');
	Graph<char>::Node* I = Graph<char>::CreateNode('I');

	// 노드 추가 
	graph.AddNode(A);
	graph.AddNode(B);
	graph.AddNode(C);
	graph.AddNode(D);
	graph.AddNode(E);
	graph.AddNode(F);
	graph.AddNode(G);
	graph.AddNode(H);
	graph.AddNode(I);


	// 엣지 추가
	graph.AddEdge(A, Graph<char>::CreateEdge(A, E, 247));

	graph.AddEdge(B, Graph<char>::CreateEdge(B, A, 35));
	graph.AddEdge(B, Graph<char>::CreateEdge(B, C, 126));
	graph.AddEdge(B, Graph<char>::CreateEdge(B, F, 150));

	graph.AddEdge(C, Graph<char>::CreateEdge(C, D, 117));
	graph.AddEdge(C, Graph<char>::CreateEdge(C, F, 162));
	graph.AddEdge(C, Graph<char>::CreateEdge(C, G, 220));

	graph.AddEdge(E, Graph<char>::CreateEdge(E, H, 98));

	graph.AddEdge(F, Graph<char>::CreateEdge(F, E, 82));
	graph.AddEdge(F, Graph<char>::CreateEdge(F, G, 154));
	graph.AddEdge(F, Graph<char>::CreateEdge(F, H, 120));

	graph.AddEdge(G, Graph<char>::CreateEdge(G, I, 106));

	cout << "프림 알고리즘 " << endl;
	Graph<char> prim;
	graph.Prim(B, &prim);
	prim.Print();
	cout << endl;

	return 0;
}