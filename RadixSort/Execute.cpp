#include <iostream>
#include <queue>
using namespace std;

// 배열 값 출력
void Print(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

// 숫자와 얻고자 하는 자릿수를 입력 받아 얻고자 하는 자릿수의 값이 얼마인지 반환하는 함수
int GetRadixDigit(int num, int radix)
{
	return (num / radix) % 10;
}

// 입력 받은 배열의 최댓값을 반환하는 함수
int GetMax(int arr[], int arrSize)
{
	int maxValue = 0;
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] > maxValue)
		{
			maxValue = arr[i];
		}
	}

	return maxValue;
}

// 입력 받은 배열의 최댓값으로 반복할 수를 반환하는 함수 
int GetMaxRadix(int max)
{
	// max 값이 123이 들어왔다고 가정한다면
	// 123은 100 ~ 1000에 있다.
	// 1000 >= max가 성립하기 때문에 
	// 1000을 반환

	int radix = 1; // 자릿수를 위한 변수

	while (true)
	{
		if (max <= 0) // max가 음수거나 0이면 안된다.
		{
			return 0;
		}

		if (radix >= max)
		{
			return radix;
		}

		radix *= 10;
	}
}

void RadixSort(int arr[], int arrSize, int maxRadix)
{
	const int queueNum = 10;
	queue<int> bucket[queueNum]; // 0 ~ 9를 담을 버킷을 10개 생성

	for (int i = 1; i < maxRadix; i *= 10) // 1 ~ maxRadix까지 반복 ex) 1, 10, 100, 1000 ...
	{
		for (int j = 0; j < arrSize; j++) // 배열의 모든 값 탐색
		{
			int n = GetRadixDigit(arr[j], i); // arr[j]의 값의 i 자릿수
			bucket[n].push(arr[j]); // 버킷에 푸쉬
		}

		int index = 0; // 배열의 인덱스 
		for (int j = 0; j < queueNum; j++) // 큐를 전부 검사 
		{
			while (bucket[j].empty() == false) // 큐가 빌 때까지 반복 
			{
				arr[index] = bucket[j].front();
				bucket[j].pop();
				index++;
			}
		}
	}
}

int main()
{
	int arr[] = { 11,16,29,33,45,44,27,62,39,38,51 };
	int arrSize = sizeof(arr) / sizeof(arr[0]); // 배열 크기

	int maxValue = GetMax(arr, arrSize);
	int maxRadix = GetMaxRadix(maxValue);

	cout << "Before Radix Sort " << '\n';
	Print(arr, arrSize);

	cout << "After Radix Sort " << '\n';
	RadixSort(arr, arrSize, maxRadix);
	Print(arr, arrSize);

	return 0;
}