#include <iostream>
#include <queue>
using namespace std;

// �迭 �� ���
void Print(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

// ���ڿ� ����� �ϴ� �ڸ����� �Է� �޾� ����� �ϴ� �ڸ����� ���� ������ ��ȯ�ϴ� �Լ�
int GetRadixDigit(int num, int radix)
{
	return (num / radix) % 10;
}

// �Է� ���� �迭�� �ִ��� ��ȯ�ϴ� �Լ�
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

// �Է� ���� �迭�� �ִ����� �ݺ��� ���� ��ȯ�ϴ� �Լ� 
int GetMaxRadix(int max)
{
	// max ���� 123�� ���Դٰ� �����Ѵٸ�
	// 123�� 100 ~ 1000�� �ִ�.
	// 1000 >= max�� �����ϱ� ������ 
	// 1000�� ��ȯ

	int radix = 1; // �ڸ����� ���� ����

	while (true)
	{
		if (max <= 0) // max�� �����ų� 0�̸� �ȵȴ�.
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
	queue<int> bucket[queueNum]; // 0 ~ 9�� ���� ��Ŷ�� 10�� ����

	for (int i = 1; i < maxRadix; i *= 10) // 1 ~ maxRadix���� �ݺ� ex) 1, 10, 100, 1000 ...
	{
		for (int j = 0; j < arrSize; j++) // �迭�� ��� �� Ž��
		{
			int n = GetRadixDigit(arr[j], i); // arr[j]�� ���� i �ڸ���
			bucket[n].push(arr[j]); // ��Ŷ�� Ǫ��
		}

		int index = 0; // �迭�� �ε��� 
		for (int j = 0; j < queueNum; j++) // ť�� ���� �˻� 
		{
			while (bucket[j].empty() == false) // ť�� �� ������ �ݺ� 
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
	int arrSize = sizeof(arr) / sizeof(arr[0]); // �迭 ũ��

	int maxValue = GetMax(arr, arrSize);
	int maxRadix = GetMaxRadix(maxValue);

	cout << "Before Radix Sort " << '\n';
	Print(arr, arrSize);

	cout << "After Radix Sort " << '\n';
	RadixSort(arr, arrSize, maxRadix);
	Print(arr, arrSize);

	return 0;
}