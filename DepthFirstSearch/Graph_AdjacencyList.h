#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Graph_AdjacencyList
{
public:
	// 전방 선언 
	struct Node;
	struct Edge;

public:
	// 노드 추가 함수 
	void AddNode(Node* node)
	{
		Node* nodeList = Head;

		if (nodeList != NULL) // 연결된 노드가 존재하는 경우
		{
			// 다음 노드가 없는 경우까지 반복 
			while (nodeList->Next != NULL)
			{
				nodeList = nodeList->Next;
			}

			// 마지막 노드에 노드를 추가로 연결 
			nodeList->Next = node;

		}
		else // 연결된 노드가 존재하지 않는 경우 
		{
			Head = node;
		}

		node->Index = Count++;
	}

	// 엣지 추가 함수
	void AddEdge(Node* node, Edge* edge)
	{
		if (node->Edge != NULL) // 노드에 엣지가 연결된 경우 
		{
			Edge* edgeList = node->Edge;

			// 다음 엣지가 없는 경우까지 반복 
			while (edgeList->Next != NULL)
			{
				edgeList = edgeList->Next;
			}

			edgeList->Next = edge;
		}
		else // 노드에 연결된 엣지가 없는 경우 
		{
			node->Edge = edge;
		}
	}

	// 그래프 출력 함수 
	void Print()
	{
		Node* node = NULL;
		Edge* edge = NULL;

		node = Head;
		// 헤드가 NULL이면 리턴 
		if (node == NULL)
			return;

		while (node != NULL)
		{
			cout << node->Data << " : ";

			// 노드의 엣지가 NULL
			edge = node->Edge;
			if (edge == NULL)
			{
				node = node->Next;
				cout << endl;

				continue;
			}

			while (edge != NULL)
			{
				cout << edge->Target->Data;
				edge = edge->Next;
			}

			cout << endl;

			node = node->Next;
		}

		cout << endl;
	}

	void DFS(Node* node)
	{
		cout << node->Data << " ";
		node->Visited = true; // 방문

		Edge* edge = node->Edge;
		while (edge != NULL)
		{
			if (edge->Target != NULL && edge->Target->Visited == false) // 다음 엣지가 존재하고 방문하지 않는 노드라면
			{
				DFS(edge->Target); // 다음 엣지로 재귀
			}

			edge = edge->Next; // 다음 엣지로
		}
	}

public:
	// 노드와 엣지 정의
	struct Node
	{
		T Data;
		int Index = -1;
		bool Visited = false;

		Node* Next = NULL; // 다음 노드 
		Edge* Edge = NULL; // 연결된 엣지 
	};

	struct Edge
	{
		Node* Start = NULL; // 시작 노드 
		Node* Target = NULL; // 타겟 노드 
		Edge* Next = NULL; // 다음 엣지 
	};

public:
	// 엣지 생성 함수 
	static Edge* CreateEdge(Node* start, Node* target)
	{
		Edge* edge = new Edge();

		edge->Start = start;
		edge->Target = target;
		edge->Next = NULL;

		return edge;
	}

	// 노드 생성 함수 
	static Node* CreateNode(T data)
	{
		Node* node = new Node();

		node->Data = data;

		return node;
	}

private:
	Node* Head = NULL;
	int Count = 0;
};
