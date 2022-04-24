#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include "Timer.h"
using namespace std;

// Tip. 이차원 배열은 구조체로 다루면 편하다.
// 이차 포인터를 바로 다룰 수 있어 편하다.
// 이차 포인터의 포인터를 다룰 수 있다.
struct Table
{
	int ** Data;
};

// x, y는 입력받은 문자열
// i, j는 현재 비교할 위치이고, 길이가 입력 받는다. 문자열의 맨 뒤에서 부터 비교를 시작한다.
int LCS(const char* x, const  char* y, int i, int j, Table* table)
{
	// 문자열의 길이가 0이라면 
	if (i == 0 || j == 0)
	{
		table->Data[i][j] = 0;

		//cout << "if (i == 0 || j == 0) -> " << "i : " << i << ", " << "j : " << j << ", " << "table->Data[" << i << "][" << j << "] : " << table->Data[i][j] << '\n';
		//int breakpoint = 0;
	}
	else if (x[i - 1] == y[j - 1]) // 같은 문자라면, i와 j를 -1 해주고, 데이터 값에 +1를 해준다.
	{
		table->Data[i][j] = LCS(x, y, i - 1, j - 1, table) + 1;
		//cout << "if (x[i - 1] == y[j - 1]) -> " << "i : " << i << ", " << "j : " << j << ", " << "table->Data[" << i << "][" << j << "] : " << table->Data[i][j] << '\n';
		//int breakpoint = 0;
	}
	else // 문자가 같지 않다면, 문제를 분할해서 값을 축적해 나간다.
	{

		int a = LCS(x, y, i - 1, j, table); // "GOOD MORNING."
		int b = LCS(x, y, i, j - 1, table); // "GOAL MORNQWE."

		if (a > b)
		{
			table->Data[i][j] = a;
		}
		else
		{
			table->Data[i][j] = b;
		}
		//cout << "else -> " << "a : " << a << ", " << "b : " << b << " ";
		//cout << "i : " << i << ", " << "j : " << j << ", " << "table->Data[" << i << "][" << j << "] : " << table->Data[i][j] << '\n';
		//int breakpoint = 0;

	}

	return table->Data[i][j];
}

// x, y는 입력받은 문자열
// i, j는 현재 비교할 위치이고, 길이가 입력 받는다. 문자열의 맨 뒤에서 부터 비교를 시작한다.
int Dynamic_LCS(const char* x, const char* y, int i, int j, Table* table)
{
	for (int m = 0; m <= i; m++)
	{
		table->Data[m][0] = 0;
	}

	for (int n = 0; n <= j; n++)
	{
		table->Data[0][n] = 0;
	}

	for (int m = 1; m <= i; m++)
	{
		for (int n = 1; n <= j; n++)
		{
			if (x[m - 1] != y[n - 1])
			{
				// 문자가 같지 않다면, 현재 위치에서 바로 윗 값과 왼쪽 값을 비교하여, 더 큰 값을 선택한다.
				table->Data[m][n] = max(table->Data[m][n - 1], table->Data[m - 1][n]);
			}
			else
			{
				// 문제가 같다면, 대각선 왼쪽 윗 값 +1 
				table->Data[m][n] = table->Data[m - 1][n - 1] + 1;
			}
		}
	}
	return table->Data[i][j];
}

