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

	// 노드 생성
	static Node* Create(T InData)
	{
		Node* node = new Node();
		node->Data = InData;
		node->Next = nullptr;

		return node;
	}

	// 노드 삭제 
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

	// 연결 리스트 푸쉬 함수  
	void Push(Node* InNode)
	{
		// 헤드가 nullptr이면 헤드에 노드를 대입
		if (head == nullptr)
		{
			head = InNode;
			return;
		}

		Node* tail = head;

		// 다음 노드가 없을 때까지 반복
		while (tail->Next != nullptr)
		{
			tail = tail->Next; // 다음 노드로
		}

		tail->Next = InNode;
	}

	// 연결 리스트 개수 출력 함수
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

	// 연결리스트의 노드를 가져오는 함수 
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

	// 연결 리스트의 중간에 삽입하는 함수 
	void Insert(Node* InAddNode, unsigned int InIndex = 0)
	{
		if (head == nullptr)
		{
			head = InAddNode;
			return;
		}

		if (InIndex > GetNodeCount())
		{
			cout << "Index값이 너무 큼" << endl;
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
	// 연결 리스트의 중간에 삽입하는 함수 
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
				cout << "InListNode는 List에 속한 노드가 아닙니다." << endl;
				return;
			}
			Node* listNodeNext = InListNode->Next;
			InListNode->Next = InAddNode;
			InAddNode->Next = listNodeNext;
		}
	}

	// 연결 리스트 삭제 함수 
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

	// 연결 리스트에 노드가 존재하는지 확인하는 함수 
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

	// 연결 리스트 출력 함수
	void PrintList()
	{
		int index = 0;
		int Total = GetNodeCount();
		Node* PrintNode = head;
		for (int i = 0; i < Total; i++)
		{
			cout << "List[" << i << "]의 Data : " << PrintNode->Data << endl;
			PrintNode = PrintNode->Next;
		}
	}

private:
	Node* head;
};