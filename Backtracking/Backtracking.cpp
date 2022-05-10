#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 조건 확인 함수 
bool IsPromising(vector<int> pos, int level)
{
	for (int i = 1; i < level; ++i)
	{
		if (pos[i] == pos[level]) return false; // 같은 열에 놓였는지를 검사한다.
		else if ((level - i) == abs(pos[level] - pos[i])) return false; // 같은 대각선에 놓였는지를 검사한다.
	}

	return true;
}

// 입력값 퀸의 위치, N의 값, 현재 깊이 즉 Level, 출력할 경우의 수
void Queens(vector<int> pos, int N, int level, int& count)
{
	if (IsPromising(pos, level) == false) return;
	else if(level == N)
	{
		count++;
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		pos[level + 1] = i;
		Queens(pos, N, level + 1, count);
	}
}

int main()
{
	// N * N 크기의 체스판에서 N개의 퀀을 서로 공격할 수 없도록 놓을 수 있는 경우의 수는 ?
	int N; // 입력 값
	cin >> N;
	vector<int> pos; // 퀸의 위치, 인덱스는 열, 값은 행
	pos.assign(N + 1, 0); // 미리 할당
	int count = 0; // 경우의 수

	Queens(pos, N, 0, count);
	cout << count << '\n';
	return 0;
}
