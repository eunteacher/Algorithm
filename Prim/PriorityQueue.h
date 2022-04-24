#pragma once

#include <iostream>
using namespace std;

template<typename T>
class PriorityQueue
{
public:
	struct Node;

public:
	PriorityQueue(int capacity)
		:capacity(capacity)
	{
		nodes = new Node[capacity];
		size = 0;
	}

	~PriorityQueue()
	{
		delete[] nodes;
		nodes = NULL;
	}

	// �θ� ��� �ε��� ���
	int Parent(int index)
	{
		return (int)(index - 1) / 2;
	}

	// ���� �ڽ� �ε��� ���
	int LeftChild(int index)
	{
		return (index * 2) + 1;
	}

	// ��ġ ��ȯ �Լ� 
	void SwapNode(int index1, int index2)
	{
		//Node* temp = new Node();
		//memcpy(temp, &nodes[index1], sizeof(Node));
		//memcpy(&nodes[index1], &nodes[index2], sizeof(Node));
		//memcpy(&nodes[index2], temp, sizeof(Node));
		//delete temp;

		Node temp;
		temp = nodes[index1];
		nodes[index1] = nodes[index2];
		nodes[index2] = temp;
	}

	// ���� �Լ�
	void Insert(Node data)
	{
		int current = size;
		int parent = Parent(current);

		// capacity�� size�� ���ٸ� capacity�� ����
		if (size == capacity)
		{
			Node* temp = new Node[capacity * 2];
			memcpy(temp, nodes, sizeof(Node) * capacity); // ����

			delete[] nodes;

			nodes = temp;
			capacity *= 2;
		}

		nodes[current] = data;

		// �켱 ������ ���� ����
		while (current > 0 && nodes[current].Priority < nodes[parent].Priority)
		{
			SwapNode(current, parent);

			current = parent;

			parent = Parent(current);
		}

		size++;
		//cout << size << endl;
	}

	// ��� �Լ�
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			int parent = -1;
			if (i > 0)
			{
				parent = Parent(i);
			}

			cout << nodes[i].Priority << "|" << nodes[i].Data << ",";
		}

		cout << endl;
	}

	// �ּڰ� ���� �Լ�
	Node RemoveMin()
	{
		int parent = 0;
		int left = 0;
		int right = 0;

		//Node result;
		//memcpy(&result, &nodes[0], sizeof(Node));

		Node result = nodes[0];

		size--;

		SwapNode(0, size);
		left = LeftChild(0);
		right = left + 1;

		while (true)
		{
			int selected = 0;
			if (left >= size)
				break;

			if (right >= size)
			{
				// �� ��� size�� ���� ���� ������ left ���� 
				selected = left;
			}
			else
			{
				// �ڽĳ�� ���� ������ �� �� : ���� �� ���� 
				if (nodes[left].Priority > nodes[right].Priority)
				{
					selected = right;
				}
				else
				{
					selected = left;
				}
			}

			if (nodes[selected].Priority < nodes[parent].Priority)
			{
				SwapNode(parent, selected);

				parent = selected;
			}
			else
			{
				break;
			}

			left = LeftChild(parent);
			right = left + 1;
		}

		// ���Ҵ� -> �귱ġ�� ������ �Ǹ� ���Ҵ��� ����ߵ�

		return result;
	}

	bool Empty()
	{
		return (size == 0);
	}

public:
	struct Node
	{
		int Priority; // �켱����
		T Data;

		Node() {}

		Node(int priority, T data)
		{
			Data = data;
			Priority = priority;
		}
	};

private:
	Node* nodes;

	int capacity;
	int size;
};