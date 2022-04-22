#include <iostream>
using namespace std;

#define MaxNum 10

int main()
{
	int data[] = { 5,3,3,4,7,0,0 }; // 정렬할 배열
	int sumArr[MaxNum] = { 0, }; // 누적합 배열 선언 및 초기값 설정
	int countArr[MaxNum] = { 0, }; // 정렬된 배열
	int sortArr[7];
	// 등장 횟수  
	for (int i = 0; i < 7; i++)
		countArr[data[i]]++;

	// 누적 합
	sumArr[0] = countArr[0];
	for (int i = 1; i < MaxNum; i++)
		sumArr[i] = countArr[i] + sumArr[i - 1];

	// 정렬 배열 값 넣기
	for (int i = 6; i >= 0; i--)
	{
		int val = data[i];
		sortArr[sumArr[val] - 1] = val;
		sumArr[val]--;
	}

	// 출력
	for (int i = 0; i < 7; i++)
		cout << sortArr[i] << " ";

	return 0;
}