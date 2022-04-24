#include "Heap.h"

int main()
{
	Heap<int> heap(3);

	heap.Insert(3);
	heap.Insert(37);
	heap.Insert(88);
	heap.Insert(43);
	heap.Insert(17);
	heap.Insert(67);

	heap.Print();
	cout << endl;

	while (heap.Empty() == false)
	{
		heap.RemoveMin();
		heap.Print();
		cout << std::endl;
	}

	return 0;
}