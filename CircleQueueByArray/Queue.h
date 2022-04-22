#pragma once

const static int MaxSize = 10;

template<typename T>
class Queue
{
public:
	Queue()
	{
		// 초기화
		memset(values, 0, sizeof(T) * MaxSize);
		front = 0;
		rear = 0;
	}
	~Queue()
	{

	}

public:
	// 데이터 삽입
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
	// 데이터 pop
	T Deque()
	{
		// Queue가 꽉 차 있는 경우
		if (IsFull() == true && (front - 1) == rear)
		{
			T temp = values[front]; // 프론트 값을 임시 저장
			memset(values, 0, sizeof(T) * MaxSize); // Queue 초기화
			front = 0;
			rear = 0;

			return temp;
		}
		// Queue가 비어 있는 경우
		if (IsEmpty() == true)
			return NULL;

		// front의 값을 증가 시키고 반환
		return values[front++];
	}

	int Front()
	{
		return values[front];
	}

	// Queue가 비어있는지 검사
	bool IsEmpty()
	{
		return (front == rear);
	}
	// Queue가 꽉 차 있는지 검사 
	bool IsFull()
	{
		return (rear + 1) == MaxSize;
	}

private:
	T values[MaxSize];

	// front와 rear는 인덱스 값이다.
	int front;
	int rear;
};
