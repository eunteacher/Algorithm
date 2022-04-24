#pragma once

#include <iostream>
using namespace std;

template<typename T>
class DoubleLinkedList
{
public:
	struct Node
	{
		T Data;
		Node* Prev;
		Node* Next;
	};

	// ����
	static Node* Create(T InData)
	{
		Node* node = new Node();
		node->Data = InData;
		node->Prev = nullptr;
		node->Next = nullptr;

		return node;
	}

	// ���� 
	static void Delete(Node** InNode)
	{
		delete *InNode;
		*InNode = nullptr;

	}

public:
	DoubleLinkedList(Node** InHead)
	{
		Head = *InHead;
	}

	~DoubleLinkedList()
	{
		int Total = GetNodeCount();
		for (int i = 0; i < Total; i++)
		{
			Delete(&GetNode(i));
		}
	}

	// Ǫ�� �Լ�
	void Push(Node* InNode)
	{
		Node* Tail = Head;
		while (Tail->Next != nullptr)
			Tail = Tail->Next;

		Tail->Next = InNode;
		InNode->Prev = Tail;
	}

	int GetNodeCount()
	{
		int Count = 0;
		Node* Current = Head;
		while (Current != nullptr)
		{
			Current = Current->Next;
			Count++;
		}

		return Count;
	}

	Node* GetNode(unsigned int InIndex)
	{
		Node* Result = Head;
		int Count = 0;

		if (InIndex >= GetNodeCount() - 1)
		{
			cout << "�ε����� �ʹ� ŭ" << endl;
			return nullptr;
		}

		while (Result != nullptr)
		{
			if (Count == InIndex)
				break;

			Result = Result->Next;
			Count++;
		}

		return Result;
	}

	void Insert(Node* InAddNode, unsigned int InIndex = 0)
	{
		if (InIndex > GetNodeCount())
		{
			cout << "Index���� �ʹ� ŭ" << endl;
			return;
		}

		Node* CurrentNode = GetNode(InIndex);
		Node* PrevNode = CurrentNode->Prev;

		InAddNode->Prev = PrevNode;
		InAddNode->Next = CurrentNode;
		PrevNode->Next = InAddNode;

		CurrentNode->Prev = InAddNode;
	}

	void Insert(Node* InAddNode, Node* InListNode = nullptr)
	{
		if (InListNode == nullptr)
		{
			Push(InAddNode);
		}
		else
		{
			if (ExistNode(InListNode) == false)
			{
				cout << "InListNode�� List�� ���� ��尡 �ƴմϴ�." << endl;
				return;
			}

			Node* PrevNode = InListNode->Prev;

			InAddNode->Prev = PrevNode;
			InAddNode->Next = InListNode;
			PrevNode->Next = InAddNode;

			InListNode->Prev = InAddNode;
		}
	}

	bool ExistNode(Node* InNode)
	{
		Node* temp = Head;
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

	void Remove(Node* RemoveNode = nullptr)
	{
		// RemoveNode�� nullptr �̸� ���� ������ ��带 ����
		if (RemoveNode == nullptr)
		{
			Node* Tail = Head;
			while (Tail->Next->Next != nullptr)
				Tail = Tail->Next;

			Node* removeNode = Tail->Next;
			Tail->Next = nullptr;
			Delete(&removeNode);
		}
		else
		{
			if (RemoveNode == Head)
			{
				Head = RemoveNode->Next;
				Head->Prev = nullptr;
				Delete(&RemoveNode);
			}
			else
			{
				Node* PrevNode = RemoveNode->Prev;
				Node* NextNode = RemoveNode->Next;

				PrevNode->Next = NextNode;
				NextNode->Prev = PrevNode;

				Delete(&RemoveNode);
			}
		}
	}

	void Remove(unsigned int InIndex)
	{
		Node* RemoveNode = GetNode(InIndex);

		if (RemoveNode == Head)
		{
			Head = RemoveNode->Next;
			Head->Prev = nullptr;
			Delete(&RemoveNode);
		}
		else
		{
			Node* PrevNode = RemoveNode->Prev;
			Node* NextNode = RemoveNode->Next;

			PrevNode->Next = NextNode;
			NextNode->Prev = PrevNode;

			Delete(&RemoveNode);
		}
	}

	void PrintList()
	{
		int Total = GetNodeCount();
		Node* PrintNode = Head;
		for (int i = 0; i < Total; i++)
		{
			cout << "List[" << i << "]�� Data : " << PrintNode->Data << endl;
			PrintNode = PrintNode->Next;
		}
	}

private:
	Node* Head;
};