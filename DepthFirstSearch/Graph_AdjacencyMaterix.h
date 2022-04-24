#pragma once

#include <iostream>
using namespace std;

class Graph_AdjacencyMaterix
{
public:
	Graph_AdjacencyMaterix()
	{
		Reset();
	}

	~Graph_AdjacencyMaterix() {}

	// ��� ������ �߰�
	void AddNodeData(char data)
	{
		NodeDatas[Size] = data;
		Size++;
	}

	// ���� �߰� 
	void AddEdge(int i, int j, bool linked)
	{
		AdjMat[i][j] = linked;
	}

	// ���� ��� �ʱ�ȭ 
	void Reset()
	{
		for (int i = 0; i < MaxSize; i++)
		{
			for (int j = 0; j < MaxSize; j++)
				AddEdge(i, j, false);
		}
	}
	// ��� �Լ�
	void Print()
	{
		cout << " Size : " << Size << endl;
		cout << "    ";
		for (int i = 0; i < Size; i++)
		{
			cout << NodeDatas[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < Size; i++)
		{
			cout << NodeDatas[i] << " : ";

			for (int j = 0; j < Size; j++)
				cout << AdjMat[i][j] << " ";

			cout << endl;
		}
	}

	void DFS(int start)
	{
		if (Vistied[start] == true)
		{
			// �湮�ߴٸ� ����
			return;
		}

		Vistied[start] = true;
		cout << NodeDatas[start] << " ";

		for (int i = 0; i < Size; i++)
		{
			if (AdjMat[start][i] == true)  // ������ �ִٸ� 
				DFS(i);
		}
	}

private:
	int Size = 0; // ����� ���� 

	const static int MaxSize = 256; // �迭�� �ִ� ������
	char NodeDatas[MaxSize]; // ����� ������ �迭
	bool AdjMat[MaxSize][MaxSize]; // ���� ���
	bool Vistied[MaxSize]; // ��� üũ �迭
};