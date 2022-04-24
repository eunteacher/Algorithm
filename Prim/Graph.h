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

	void Prim(Node* startNode, Graph<T> * graph)
	{
		// 현재 노드와 엣지
		Node* currentNode = NULL;
		Edge* currentEdge = NULL;
		
		// 이차 배열로 선언하는 이유는 각 노드에 대한 배열을 생성하기 위해서
		int* weights = new int[Count]; // 가중치
		// 이차포인터 동적 할당
		Node** mstNodes = new Node*[Count]; // 최소 비용 신장 트리 노드
		Node** linked = new Node*[Count]; // 친구 노드
		Node** parents = new Node*[Count];  // 부모 노드

		int index = 0;
		currentNode = Head;

		// 그래프 생성 및 초기화 
		while (currentNode != NULL)
		{
			// 스태틱 변수이기 때문에 자기 멤버랑 관련이 없음
			Graph<T>::Node* newNode = CreateNode(currentNode->Data);

			graph->AddNode(newNode); // 매개변수 그래프에 노드 추가 

			weights[index] = INT_MAX; // 가중치를 int형의 최댓값으로 초기값 설정
			mstNodes[index] = newNode; // mst에 노드 추가 
			linked[index] = NULL; // 연결된 노드
			parents[index] = NULL; // 부모 자식 관계 
			currentNode = currentNode->Next;

			index++;
		}

		PriorityQueue<Node* > queue(10);
		typename PriorityQueue<Node* >::Node startQueueNode = PriorityQueue<Node*>::Node(0, startNode); // 시작 노드의 가중치는 0으로 설정

		queue.Insert(startQueueNode);
		weights[startNode->Index] = 0; // 현재 노드의 가중치 값을 0

		// 모든 노드를 탐색하여 linked, parnets, weights에 값 또는 노드 추가
		while (queue.Empty() == false) // 큐가 비어있다 == 모든 노드를 탐색 
		{
			typename PriorityQueue<Node *>::Node poped = queue.RemoveMin(); // 가중치가 가장 낮은 노드를 pop

			currentNode = poped.Data;
			linked[currentNode->Index] = currentNode; // linked에 현재 노드를 추가 

			currentEdge = currentNode->Edge;

			// linked의 값을 이용하여 parnets 와 weights에 값 추가
			while (currentEdge != NULL) // 현재 간선이 NULL 값일 될 떄 까지 반복
			{
				Node* targetNode = currentEdge->Target;

				// 타겟 노드(연결된 노드)가 현재 linked의 없다면 NULL && 현재 간선의 가중치가 값이 더 작을 경우
				if (linked[targetNode->Index] == NULL && currentEdge->Weight < weights[targetNode->Index])
				{
					typename PriorityQueue<Node *>::Node newNode = PriorityQueue<Node *>::Node(currentEdge->Weight, targetNode);
					queue.Insert(newNode);

					parents[targetNode->Index] = currentEdge->Start;
					weights[targetNode->Index] = currentEdge->Weight;
				}

				currentEdge = currentEdge->Next;
			} // while (currnetEdge != NULL)
		} // while (queue.Empty() == false)

		// 인덱스 순으로 가중치 출력
		//cout << endl;
		//for (int i = 0; i < Count; i++)
		//{
		//	cout<<i<<", " << weights[i] << " / ";
		//}

		// 트리 구성
		for (int i = 0; i < Count; i++)
		{
			int start, target;
			if (parents[i] == NULL) // 헤드를 의미
			{
				continue;
			}

			start = parents[i]->Index; // parnets의 i 번째 노드의 인덱스 값
			target = i;

			graph->AddEdge(mstNodes[start], Graph<T>::CreateEdge(mstNodes[start], mstNodes[target], weights[i]));
			graph->AddEdge(mstNodes[target], Graph<T>::CreateEdge(mstNodes[target], mstNodes[start], weights[i]));

			cout << mstNodes[start]->Data << "->" << mstNodes[target]->Data << ", " << weights[i] << endl;
		}

		cout << endl;

		delete[] weights;
		delete[] mstNodes;
		delete[] linked;
		delete[] parents;
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
