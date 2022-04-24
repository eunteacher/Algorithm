#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);

	int i = 100;

	while (stack.IsFull() == false)
	{
		stack.Push(i);
		i++;
	}

	while (stack.IsEmpty() == false)
	{
		cout << "stack value : " << stack.Pop() << endl;
	}

	return 0;
}