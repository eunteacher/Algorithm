#pragma once
#include <iostream>
#include "PriorityQueue.h"
#include "DisjointSet.h"
using namespace std;

template<typename T>
class Graph
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

	// 크루스칼 알고리즘
	// Graph<T>* graph : 크루스칼 알고리즘을 구현할 그래프
	void Krukal(Graph<T>* graph)
	{
		Node** mstNodes = new Node*[Count];
		PriorityQueue<Edge *> queue(10); // 가중치의 오름 차순때문에 일정한 순서로 보장하는 우선순위 큐를 사용

		// 합집합과 탐색을 위해서 DisjointSet 선언
		auto** sets = new typename DisjointSet<Node *>::Set*[Count];

		int index = 0;
		Node* currentNode = Head;
		Edge* currentEdge = NULL;

		// 우선 순위 큐를 사용하여 오름 차순 정렬
		while (currentNode != NULL) // 현재 노드가 NULL 값이 될 때까지 반복
		{
			sets[index] = DisjointSet<Node *>::CreateSet(currentNode); // set 생성
			mstNodes[index] = CreateNode(currentNode->Data); // 현재 노드의 데이터로 새로운 노드를 생성하여 mst에 삽입
			graph->AddNode(mstNodes[index]); // 노드 추가

			currentEdge = currentNode->Edge;

			// 현재 노드의 연결된 모든 간선을 오름 차순으로 정렬
			while (currentEdge != NULL) // 간선이 NULL 값이 될 때까지 반복
			{
				typename PriorityQueue<Edge *>::Node newNode = PriorityQueue<Edge *>::Node(currentEdge->Weight, currentEdge);
				queue.Insert(newNode); // 우선 순위 큐에 삽입 -> 가중치가 낮은 순서로 정렬

				currentEdge = currentEdge->Next; // 다음 엣지로
			}

			currentNode = currentNode->Next; // 다음 노드로
			index++;
		}

		// 분리 집합
		while (queue.Empty() == false)
		{
			// 우선 순위가 가장 높은 노드를 pop -> 즉 가중치가 가장 낮은 간선
			typename PriorityQueue<Edge *>::Node poped = queue.RemoveMin();
			currentEdge = poped.Data; // 현재 Data의 자료형은 Edge이기 떄문에 가능

			int start = currentEdge->Start->Index; // 시작 노드의 Index
			int target = currentEdge->Target->Index; // 타겟 노드의 Index

			// 사이클 형성을 막음
			if (DisjointSet<Node *>::FindSet(sets[start]) == DisjointSet<Node *>::FindSet(sets[target]))
				continue;

			DisjointSet<Node *>::UnionSet(sets[start], sets[target]); // Union-Find 시작 : 합집합 -> 탐색

			// 그래프에 엣지 추가 
			graph->AddEdge(mstNodes[start], Graph<T>::CreateEdge(mstNodes[start], mstNodes[target], currentEdge->Weight));
			graph->AddEdge(mstNodes[target], Graph<T>::CreateEdge(mstNodes[target], mstNodes[start], currentEdge->Weight));

			// 데이터 출력
			cout << mstNodes[start]->Data << "->" << mstNodes[target]->Data << ", " << currentEdge->Weight << endl;
		}

		delete[] sets;
		delete[] mstNodes;

		cout << endl;
	}


public:
	// 노드와 엣지 정의
	struct Node
	{
		T Data;
		int Index = -1;

		Node* Next = NULL; // 다음 노드 
		Edge* Edge = NULL; // 연결된 엣지 
	};

	struct Edge
	{
		int Weight = 0;

		Node* Start = NULL; // 시작 노드 
		Node* Target = NULL; // 타겟 노드 
		Edge* Next = NULL; // 다음 엣지 
	};

public:
	// 엣지 생성 함수 
	static Edge* CreateEdge(Node* start, Node* target, int Weight)
	{
		Edge* edge = new Edge();

		edge->Weight = Weight;
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
