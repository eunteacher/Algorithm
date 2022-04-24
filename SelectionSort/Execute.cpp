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
void SelectionSort(int arr[], int size)
{
	// ������ �ε����� �ڵ����� ���ĵǾ� �ֱ� ������ �������� �ʴ´�.
	for (int i = 0; i < size - 1; i++)
	{
		int min = i; // �ּڰ�
		for (int j = i + 1; j < size; j++)
		{
			// ���� ���� ���� i�� ������.
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		// ��ȯ
		if (i != min) // �ּڰ��� ��ġ�� i�� ���ٸ� ��ȯ�����ʴ´�.
			Swap(arr[i], arr[min]);
	} // for i
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
	int arr2[5] = { 8,3,2,7,9 };

	cout << "Before Selection Sort " << '\n';
	Print(arr2, 5);
	cout << "After Selection Sort " << '\n';
	SelectionSort(arr2, 5);
	Print(arr2, 5);

	return 0;
}