#pragma once
#include <memory.h>

template<typename T>
class Stack
{
public:
	Stack()
	{
		// �迭�� ���� 0���� �ʱ�ȭ
		memset(values, 0, sizeof(T) * MAX_COUNT);
	}

	~Stack()
	{
		while (IsEmpty() == false)
			Pop();
	}

	// Ǫ�� �Լ�
	void Push(int data)
	{
		if (top == MAX_COUNT - 1)
			return;

		values[++top] = data;
	}

	// �� �Լ� 
	T Pop()
	{
		if (top < 0)
		{
			// ����ó��
			return 0;
		}

		T value = values[top];
		values[top] = 0; // �ʱ�ȭ
		top--;

		return value;
	}

	// ���� �迭�� ��� �ִ��� Ȯ���ϴ� �Լ�
	bool IsEmpty()
	{
		return (top < 0) == true;
	}

	// ���� �迭�� �� �� �ִ��� Ȯ���ϴ� �Լ�
	bool IsFull()
	{
		return (top == (MAX_COUNT - 1)) == true;
	}

private:
	int top = -1;

	const static int MAX_COUNT = 20; // ������ �ִ� �ε��� ��
	T values[MAX_COUNT]; // �迭

};