void TrackBack(const char* x, const  char* y, int m, int n, Table* table, char* lcs)
{
	if (m == 0 || n == 0)
		return;

	// 오른쪽 하단이 시작 지점이다.
	// 왼쪽 , 왼쪽 위, 위

	// 이거 3개보다 크면 대각선으로 올라감
	// 3개보다 크다 == 동일한 애가 없다란 의미
	// 동일한게 없다란 겹친 문자열이란 이야기
	bool a = true;
	a &= table->Data[m][n] > table->Data[m][n - 1]; // 가로
	a &= table->Data[m][n] > table->Data[m - 1][n]; //  세로
	a &= table->Data[m][n] > table->Data[m - 1][n - 1]; // 대각선

	// 왼쪽 값이 같고 위 값보다 크면 왼쪽으로 이동
	bool b = true;
	b &= table->Data[m][n] == table->Data[m][n - 1]; // 가로
	b &= table->Data[m][n] > table->Data[m - 1][n]; // 세로

	if (a == true)
	{
		// 대각선으로 올라갈 때만 기록
		char temp[100];
		strcpy(temp, lcs);

		sprintf(lcs, "%c%s", x[m - 1], temp);

		TrackBack(x, y, m - 1, n - 1, table, lcs);
	}
	else if (b == true)
	{
		TrackBack(x, y, m, n - 1, table, lcs);
	}
	else
	{
		// 조건이 모두 만족하지 않으면 위 쪽으로 이동
		TrackBack(x, y, m - 1, n, table, lcs);
	}
}

int main()
{
	const char* a = "GOOD MORNING.";
	const char* b = "GOAL MORNQWE.";

	int lengthA = strlen(a);
	int lengthB = strlen(b);

	Table table;
	table.Data = new int*[lengthA + 1];

	// 배열 초기화 
	for (int i = 0; i < lengthA + 1; i++)
	{
		table.Data[i] = new int[lengthB + 1];
		memset(table.Data[i], 0, sizeof(int) * (lengthB + 1));
	}

	Timer timer;
	timer.Start();
	int result = Dynamic_LCS(a, b, lengthA, lengthB, &table);
	timer.End();
	float dynamicLcsTime = timer.RunningTime();
	cout << "-----------------------------" << '\n';

	cout << "Dynamic LCS" << '\n';
	cout << "    "; // 4칸 띄우기

	for (int i = 0; i <= lengthA; i++)
	{
		cout << b[i] << " "; // 문자열 출력
	}
	cout << '\n';

	for (int i = 0; i <= lengthA; i++)
	{
		cout << a[i - 1] << " "; // 문자열 출력 
		for (int j = 0; j <= lengthB; j++)
		{
			cout << table.Data[i][j] << " "; // 데이터 값 출력
		}
		cout << '\n';
	}

	cout << "-----------------------------" << '\n';
	cout << "result : " << result << '\n';
	cout << "-----------------------------" << '\n';
	cout << '\n';

	cout << "TrackBack" << '\n';

	//char* lcs = new char[sizeof(table.Data[lengthA][lengthB] + 10)];
	// 위 코드로 치면 오류가 난다.
	// 그 이유는 배열의 크기를 벗어난 후에 delete를 해줬기 떄문에
	char* lcs = new char[100];
	sprintf(lcs, "");

	timer.Start();
	TrackBack(a, b, lengthA, lengthB, &table, lcs);
	timer.End();
	float trackBackTime = timer.RunningTime();

	cout << "    "; // 4칸 띄우기

	for (int i = 0; i <= lengthA; i++)
	{
		cout << b[i] << " "; // 문자열 출력
	}
	cout << '\n';

	for (int i = 0; i <= lengthA; i++)
	{
		cout << a[i - 1] << " "; // 문자열 출력 
		for (int j = 0; j <= lengthB; j++)
		{
			cout << table.Data[i][j] << " "; // 데이터 값 출력
		}
		cout << '\n';
	}
	cout << "-----------------------------" << '\n';
	cout << "result : " << result << ", " << "lcs : " << lcs << '\n';
	cout << "-----------------------------" << '\n';
	cout << '\n';

	cout << "동적 계획법 LCS 걸린 시간 : " << dynamicLcsTime << '\n';
	cout << "TrackBack 걸린 시간 : " << trackBackTime << '\n';

	timer.Start();
	result = LCS(a, b, lengthA, lengthB, &table);
	timer.End();
	cout << "재귀함수 LCS 걸린 시간 : " << timer.RunningTime() << '\n';

	delete[] lcs;
	//free(lcs);

	return 0;
}