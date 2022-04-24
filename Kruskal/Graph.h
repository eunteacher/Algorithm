#pragma once
#include <iostream>
#include "PriorityQueue.h"
#include "DisjointSet.h"
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

	// ũ�罺Į �˰���
	// Graph<T>* graph : ũ�罺Į �˰����� ������ �׷���
	void Krukal(Graph<T>* graph)
	{
		Node** mstNodes = new Node*[Count];
		PriorityQueue<Edge *> queue(10); // ����ġ�� ���� ���������� ������ ������ �����ϴ� �켱���� ť�� ���

		// �����հ� Ž���� ���ؼ� DisjointSet ����
		auto** sets = new typename DisjointSet<Node *>::Set*[Count];

		int index = 0;
		Node* currentNode = Head;
		Edge* currentEdge = NULL;

		// �켱 ���� ť�� ����Ͽ� ���� ���� ����
		while (currentNode != NULL) // ���� ��尡 NULL ���� �� ������ �ݺ�
		{
			sets[index] = DisjointSet<Node *>::CreateSet(currentNode); // set ����
			mstNodes[index] = CreateNode(currentNode->Data); // ���� ����� �����ͷ� ���ο� ��带 �����Ͽ� mst�� ����
			graph->AddNode(mstNodes[index]); // ��� �߰�

			currentEdge = currentNode->Edge;

			// ���� ����� ����� ��� ������ ���� �������� ����
			while (currentEdge != NULL) // ������ NULL ���� �� ������ �ݺ�
			{
				typename PriorityQueue<Edge *>::Node newNode = PriorityQueue<Edge *>::Node(currentEdge->Weight, currentEdge);
				queue.Insert(newNode); // �켱 ���� ť�� ���� -> ����ġ�� ���� ������ ����

				currentEdge = currentEdge->Next; // ���� ������
			}

			currentNode = currentNode->Next; // ���� ����
			index++;
		}

		// �и� ����
		while (queue.Empty() == false)
		{
			// �켱 ������ ���� ���� ��带 pop -> �� ����ġ�� ���� ���� ����
			typename PriorityQueue<Edge *>::Node poped = queue.RemoveMin();
			currentEdge = poped.Data; // ���� Data�� �ڷ����� Edge�̱� ������ ����

			int start = currentEdge->Start->Index; // ���� ����� Index
			int target = currentEdge->Target->Index; // Ÿ�� ����� Index

			// ����Ŭ ������ ����
			if (DisjointSet<Node *>::FindSet(sets[start]) == DisjointSet<Node *>::FindSet(sets[target]))
				continue;

			DisjointSet<Node *>::UnionSet(sets[start], sets[target]); // Union-Find ���� : ������ -> Ž��

			// �׷����� ���� �߰� 
			graph->AddEdge(mstNodes[start], Graph<T>::CreateEdge(mstNodes[start], mstNodes[target], currentEdge->Weight));
			graph->AddEdge(mstNodes[target], Graph<T>::CreateEdge(mstNodes[target], mstNodes[start], currentEdge->Weight));

			// ������ ���
			cout << mstNodes[start]->Data << "->" << mstNodes[target]->Data << ", " << currentEdge->Weight << endl;
		}

		delete[] sets;
		delete[] mstNodes;

		cout << endl;
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
