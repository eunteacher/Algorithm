#include <iostream>
using namespace std;

// �� ���� ��ȯ�ϴ� �Լ�
void Swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}
// ���� ����
void BubbleSort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		// size��ŭ �ݺ�
		for (int j = 0; j < i; j++)
		{
			// �� �� ��ȯ
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// �迭 ��� �Լ�
void Print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main()
{
	int arr[5] = { 7,4,5,1,3 };

	cout << "Before Bubble Sort " << '\n';
	Print(arr, 5);

	cout << "After Bubble Sort " << '\n';
	BubbleSort(arr, 5);
	Print(arr, 5);

	return 0;
}