#include <iostream>
using namespace std;

// 두 수를 교환하는 함수
void Swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 선택 정렬
void SelectionSort(int arr[], int size)
{
	// 마지막 인덱스는 자동으로 정렬되어 있기 때문에 정렬하지 않는다.
	for (int i = 0; i < size - 1; i++)
	{
		int min = i; // 최솟값
		for (int j = i + 1; j < size; j++)
		{
			// 제일 작은 값을 i에 보낸다.
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		// 교환
		if (i != min) // 최솟값의 위치가 i와 같다면 교환하지않는다.
			Swap(arr[i], arr[min]);
	} // for i
}

// 배열 출력 함수
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