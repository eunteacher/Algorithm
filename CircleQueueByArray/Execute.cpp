#include <iostream>
#include <memory.h>
#include "Queue.h"
using namespace std;

int main()
{
	Queue<int> q;
	// �������� ������ ����
	for (int i = MaxSize - 1; i >= 0; i--)
	{
		q.Enque(i);
	}

	// ���� ��� ���� MaxSize - 1
	cout << "q.Front() : " << q.Front() << '\n';
	cout << "--------------------------------" << '\n';
	// ������ Deque()
	for (int i = 0; i < MaxSize; i++)
	{
		cout << "q.Deque() : " << q.Deque() << '\n';
	}

	return 0;
}