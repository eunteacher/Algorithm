#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> stackByLinkedList;

	for (int i = 0; i < 5; i++)
	{
		Stack<int>::Node* node = Stack<int>::CreateNode(i);
		stackByLinkedList.Push(node);
	}

	for (int i = 0; i < 5; i++)
	{
		Stack<int>::Node* node = stackByLinkedList.Pop();
		cout << "Pop() : " << node->Data << endl;
	}

	return 0;
}