#include <stdio.h>
#include <array>
using namespace std;

int main()
{
	int a[3] = { 20,10,0 };
	for (int b : a)
	{
		printf("%d\n", b);
		// 2017 ������ ���ͷ����Ͱ� ���ԵǾ��־ ���� 
	}

	array<int, 3> list;
	for (int b : list)
	{
		printf("%d\n", b);
	}

	return 0;
}