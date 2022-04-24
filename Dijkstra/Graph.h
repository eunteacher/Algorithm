#pragma once
#include <iostream>
#include "PriorityQueue.h"
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

	void Dijkstra(Node* startNode, Graph<T>* graph)
	{
		int* weights = new int[Count]; // 가중치 
		Node** shorts = new Node*[Count]; // 가장 짧은 경로
		Node** connected = new Node*[Count]; // 연결된 노드
		Node** parents = new Node*[Count]; // 부모 노드

		Edge* currentEdge = NULL;
		Node* currentNode = Head;

		// 매개변수 graph에 노드 추가
		for (int index = 0; currentNode != NULL; index++)
		{
			Node* newNode = CreateNode(currentNode->Data);
			graph->AddNode(newNode);

			weights[index] = INT_MAX;
			shorts[index] = newNode;
			connected[index] = NULL;
			parents[index] = NULL;

			currentNode = currentNode->Next;
		}

		// 우선순위 큐 
		// 우선순위 큐를 사용하는 이유는 시작 복잡도가 O(E + VLog(V))이고, 사용 안하면 O(V^2)이다.
		PriorityQueue<Node *> queue(10);
		typename PriorityQueue<Node *>::Node startQNode = PriorityQueue<Node *>::Node(0, startNode); // 시작 노드는 가중치를 0으로 설정

		// 큐에 추가
		queue.Insert(startQNode);
		weights[startNode->Index] = 0;

		// 큐가 비어있다의 의미는 모든 노드를 다 방문했다는 의미
		// 모든 노드를 방문하는 반복문
		while (queue.Empty() == false)
		{
			typename PriorityQueue<Node *>::Node poped = queue.RemoveMin(); // 우선 순위가 가장 높은 노드를 pop
			currentNode = poped.Data;

			connected[currentNode->Index] = currentNode;

			currentEdge = currentNode->Edge;
			// 인접한 노드들이 없을 때 까지 반복문 수행
			while (currentEdge != NULL)
			{
				Node* targetNode = currentEdge->Target;

				//if (connected[targetNode->Index] == NULL && weights[currentNode->Index] * currentEdge->Weight < weights[targetNode->Index]) // 널값이면 도달x
				//{
				//	아래 코드와 동일함
				//}
				// 아래 코드처럼 작성 시 좋은 점 : 보기 좋음
				bool b = true;
				b &= connected[targetNode->Index] == NULL; // 방문한 노드인지 체크
				b &= weights[currentNode->Index] + currentEdge->Weight < weights[targetNode->Index]; // 인접한 노드의 가중치 비교

				if (b == true)
				{
					// 위 조건이 전부 true라면 큐에 삽입
					typename PriorityQueue<Node *>::Node newNode = PriorityQueue<Node *>::Node(currentEdge->Weight, targetNode);
					queue.Insert(newNode);

					parents[targetNode->Index] = currentEdge->Start; // 이전 노드
					weights[targetNode->Index] = weights[currentNode->Index] + currentEdge->Weight; // 가중치 합을 계산하고 기록
				} // if(b)

				currentEdge = currentEdge->Next;
			}// while(currentEdge)

		}

		for (int i = 0; i < Count; i++)
		{
			if (parents[i] == NULL) // 헤드노드라면
			{
				continue;
			}

			int start = parents[i]->Index;
			int target = i;

			// 방향성 그래프이기떄문에 부모 -> 자식만
			graph->AddEdge(shorts[start], Graph<T>::CreateEdge(shorts[start], shorts[target], weights[i]));

			cout << shorts[start]->Data << ", " << shorts[target]->Data << ", " << weights[i] << endl;
		}
		cout << endl;

		delete[] weights;
		delete[] parents;
		delete[] connected;
		delete[] shorts;
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
