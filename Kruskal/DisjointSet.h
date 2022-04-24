#pragma once

#include <iostream>
using namespace std;

template<typename T>
class DisjointSet
{
public:
	struct Set
	{
		T Data;
		Set* Parent; // 부모
	};

	// Set 생성
	static Set* CreateSet(T data)
	{
		Set* set = new Set();
		set->Parent = NULL;
		set->Data = data;

		return set;
	}

	// Set 삭제
	static void DestroySet(Set* set)
	{
		delete set;
		set = NULL;
	}

	// 부모 - 자식 관계 형성 즉 합집합 형태로 만듬
	static void UnionSet(Set* parent, Set* set)
	{
		set = FindSet(set);
		set->Parent = parent;
	}

	// 부모 노드 탐색
	static Set* FindSet(Set* set)
	{
		while (set->Parent != NULL) // 부모 노드가 NULL 값일 될 때 까지 반복
		{
			set = set->Parent;
		}

		return set;
	}
};