#include <stdio.h>
#include <array>
using namespace std;

int main()
{
	int a[3] = { 20,10,0 };
	for (int b : a)
	{
		printf("%d\n", b);
		// 2017 버전에 이터레이터가 포함되어있어서 가능 
	}

	array<int, 3> list;
	for (int b : list)
	{
		printf("%d\n", b);
	}

	return 0;
}