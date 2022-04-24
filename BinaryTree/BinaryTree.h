#pragma once

#include <stdio.h>
#include <iostream>
using namespace std;

template<typename T>
class BinaryTree
{
public:
	struct Node;

public:
	BinaryTree()
	{
		root = NULL;
	}

	~BinaryTree()
	{
		Destory(root);
	}

public:
	// 전위 순회
	void PreOrder(Node* node)
	{
		if (node == NULL)
			return;

		cout << " " << node->Data;

		PreOrder(node->Left);
		PreOrder(node->Right);
	}

	// 중위 순회
	void InOrder(Node* node)
	{
		if (node == NULL)
			return;
		
		InOrder(node->Left);
		
		cout << " " << node->Data;
		
		InOrder(node->Right);
	}

	// 후위 순회
	void PostOrder(Node* node)
	{
		if (node == NULL)
			return;

		PostOrder(node->Left);
		PostOrder(node->Right);
		cout << " " << node->Data;
	}

public:
	void Root(Node* node)
	{
		root = node;
	}

	// 트리 노드 삭제 함수
	// 후위 순회를 이용
	void Destory(Node* node)
	{
		if (node == NULL)
			return;

		Destory(node->Left);
		Destory(node->Right);

		DestoryNode(&node);
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
		delete* node;
		*node = NULL;
	}

private:
	Node* root;

};
