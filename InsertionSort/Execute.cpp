#include <iostream>
using namespace std;

// ���� ����
void InsertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i]; // ó���� 2��°�� Key�� �ȴ�.
		for (int j = i - 1; j >= 0; j--)
		{
			// �������� ����
			if (key < arr[j])
			{
				// ������ �̵�
				arr[j + 1] = arr[j];
				arr[j] = key;
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
	int arr3[5] = { 1,9,5,3,6 };

	cout << "After Insertion Sort " << '\n';
	InsertionSort(arr3, 5);
	Print(arr3, 5);

	return 0;
}