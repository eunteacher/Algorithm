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

	// 부모 노드 인덱스 출력
	int Parent(int index)
	{
		return (int)(index - 1) / 2;
	}

	// 왼쪽 자식 인덱스 출력
	int LeftChild(int index)
	{
		return (index * 2) + 1;
	}

	// 위치 교환 함수 
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

	// 삽입 함수
	void Insert(Node data)
	{
		int current = size;
		int parent = Parent(current);

		// capacity와 size가 같다면 capacity을 증가
		if (size == capacity)
		{
			Node* temp = new Node[capacity * 2];
			memcpy(temp, nodes, sizeof(Node) * capacity); // 복사

			delete[] nodes;

			nodes = temp;
			capacity *= 2;
		}

		nodes[current] = data;

		// 우선 순위에 따라 정렬
		while (current > 0 && nodes[current].Priority < nodes[parent].Priority)
		{
			SwapNode(current, parent);

			current = parent;

			parent = Parent(current);
		}

		size++;
		//cout << size << endl;
	}

	// 출력 함수
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

	// 최솟값 삭제 함수
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
				// 이 경우 size의 값이 없기 때문에 left 선택 
				selected = left;
			}
			else
			{
				// 자식노드 왼쪽 오른쪽 값 비교 : 작은 값 선택 
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

		// 재할당 -> 브런치가 리프가 되면 재할당을 해줘야됨

		return result;
	}

	bool Empty()
	{
		return (size == 0);
	}

public:
	struct Node
	{
		int Priority; // 우선순위
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