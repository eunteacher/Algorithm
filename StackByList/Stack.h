#pragma once
#pragma once

#include <stdio.h>

template<typename T>
class Stack
{
public:
	struct Node;

public:
	Stack() {}

	~Stack()
	{
		while (IsEmpty() == false)
		{
			Node* temp = Pop();
			DestoryNode(&temp);
		}

		head = NULL;
		tail = NULL;
	}

public:
	// 푸쉬 함수 
	void Push(Node* node)
	{
		if (IsEmpty() == true) // 현재 비어 있다면
		{
			// 비어 있기 때문에 head와 tail이 같음
			head = node;
			tail = node;
		}
		else
		{
			Node* temp = head;

			while (temp->Next != NULL) // 마지막 노드까지 반복
			{
				temp = temp->Next;
			}

			temp->Next = node;
			tail = node;
		}
	}

	// 팝 함수
	Node* Pop()
	{
		if (IsEmpty() == true)
			return NULL;

		Node* temp = head;

		if (head == tail) // 하나의 노드만 소유
		{
			head = NULL;
			return temp;
		}

		while (temp->Next != tail) // 마지막 노드 전 노드까지 반복
		{
			temp = temp->Next;
		}

		Node* node = tail;
		temp->Next = NULL;
		tail = temp;

		return node;
	}

	// 스택이 비어있는지 확인 함수
	bool IsEmpty()
	{
		return (head == NULL);
	}

public:
	struct Node
	{
		T Data;
		Node* Next;
	};

	// 노드 생성
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}

	// 노드 삭제
	static void DestoryNode(Node** node)
	{
		delete (*node);
		(*node) = NULL;
	}

private:
	Node* head = NULL;
	Node* tail = NULL;


};