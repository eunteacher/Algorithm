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

	void Dijkstra(Node* startNode, Graph<T>* graph)
	{
		int* weights = new int[Count]; // ����ġ 
		Node** shorts = new Node*[Count]; // ���� ª�� ���
		Node** connected = new Node*[Count]; // ����� ���
		Node** parents = new Node*[Count]; // �θ� ���

		Edge* currentEdge = NULL;
		Node* currentNode = Head;

		// �Ű����� graph�� ��� �߰�
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

		// �켱���� ť 
		// �켱���� ť�� ����ϴ� ������ ���� ���⵵�� O(E + VLog(V))�̰�, ��� ���ϸ� O(V^2)�̴�.
		PriorityQueue<Node *> queue(10);
		typename PriorityQueue<Node *>::Node startQNode = PriorityQueue<Node *>::Node(0, startNode); // ���� ���� ����ġ�� 0���� ����

		// ť�� �߰�
		queue.Insert(startQNode);
		weights[startNode->Index] = 0;

		// ť�� ����ִ��� �ǹ̴� ��� ��带 �� �湮�ߴٴ� �ǹ�
		// ��� ��带 �湮�ϴ� �ݺ���
		while (queue.Empty() == false)
		{
			typename PriorityQueue<Node *>::Node poped = queue.RemoveMin(); // �켱 ������ ���� ���� ��带 pop
			currentNode = poped.Data;

			connected[currentNode->Index] = currentNode;

			currentEdge = currentNode->Edge;
			// ������ ������ ���� �� ���� �ݺ��� ����
			while (currentEdge != NULL)
			{
				Node* targetNode = currentEdge->Target;

				//if (connected[targetNode->Index] == NULL && weights[currentNode->Index] * currentEdge->Weight < weights[targetNode->Index]) // �ΰ��̸� ����x
				//{
				//	�Ʒ� �ڵ�� ������
				//}
				// �Ʒ� �ڵ�ó�� �ۼ� �� ���� �� : ���� ����
				bool b = true;
				b &= connected[targetNode->Index] == NULL; // �湮�� ������� üũ
				b &= weights[currentNode->Index] + currentEdge->Weight < weights[targetNode->Index]; // ������ ����� ����ġ ��

				if (b == true)
				{
					// �� ������ ���� true��� ť�� ����
					typename PriorityQueue<Node *>::Node newNode = PriorityQueue<Node *>::Node(currentEdge->Weight, targetNode);
					queue.Insert(newNode);

					parents[targetNode->Index] = currentEdge->Start; // ���� ���
					weights[targetNode->Index] = weights[currentNode->Index] + currentEdge->Weight; // ����ġ ���� ����ϰ� ���
				} // if(b)

				currentEdge = currentEdge->Next;
			}// while(currentEdge)

		}

		for (int i = 0; i < Count; i++)
		{
			if (parents[i] == NULL) // �������
			{
				continue;
			}

			int start = parents[i]->Index;
			int target = i;

			// ���⼺ �׷����̱⋚���� �θ� -> �ڽĸ�
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
