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
	// Ǫ�� �Լ� 
	void Push(Node* node)
	{
		if (IsEmpty() == true) // ���� ��� �ִٸ�
		{
			// ��� �ֱ� ������ head�� tail�� ����
			head = node;
			tail = node;
		}
		else
		{
			Node* temp = head;

			while (temp->Next != NULL) // ������ ������ �ݺ�
			{
				temp = temp->Next;
			}

			temp->Next = node;
			tail = node;
		}
	}

	// �� �Լ�
	Node* Pop()
	{
		if (IsEmpty() == true)
			return NULL;

		Node* temp = head;

		if (head == tail) // �ϳ��� ��常 ����
		{
			head = NULL;
			return temp;
		}

		while (temp->Next != tail) // ������ ��� �� ������ �ݺ�
		{
			temp = temp->Next;
		}

		Node* node = tail;
		temp->Next = NULL;
		tail = temp;

		return node;
	}

	// ������ ����ִ��� Ȯ�� �Լ�
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

	// ��� ����
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}

	// ��� ����
	static void DestoryNode(Node** node)
	{
		delete (*node);
		(*node) = NULL;
	}

private:
	Node* head = NULL;
	Node* tail = NULL;


};