#pragma once

#include <stdio.h>
#include <iostream>
using namespace std;

template<typename T>
class BinarySearchTree
{
public:
	struct Node;

public:
	BinarySearchTree() {}

	~BinarySearchTree() {}

	// 삽입 함수
	// 부모 노드보다 클 경우 왼쪽, 작을 경우 오른쪽
	void Insert(Node** parent, Node* child)
	{
		if ((*parent)->Data < child->Data) // 부모 노드가 자식 노드보다 작을 경우
		{
			if ((*parent)->Right == NULL)
			{
				(*parent)->Right = child;
			}
			else
			{
				Insert(&(*parent)->Right, child);
			}
		}
		else if((*parent)->Data > child->Data) // // 부모 노드가 자식 노드보다 클 경우
		{
			if ((*parent)->Left == NULL)
			{
				(*parent)->Left = child;
			}
			else
			{
				Insert(&(*parent)->Left, child);
			}
		}
	}
	// 탐색 함수
	// 입력된 데이터가 같으면 출력
	// 작으면 왼쪽으로, 크면 오른쪽으로
	Node* Search(Node* node, T data, int& depth)
	{
		if (node == NULL)
			return NULL;

		depth++;

		if (node->Data == data)
		{
			return node;
		}
		else if (node->Data > data)
		{
			return Search(node->Left, data, depth);
		}
		else if (node->Data < data)
		{
			return Search(node->Right, data, depth);
		}

		return NULL;
	}
	// 중위 순회
	void InOrder(Node* node, int depth)
	{
		if (node == NULL)
			return;

		depth++;

		InOrder(node->Left, depth);
		cout << " Data : " << node->Data << " depth : " << depth << endl;
		InOrder(node->Right, depth);
	}
	// 삭제 함수
	Node* Remove(Node* node, Node* parent, T data)
	{
		Node* remove = NULL;

		if (node == NULL)
			return NULL;

		if (node->Data > data)
		{
			remove = Remove(node->Left, node, data);
		}
		else if (node->Data < data)
		{
			remove = Remove(node->Right, node, data);
		}
		else // 탐색 완료 -> 노드 삭제 
		{
			remove = node;
			if (node->Left == NULL && node->Right == NULL) // leaf
			{
				if (parent->Left == node)
				{
					parent->Left = NULL;
				}
				else
				{
					parent->Right = NULL;
				}
			}
			else
			{
				if (node->Left != NULL && node->Right != NULL)  // 양쪽 자식 노드 존재
				{
					Node* minNode = SearchMinValue(node->Right);

					minNode = Remove(node, NULL, minNode->Data);
					node->Data = minNode->Data;

					return minNode;
				}
				else // 자식 노드가 한쪽인 경우
				{
					Node* temp = NULL;

					if (node->Left != NULL)
					{
						temp = node->Left;
					}
					else
					{
						temp = node->Right;
					}

					if (parent->Left == node)
					{
						parent->Left = temp;
					}
					else
					{
						parent->Right = temp;
					}
				}
			}
		}

		return remove;
	}
	// 제일 작은 데이터를 가진 노드를 찾는 함수
	Node* SearchMinValue(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->Left == NULL) // 왼쪽의 자식 노드가 없을 경우 최솟값
		{
			return node;
		}
		else
		{
			return SearchMinValue(node->Left);
		}
	}

	Node* Root()
	{
		return root;
	}
	void Root(Node* root)
	{
		this->root = root;
	}

public:
	struct Node
	{
		T Data;
		Node* Left;
		Node* Right;
	};
	// 노드 생성
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = NULL;
		node->Right = NULL;

		return node;
	}
	// 노드 삭제
	static void DestoryNode(Node** node)
	{
		delete *node;
		*node = NULL;
	}

private:
	Node* root;

};
