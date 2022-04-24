#include <string>
#include "PriorityQueue.h"

int main()
{
	PriorityQueue<string> priorityQueue(12);

	priorityQueue.Insert(PriorityQueue<string>::Node(34, "ȫ�浿"));
	priorityQueue.Insert(PriorityQueue<string>::Node(12, "�̼���"));
	priorityQueue.Insert(PriorityQueue<string>::Node(87, "�������"));
	priorityQueue.Insert(PriorityQueue<string>::Node(45, "��������"));
	priorityQueue.Insert(PriorityQueue<string>::Node(35, "�ڹ���"));
	priorityQueue.Insert(PriorityQueue<string>::Node(66, "������"));
	priorityQueue.Insert(PriorityQueue<string>::Node(5, "������"));

	priorityQueue.Print();

	while (priorityQueue.Empty() == false)
	{
		priorityQueue.RemoveMin();
		priorityQueue.Print();
	}

	return 0;
}