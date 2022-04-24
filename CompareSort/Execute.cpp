#include <iostream>
#include "Timer.h"
using namespace std;

// 두 수를 교환하는 함수
void Swap(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 버블 정렬
void BubbleSort(int arr[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		// size만큼 반복
		for (int j = 0; j < i; j++)
		{
			// 비교 후 교환
			if (arr[j] > arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
			}
		}
	}
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
		{
			Swap(arr[i], arr[min]);
		}
	} // for i
}

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
	// 시간 복잡도가 O(log(n^2)인 정렬
	Timer t;
	int arr[5] = { 7,4,5,1,3 };
	int arr2[5] = { 8,3,2,7,9 };
	int arr3[5] = { 1,9,5,3,6 };
	
	cout << "Before Bubble Sort " << '\n';
	Print(arr, 5);

	cout << "After Bubble Sort " << '\n';
	t.Start();
	BubbleSort(arr, 5);
	t.End();
	Print(arr, 5);
	cout<<"Bubble Sort Time : " << t.RunningTime() << '\n';
	cout << "-------------------------------------" << '\n';
	
	cout << "Before Selection Sort " << '\n';
	Print(arr2, 5);
	cout << "After Selection Sort " << '\n';
	t.Start();
	SelectionSort(arr2, 5);
	t.End();
	Print(arr2, 5);
	cout << "Selection Sort Time : " << t.RunningTime() << '\n';
	cout << "-------------------------------------" << '\n';

	cout << "Before Insertion Sort " << '\n';
	Print(arr3, 5);

	cout << "After Insertion Sort " << '\n';
	t.Start();
	InsertionSort(arr3, 5);
	t.End();
	Print(arr3, 5);
	cout << "Insertion Sort Time : " << t.RunningTime() << '\n';

	return 0;
}