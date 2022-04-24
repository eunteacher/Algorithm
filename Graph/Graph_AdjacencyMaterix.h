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

	// 노드 데이터 추가
	void AddNodeData(char data)
	{
		NodeDatas[Size] = data;
		Size++;
	}

	// 엣지 추가 
	void AddEdge(int i, int j, bool linked)
	{
		AdjMat[i][j] = linked;
	}

	// 인접 행렬 초기화 
	void Reset()
	{
		for (int i = 0; i < MaxSize; i++)
		{
			for (int j = 0; j < MaxSize; j++)
				AddEdge(i, j, false);
		}
	}
	// 출력 함수
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

private:
	int Size = 0; // 노드의 개수 

	const static int MaxSize = 256; // 배열의 최대 사이즈
	char NodeDatas[MaxSize]; // 노드의 데이터 배열
	bool AdjMat[MaxSize][MaxSize]; // 인접 행렬 
};