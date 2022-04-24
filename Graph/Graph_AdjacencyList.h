#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Graph_AdjacencyList
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
		Node* Start = NULL; // ���� ��� 
		Node* Target = NULL; // Ÿ�� ��� 
		Edge* Next = NULL; // ���� ���� 
	};

public:
	// ���� ���� �Լ� 
	static Edge* CreateEdge(Node* start, Node* target)
	{
		Edge* edge = new Edge();

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