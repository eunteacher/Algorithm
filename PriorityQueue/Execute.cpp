#include <string>
#include "PriorityQueue.h"

int main()
{
	PriorityQueue<string> priorityQueue(12);

	priorityQueue.Insert(PriorityQueue<string>::Node(34, "È«±æµ¿"));
	priorityQueue.Insert(PriorityQueue<string>::Node(12, "ÀÌ¼ø½Å"));
	priorityQueue.Insert(PriorityQueue<string>::Node(87, "¼¼Á¾´ë¿Õ"));
	priorityQueue.Insert(PriorityQueue<string>::Node(45, "À»Áö¹®´ö"));
	priorityQueue.Insert(PriorityQueue<string>::Node(35, "¹Ú¹®¼ö"));
	priorityQueue.Insert(PriorityQueue<string>::Node(66, "À¯°ü¼ø"));
	priorityQueue.Insert(PriorityQueue<string>::Node(5, "À±ºÀ±æ"));

	priorityQueue.Print();

	while (priorityQueue.Empty() == false)
	{
		priorityQueue.RemoveMin();
		priorityQueue.Print();
	}

	return 0;
}