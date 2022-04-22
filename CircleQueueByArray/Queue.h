#pragma once

const static int MaxSize = 10;

template<typename T>
class Queue
{
public:
	Queue()
	{
		// �ʱ�ȭ
		memset(values, 0, sizeof(T) * MaxSize);
		front = 0;
		rear = 0;
	}
	~Queue()
	{

	}

public:
	// ������ ����
	void Enque(T data)
	{
		if (IsFull() == true)
			return;

		if (IsEmpty() == true)
			values[front] = data;
		else
			values[rear] = data;
		
		rear++;
	}
	// ������ pop
	T Deque()
	{
		// Queue�� �� �� �ִ� ���
		if (IsFull() == true && (front - 1) == rear)
		{
			T temp = values[front]; // ����Ʈ ���� �ӽ� ����
			memset(values, 0, sizeof(T) * MaxSize); // Queue �ʱ�ȭ
			front = 0;
			rear = 0;

			return temp;
		}
		// Queue�� ��� �ִ� ���
		if (IsEmpty() == true)
			return NULL;

		// front�� ���� ���� ��Ű�� ��ȯ
		return values[front++];
	}

	int Front()
	{
		return values[front];
	}

	// Queue�� ����ִ��� �˻�
	bool IsEmpty()
	{
		return (front == rear);
	}
	// Queue�� �� �� �ִ��� �˻� 
	bool IsFull()
	{
		return (rear + 1) == MaxSize;
	}

private:
	T values[MaxSize];

	// front�� rear�� �ε��� ���̴�.
	int front;
	int rear;
};
