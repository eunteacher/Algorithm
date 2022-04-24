#include <iostream>
using namespace std;

// 삽입 정렬
void InsertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i]; // 처음은 2번째가 Key가 된다.
		for (int j = i - 1; j >= 0; j--)
		{
			// 역순으로 진행
			if (key < arr[j])
			{
				// 데이터 이동
				arr[j + 1] = arr[j];
				arr[j] = key;
			}
		}
	}
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
	int arr3[5] = { 1,9,5,3,6 };

	cout << "After Insertion Sort " << '\n';
	InsertionSort(arr3, 5);
	Print(arr3, 5);

	return 0;
}