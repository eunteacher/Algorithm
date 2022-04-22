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
	BinarySearchTree()
	{

	}

	~BinarySearchTree()
	{

	}

	void Insert(Node** parent, Node* child)
	{
		if ((*parent)->Data < child->Data)
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
		else if((*parent)->Data > child->Data)
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

	Node* Search(Node* node, T data, int& depth)
	{
		if (node == NULL)
		{
			return NULL;
		}

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

	void InOrder(Node* node, int depth)
	{
		if (node == NULL)
		{
			return;
		}

		depth++;

		InOrder(node->Left, depth);
		cout << " Data : " << node->Data << " depth : " << depth << endl;
		InOrder(node->Right, depth);
	}

	Node* Remove(Node* node, Node* parent, T data)
	{
		Node* remove = NULL;

		if (node == NULL)
		{
			return NULL;
		}

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

	Node* SearchMinValue(Node* node)
	{
		if (node == NULL)
		{
			return NULL;
		}

		if (node->Left == NULL)
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

	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = NULL;
		node->Right = NULL;

		return node;
	}

	static void DestoryNode(Node** node)
	{
		delete *node;
		*node = NULL;
	}

private:
	Node* root;

};
