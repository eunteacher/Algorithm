#include <iostream>
#include <memory.h>
#include "Queue.h"
using namespace std;

int main()
{
	Queue<int> q;
	// 역순으로 데이터 삽입
	for (int i = MaxSize - 1; i >= 0; i--)
	{
		q.Enque(i);
	}

	// 예상 출력 값은 MaxSize - 1
	cout << "q.Front() : " << q.Front() << '\n';
	cout << "--------------------------------" << '\n';
	// 데이터 Deque()
	for (int i = 0; i < MaxSize; i++)
	{
		cout << "q.Deque() : " << q.Deque() << '\n';
	}

	return 0;
}