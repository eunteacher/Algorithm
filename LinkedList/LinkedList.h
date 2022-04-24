#pragma once

#include <iostream>
using namespace std;


template<typename T>
class LinkedList
{
public:
	struct Node
	{
		T Data;
		Node* Next;
	};

	// ��� ����
	static Node* Create(T InData)
	{
		Node* node = new Node();
		node->Data = InData;
		node->Next = nullptr;

		return node;
	}

	// ��� ���� 
	static void Delete(Node* InNode)
	{
		delete InNode;
		InNode = nullptr;
	}

public:
	LinkedList()
	{
		this->head = nullptr;
	}

	LinkedList(Node* InNode)
	{
		this->head = InNode;
	}

	// ���� ����Ʈ Ǫ�� �Լ�  
	void Push(Node* InNode)
	{
		// ��尡 nullptr�̸� ��忡 ��带 ����
		if (head == nullptr)
		{
			head = InNode;
			return;
		}

		Node* tail = head;

		// ���� ��尡 ���� ������ �ݺ�
		while (tail->Next != nullptr)
		{
			tail = tail->Next; // ���� ����
		}

		tail->Next = InNode;
	}

	// ���� ����Ʈ ���� ��� �Լ�
	int GetNodeCount()
	{
		int count = 0;
		Node* current = head;
		while (current != nullptr)
		{
			current = current->Next;
			count++;
			int a = 0;
		}

		return count;
	}

	// ���Ḯ��Ʈ�� ��带 �������� �Լ� 
	Node* GetNode(int InIndex)
	{
		Node* node = head;
		int count = 0;
		while (node != nullptr)
		{
			node = node->Next;
			count++;

			if (count == InIndex)
			{
				break;
			}
		}

		return node;
	}

	// ���� ����Ʈ�� �߰��� �����ϴ� �Լ� 
	void Insert(Node* InAddNode, unsigned int InIndex = 0)
	{
		if (head == nullptr)
		{
			head = InAddNode;
			return;
		}

		if (InIndex > GetNodeCount())
		{
			cout << "Index���� �ʹ� ŭ" << endl;
			return;
		}

		if (InIndex == 0)
		{
			Node* headNext = head->Next;
			head->Next = InAddNode;
			InAddNode->Next = headNext;
		}
		else
		{
			Node* listNode = GetNode(InIndex);
			Node* listNodeNext = listNode->Next;

			listNode->Next = InAddNode;
			InAddNode->Next = listNodeNext;
		}
	}
	// ���� ����Ʈ�� �߰��� �����ϴ� �Լ� 
	void Insert(Node* InAddNode, Node* InListNode = nullptr)
	{
		if (head == nullptr)
		{
			head = InAddNode;
			return;
		}

		if (InListNode == nullptr)
		{
			Node* headNext = head->Next;
			head->Next = InAddNode;
			InAddNode->Next = headNext;
		}
		else
		{
			if (ExistNode(InListNode) == false)
			{
				cout << "InListNode�� List�� ���� ��尡 �ƴմϴ�." << endl;
				return;
			}
			Node* listNodeNext = InListNode->Next;
			InListNode->Next = InAddNode;
			InAddNode->Next = listNodeNext;
		}
	}

	// ���� ����Ʈ ���� �Լ� 
	void Remove()
	{
		Node* tail = head;
		while (tail->Next->Next != nullptr)
		{
			tail = tail->Next;
		}
		Node* RemoveNode = tail->Next;
		tail->Next = nullptr;
		Delete(RemoveNode);

	}

	// ���� ����Ʈ�� ��尡 �����ϴ��� Ȯ���ϴ� �Լ� 
	bool ExistNode(Node* InNode)
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp == InNode)
			{
				return true;
			}
			temp = temp->Next;
		}

		return false;
	}

	// ���� ����Ʈ ��� �Լ�
	void PrintList()
	{
		int index = 0;
		int Total = GetNodeCount();
		Node* PrintNode = head;
		for (int i = 0; i < Total; i++)
		{
			cout << "List[" << i << "]�� Data : " << PrintNode->Data << endl;
			PrintNode = PrintNode->Next;
		}
	}

private:
	Node* head;
};