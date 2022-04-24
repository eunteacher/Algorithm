#pragma once
#include <memory.h>

template<typename T>
class Stack
{
public:
	Stack()
	{
		// 배열을 전부 0으로 초기화
		memset(values, 0, sizeof(T) * MAX_COUNT);
	}

	~Stack()
	{
		while (IsEmpty() == false)
			Pop();
	}

	// 푸쉬 함수
	void Push(int data)
	{
		if (top == MAX_COUNT - 1)
			return;

		values[++top] = data;
	}

	// 팝 함수 
	T Pop()
	{
		if (top < 0)
		{
			// 예외처리
			return 0;
		}

		T value = values[top];
		values[top] = 0; // 초기화
		top--;

		return value;
	}

	// 스택 배열이 비어 있는지 확인하는 함수
	bool IsEmpty()
	{
		return (top < 0) == true;
	}

	// 스택 배열이 꽉 차 있는지 확인하는 함수
	bool IsFull()
	{
		return (top == (MAX_COUNT - 1)) == true;
	}

private:
	int top = -1;

	const static int MAX_COUNT = 20; // 스택의 최대 인덱스 값
	T values[MAX_COUNT]; // 배열

};