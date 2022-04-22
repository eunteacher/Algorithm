#pragma once

template <typename T>
class Queue
{
public:
	struct Node; // 전방 선언

public:
	Queue()	
	{
		front = NULL;
		rear = NULL;
	}

	~Queue()
	{
		while (IsEmpty() == false)
		{
			Node* temp = Deque();
			DestroyNode(&temp);
		}

		front = NULL;
		rear = NULL;
	}

	// 데이터 삽입
	void Enque(Node* node)
	{
		if (IsEmpty() == true)
		{
			// 노드가 비어 있기 떄문에 인큐된 노드가 front
			// 처음과 끝이 연결되어야 하기 때문에 front의 next를 rear로
			front = node;
			front->Next = rear; 
		}
		else
		{
			Node* temp = front;
			// 큐의 (rear - 1)까지 이동 
			while (temp->Next != rear)
			{
				temp = temp->Next;
			}
			// 인큐된 노드를 rear로
			temp->Next = node;
			node->Next = rear; // 삽입된 노드의 다음을 rear로
		}
	}

	Node* Deque()
	{
		if (IsEmpty() == true)
			return NULL;

		// 프론트를 디큐
		Node* node = front;
		front = node->Next;
		return node;
	}

	Node* Front()
	{
		return front;
	}

	bool IsEmpty()
	{
		return (front == NULL) && (rear == NULL);
	}

public:
	// 노드 구조체 선언
	struct Node
	{
		T Data; // 데이터
		Node* Next; // 다음 노드
	};
	// 노드 생성
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;
		return node;
	};
	// 노드 삭제
	static void DestroyNode(Node** node)
	{
		delete (*node);
		(*node) = NULL;
	}

private:
	Node* front;
	Node* rear;

};

