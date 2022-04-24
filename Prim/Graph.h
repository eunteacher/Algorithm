#pragma once
#include <iostream>
#include "PriorityQueue.h"
using namespace std;

template<typename T>
class Graph
{
public:
	// ���� ���� 
	struct Node;
	struct Edge;

public:
	// ��� �߰� �Լ� 
	void AddNode(Node* node)
	{
		Node* nodeList = Head;

		if (nodeList != NULL) // ����� ��尡 �����ϴ� ���
		{
			// ���� ��尡 ���� ������ �ݺ� 
			while (nodeList->Next != NULL)
			{
				nodeList = nodeList->Next;
			}

			// ������ ��忡 ��带 �߰��� ���� 
			nodeList->Next = node;

		}
		else // ����� ��尡 �������� �ʴ� ��� 
		{
			Head = node;
		}

		node->Index = Count++;
	}

	// ���� �߰� �Լ�
	void AddEdge(Node* node, Edge* edge)
	{
		if (node->Edge != NULL) // ��忡 ������ ����� ��� 
		{
			Edge* edgeList = node->Edge;

			// ���� ������ ���� ������ �ݺ� 
			while (edgeList->Next != NULL)
			{
				edgeList = edgeList->Next;
			}

			edgeList->Next = edge;
		}
		else // ��忡 ����� ������ ���� ��� 
		{
			node->Edge = edge;
		}
	}

	// �׷��� ��� �Լ� 
	void Print()
	{
		Node* node = NULL;
		Edge* edge = NULL;

		node = Head;
		// ��尡 NULL�̸� ���� 
		if (node == NULL)
			return;

		while (node != NULL)
		{
			cout << node->Data << " : ";

			// ����� ������ NULL
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
		// ���� ���� ����
		Node* currentNode = NULL;
		Edge* currentEdge = NULL;
		
		// ���� �迭�� �����ϴ� ������ �� ��忡 ���� �迭�� �����ϱ� ���ؼ�
		int* weights = new int[Count]; // ����ġ
		// ���������� ���� �Ҵ�
		Node** mstNodes = new Node*[Count]; // �ּ� ��� ���� Ʈ�� ���
		Node** linked = new Node*[Count]; // ģ�� ���
		Node** parents = new Node*[Count];  // �θ� ���

		int index = 0;
		currentNode = Head;

		// �׷��� ���� �� �ʱ�ȭ 
		while (currentNode != NULL)
		{
			// ����ƽ �����̱� ������ �ڱ� ����� ������ ����
			Graph<T>::Node* newNode = CreateNode(currentNode->Data);

			graph->AddNode(newNode); // �Ű����� �׷����� ��� �߰� 

			weights[index] = INT_MAX; // ����ġ�� int���� �ִ����� �ʱⰪ ����
			mstNodes[index] = newNode; // mst�� ��� �߰� 
			linked[index] = NULL; // ����� ���
			parents[index] = NULL; // �θ� �ڽ� ���� 
			currentNode = currentNode->Next;

			index++;
		}

		PriorityQueue<Node* > queue(10);
		typename PriorityQueue<Node* >::Node startQueueNode = PriorityQueue<Node*>::Node(0, startNode); // ���� ����� ����ġ�� 0���� ����

		queue.Insert(startQueueNode);
		weights[startNode->Index] = 0; // ���� ����� ����ġ ���� 0

		// ��� ��带 Ž���Ͽ� linked, parnets, weights�� �� �Ǵ� ��� �߰�
		while (queue.Empty() == false) // ť�� ����ִ� == ��� ��带 Ž�� 
		{
			typename PriorityQueue<Node *>::Node poped = queue.RemoveMin(); // ����ġ�� ���� ���� ��带 pop

			currentNode = poped.Data;
			linked[currentNode->Index] = currentNode; // linked�� ���� ��带 �߰� 

			currentEdge = currentNode->Edge;

			// linked�� ���� �̿��Ͽ� parnets �� weights�� �� �߰�
			while (currentEdge != NULL) // ���� ������ NULL ���� �� �� ���� �ݺ�
			{
				Node* targetNode = currentEdge->Target;

				// Ÿ�� ���(����� ���)�� ���� linked�� ���ٸ� NULL && ���� ������ ����ġ�� ���� �� ���� ���
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

		// �ε��� ������ ����ġ ���
		//cout << endl;
		//for (int i = 0; i < Count; i++)
		//{
		//	cout<<i<<", " << weights[i] << " / ";
		//}

		// Ʈ�� ����
		for (int i = 0; i < Count; i++)
		{
			int start, target;
			if (parents[i] == NULL) // ��带 �ǹ�
			{
				continue;
			}

			start = parents[i]->Index; // parnets�� i ��° ����� �ε��� ��
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
	// ���� ���� ����
	struct Node
	{
		T Data;
		int Index = -1;

		Node* Next = NULL; // ���� ��� 
		Edge* Edge = NULL; // ����� ���� 
	};

	struct Edge
	{
		int Weight = 0;

		Node* Start = NULL; // ���� ��� 
		Node* Target = NULL; // Ÿ�� ��� 
		Edge* Next = NULL; // ���� ���� 
	};

public:
	// ���� ���� �Լ� 
	static Edge* CreateEdge(Node* start, Node* target, int Weight)
	{
		Edge* edge = new Edge();

		edge->Weight = Weight;
		edge->Start = start;
		edge->Target = target;
		edge->Next = NULL;

		return edge;
	}

	// ��� ���� �Լ� 
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
