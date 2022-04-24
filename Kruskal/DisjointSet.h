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
		Set* Parent; // �θ�
	};

	// Set ����
	static Set* CreateSet(T data)
	{
		Set* set = new Set();
		set->Parent = NULL;
		set->Data = data;

		return set;
	}

	// Set ����
	static void DestroySet(Set* set)
	{
		delete set;
		set = NULL;
	}

	// �θ� - �ڽ� ���� ���� �� ������ ���·� ����
	static void UnionSet(Set* parent, Set* set)
	{
		set = FindSet(set);
		set->Parent = parent;
	}

	// �θ� ��� Ž��
	static Set* FindSet(Set* set)
	{
		while (set->Parent != NULL) // �θ� ��尡 NULL ���� �� �� ���� �ݺ�
		{
			set = set->Parent;
		}

		return set;
	}
};