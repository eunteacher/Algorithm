#include <iostream>
#include <ctime>
#include "Timer.h"
using namespace std;

// 입력 받은 a,b를 교환
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// 분할
int Partition(int arr[], int left, int right)
{
	int start = left; // 중간값을 모르기 때문에 맨 앞을 기준으로 삼는다.
	int pivot = arr[start];

	left++; // left가 start이기 때문에 하나 증가된 값부터 시작

	while (left <= right) // right가 left보다 크면 계속 반복
	{
		// arr[left]가 pivot보다 작고, left가 right보다 작을 경우 left를 -> 방향으로 계속 움직인다.
		// 즉, arr[left]가 pivot보다 큰 값을 찾을 때까지 반복한다.
		while (arr[left] <= pivot && left < right)
			left++;

		// arr[right]가 pivot보다 크고, left가 right보다 작거나 같은 경우 right를 <- 방향으로 계속 움직인다.
		// 즉, arr[right]가 pivot보다 작은 값을 찾을 때까지 반복한다.
		while (arr[right] > pivot && left <= right)
			right--;

		if (left < right) // left는 큰 값을, right는 작은 값을 찾은 경우 
			Swap(arr[left], arr[right]);
		else // 서로 교차 혹은 만난 경우
			break;
	}

	// right 값을 피벗으로 사용한다.
	Swap(arr[start], arr[right]);

	return right;
}
// 쿽 정렬
void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int index = Partition(arr, left, right);

		QuickSort(arr, left, index - 1);
		QuickSort(arr, index + 1, right);
	}
}
// 병합 함수
void Merge(int arr[], int start, int mid, int end)
{
	int left = start;
	int right = mid + 1;

	// 입력받을 배열의 인덱스를 말한다.
	int destIndex = 0;
	// 입력 받을 배열, 동적할당을 하는 이유는 크기를 모르기 때문에, 런타임 중에 크기를 정해주려고 
	int* dest = new int[(end - start + 1)];

	// 정렬
	// 두 수를 비교해서 더 작은 값을 먼저 배열에 대입한다.
	while (left <= mid && right <= end)
	{
		if (arr[left] < arr[right])
		{
			dest[destIndex] = arr[left];
			left++;
		}
		else
		{
			dest[destIndex] = arr[right];
			right++;
		}

		destIndex++;
	}

	// 합병 과정에서 순서가 수정되거나 추가된 값들을 dest 배열에 대입한다.
	while (left <= mid)
	{
		dest[destIndex++] = arr[left++];
	}

	while (right <= end)
	{
		dest[destIndex++] = arr[right++];
	}

	// 입력받은 배열 arr에 정렬된 dest 배열을 복사한다.
	destIndex = 0;
	for (int i = start; i <= end; i++)
	{
		arr[i] = dest[destIndex++];
	}

	delete[] dest;

}
// 정렬 함수
void MergeSort(int arr[], int start, int end)
{
	// 정렬할 데이터가 없다면
	if (end - start < 1)
		return;

	// 중간값
	int mid = (start + end) / 2;

	// 재귀함수로 분할 
	MergeSort(arr, start, mid);
	MergeSort(arr, mid + 1, end);

	// 병합
	Merge(arr, start, mid, end);
}
// 배열 출력 함수 
void Print(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main()
{
	srand((unsigned int)time(NULL));
	const int arrSize = 10;
	int arr[arrSize];
	int arr2[arrSize];

	Timer t;

	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = rand() % 100; // 0 ~ 100 난수 생성
		arr2[i] = rand() % 100;
	}
	cout << "Before QuickSort" << '\n';
	Print(arr, arrSize);

	cout << "After QuickSort" << '\n';
	t.Start();
	QuickSort(arr, 0, arrSize - 1);
	Print(arr, arrSize);
	t.End();
	cout << "Quick Time : " << t.RunningTime() << '\n';
	cout << "--------------------------------------" << '\n';
	cout << "Before MergeSort" << '\n';
	Print(arr2, arrSize);
	cout << "After MergeSort" << '\n';
	t.Start();
	MergeSort(arr2, 0, arrSize - 1);
	Print(arr2, arrSize);
	t.End();
	cout << "MergeSort Time : " << t.RunningTime() << '\n';

	return 0;
}