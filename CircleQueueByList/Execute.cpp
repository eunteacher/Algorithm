#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue<int> q;

	Queue<int>::Node* node1 = Queue<int>::CreateNode(54);
	Queue<int>::Node* node2 = Queue<int>::CreateNode(65);
	Queue<int>::Node* node3 = Queue<int>::CreateNode(83);
	Queue<int>::Node* node4 = Queue<int>::CreateNode(75);

	q.Enque(node1);
	q.Enque(node2);
	q.Enque(node3);
	q.Enque(node4);

	cout<<"q의 front의 Data 값 : " << q.Front()->Data << '\n';
	
	// deque
	for (int i = 0; i < 4; i++)
	{
		cout << q.Deque()->Data << " ";
	}
	cout << '\n';

	if (q.IsEmpty() == true)
	{
		cout << "q가 비어있다" << '\n';
	}

	return 0;
}