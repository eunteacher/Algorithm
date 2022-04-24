#include <iostream>
#include "Timer.h"
using namespace std;

// Time 클래스를 이용해서 수행 시간 비교해보기.

typedef unsigned long long BLONG;

// 행렬
struct Matrix
{
	BLONG Data[2][2];

	// 두 행렬의 곱
	static Matrix Multiply(Matrix a, Matrix b)
	{
		Matrix r;

		r.Data[0][0] = a.Data[0][0] * b.Data[0][0] + a.Data[0][1] * b.Data[1][0];
		r.Data[0][1] = a.Data[0][0] * b.Data[1][0] + a.Data[0][1] * b.Data[1][1];
		r.Data[1][0] = a.Data[1][0] * b.Data[0][0] + a.Data[1][1] * b.Data[1][0];
		r.Data[1][1] = a.Data[1][0] * b.Data[1][0] + a.Data[1][1] * b.Data[1][1];

		return r;
	}
};

// 입력 값 n만큼 행렬 m을 제곱해주는 함수 
Matrix Power(Matrix& m, int n)
{
	// n이 1보다 작거나 같으면 행렬을 그대로 반환 
	if (n <= 1)
	{
		return m;
	}

	m = Power(m, n / 2);
	m = Matrix::Multiply(m, m);

	// 비트 AND 연산자 : 두 비트가 모두 1인 경우 1로 평가 
	// 홀수일 경우 true
	if (n & 1)
	{
		Matrix b;
		b.Data[0][0] = 1;
		b.Data[0][1] = 1;

		b.Data[1][0] = 1;
		b.Data[1][1] = 0;

		m = Matrix::Multiply(m, b);
	}

	return m;
}

BLONG Finbonacci(int n)
{
	Matrix m;

	m.Data[0][0] = 1;
	m.Data[0][1] = 1;

	m.Data[1][0] = 1;
	m.Data[1][1] = 0;

	m = Power(m, n);

	return m.Data[0][1]; // 2,3 만 반환해야된다.
}

// 동적 계획법을 이용하여 구현한 피보나치 수열 값 반환 함수 
BLONG Dynamic_Finbonacci(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	BLONG* table = new BLONG[n + 1]; // 계산된 값을 넣을 배열

	// 이미 계산된 2개의 값
	table[0] = 0; 
	table[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		table[i] = table[i - 1] + table[i - 2];
	}

	BLONG result = table[n];

	delete[] table;

	return result;
}

int main()
{
	Timer timer;

	timer.Start();
	cout<<"Dynamic_Finbonacci : " << Dynamic_Finbonacci(10) << '\n';
	timer.End();
	cout << "걸린 시간 : " << timer.RunningTime() << '\n';

	BLONG temp = Finbonacci(10);
	timer.Start();
	cout << "Matrix : " << temp << '\n';
	timer.End();
	cout << "걸린 시간 : " << timer.RunningTime() << '\n';
	return 0;
}