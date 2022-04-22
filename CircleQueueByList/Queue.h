#pragma once

template <typename T>
class Queue
{
public:
	struct Node; // ���� ����

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

	// ������ ����
	void Enque(Node* node)
	{
		if (IsEmpty() == true)
		{
			// ��尡 ��� �ֱ� ������ ��ť�� ��尡 front
			// ó���� ���� ����Ǿ�� �ϱ� ������ front�� next�� rear��
			front = node;
			front->Next = rear; 
		}
		else
		{
			Node* temp = front;
			// ť�� (rear - 1)���� �̵� 
			while (temp->Next != rear)
			{
				temp = temp->Next;
			}
			// ��ť�� ��带 rear��
			temp->Next = node;
			node->Next = rear; // ���Ե� ����� ������ rear��
		}
	}

	Node* Deque()
	{
		if (IsEmpty() == true)
			return NULL;

		// ����Ʈ�� ��ť
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
	// ��� ����ü ����
	struct Node
	{
		T Data; // ������
		Node* Next; // ���� ���
	};
	// ��� ����
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;
		return node;
	};
	// ��� ����
	static void DestroyNode(Node** node)
	{
		delete (*node);
		(*node) = NULL;
	}

private:
	Node* front;
	Node* rear;

};

