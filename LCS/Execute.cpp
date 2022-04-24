#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include "Timer.h"
using namespace std;

// Tip. ������ �迭�� ����ü�� �ٷ�� ���ϴ�.
// ���� �����͸� �ٷ� �ٷ� �� �־� ���ϴ�.
// ���� �������� �����͸� �ٷ� �� �ִ�.
struct Table
{
	int ** Data;
};

// x, y�� �Է¹��� ���ڿ�
// i, j�� ���� ���� ��ġ�̰�, ���̰� �Է� �޴´�. ���ڿ��� �� �ڿ��� ���� �񱳸� �����Ѵ�.
int LCS(const char* x, const  char* y, int i, int j, Table* table)
{
	// ���ڿ��� ���̰� 0�̶�� 
	if (i == 0 || j == 0)
	{
		table->Data[i][j] = 0;

		//cout << "if (i == 0 || j == 0) -> " << "i : " << i << ", " << "j : " << j << ", " << "table->Data[" << i << "][" << j << "] : " << table->Data[i][j] << '\n';
		//int breakpoint = 0;
	}
	else if (x[i - 1] == y[j - 1]) // ���� ���ڶ��, i�� j�� -1 ���ְ�, ������ ���� +1�� ���ش�.
	{
		table->Data[i][j] = LCS(x, y, i - 1, j - 1, table) + 1;
		//cout << "if (x[i - 1] == y[j - 1]) -> " << "i : " << i << ", " << "j : " << j << ", " << "table->Data[" << i << "][" << j << "] : " << table->Data[i][j] << '\n';
		//int breakpoint = 0;
	}
	else // ���ڰ� ���� �ʴٸ�, ������ �����ؼ� ���� ������ ������.
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

// x, y�� �Է¹��� ���ڿ�
// i, j�� ���� ���� ��ġ�̰�, ���̰� �Է� �޴´�. ���ڿ��� �� �ڿ��� ���� �񱳸� �����Ѵ�.
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
				// ���ڰ� ���� �ʴٸ�, ���� ��ġ���� �ٷ� �� ���� ���� ���� ���Ͽ�, �� ū ���� �����Ѵ�.
				table->Data[m][n] = max(table->Data[m][n - 1], table->Data[m - 1][n]);
			}
			else
			{
				// ������ ���ٸ�, �밢�� ���� �� �� +1 
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

	// ������ �ϴ��� ���� �����̴�.
	// ���� , ���� ��, ��

	// �̰� 3������ ũ�� �밢������ �ö�
	// 3������ ũ�� == ������ �ְ� ���ٶ� �ǹ�
	// �����Ѱ� ���ٶ� ��ģ ���ڿ��̶� �̾߱�
	bool a = true;
	a &= table->Data[m][n] > table->Data[m][n - 1]; // ����
	a &= table->Data[m][n] > table->Data[m - 1][n]; //  ����
	a &= table->Data[m][n] > table->Data[m - 1][n - 1]; // �밢��

	// ���� ���� ���� �� ������ ũ�� �������� �̵�
	bool b = true;
	b &= table->Data[m][n] == table->Data[m][n - 1]; // ����
	b &= table->Data[m][n] > table->Data[m - 1][n]; // ����

	if (a == true)
	{
		// �밢������ �ö� ���� ���
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
		// ������ ��� �������� ������ �� ������ �̵�
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

	// �迭 �ʱ�ȭ 
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
	cout << "    "; // 4ĭ ����

	for (int i = 0; i <= lengthA; i++)
	{
		cout << b[i] << " "; // ���ڿ� ���
	}
	cout << '\n';

	for (int i = 0; i <= lengthA; i++)
	{
		cout << a[i - 1] << " "; // ���ڿ� ��� 
		for (int j = 0; j <= lengthB; j++)
		{
			cout << table.Data[i][j] << " "; // ������ �� ���
		}
		cout << '\n';
	}

	cout << "-----------------------------" << '\n';
	cout << "result : " << result << '\n';
	cout << "-----------------------------" << '\n';
	cout << '\n';

	cout << "TrackBack" << '\n';

	//char* lcs = new char[sizeof(table.Data[lengthA][lengthB] + 10)];
	// �� �ڵ�� ġ�� ������ ����.
	// �� ������ �迭�� ũ�⸦ ��� �Ŀ� delete�� ����� ������
	char* lcs = new char[100];
	sprintf(lcs, "");

	timer.Start();
	TrackBack(a, b, lengthA, lengthB, &table, lcs);
	timer.End();
	float trackBackTime = timer.RunningTime();

	cout << "    "; // 4ĭ ����

	for (int i = 0; i <= lengthA; i++)
	{
		cout << b[i] << " "; // ���ڿ� ���
	}
	cout << '\n';

	for (int i = 0; i <= lengthA; i++)
	{
		cout << a[i - 1] << " "; // ���ڿ� ��� 
		for (int j = 0; j <= lengthB; j++)
		{
			cout << table.Data[i][j] << " "; // ������ �� ���
		}
		cout << '\n';
	}
	cout << "-----------------------------" << '\n';
	cout << "result : " << result << ", " << "lcs : " << lcs << '\n';
	cout << "-----------------------------" << '\n';
	cout << '\n';

	cout << "���� ��ȹ�� LCS �ɸ� �ð� : " << dynamicLcsTime << '\n';
	cout << "TrackBack �ɸ� �ð� : " << trackBackTime << '\n';

	timer.Start();
	result = LCS(a, b, lengthA, lengthB, &table);
	timer.End();
	cout << "����Լ� LCS �ɸ� �ð� : " << timer.RunningTime() << '\n';

	delete[] lcs;
	//free(lcs);

	return 0;
}