#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList<int>::Node* head = DoubleLinkedList<int>::Create(10);
	DoubleLinkedList<int>::Node* node1 = DoubleLinkedList<int>::Create(20);

	DoubleLinkedList<int>* DoubleList = new DoubleLinkedList<int>(&head);
	DoubleList->Push(node1);

	int ListCount = DoubleList->GetNodeCount();

	DoubleLinkedList<int>::Node* temp = DoubleList->GetNode(0);

	DoubleLinkedList<int>::Node* node2 = DoubleLinkedList<int>::Create(30);
	DoubleLinkedList<int>::Node* node3 = DoubleLinkedList<int>::Create(40);
	DoubleLinkedList<int>::Node* node4 = DoubleLinkedList<int>::Create(50);
	DoubleLinkedList<int>::Node* node5 = DoubleLinkedList<int>::Create(60);

	DoubleList->Push(node2);
	DoubleList->Push(node3);
	DoubleList->Push(node4);
	DoubleList->Push(node5);

	DoubleList->PrintList();

	cout << endl;
	DoubleLinkedList<int>::Node* AddNode1 = DoubleLinkedList<int>::Create(35);
	DoubleLinkedList<int>::Node* AddNode2 = DoubleLinkedList<int>::Create(45);

	DoubleList->Insert(AddNode1, 3);
	DoubleList->Insert(AddNode2, node4);
	cout << "노드 추가 후 List" << endl;
	DoubleList->PrintList();

	cout << endl;

	//DoubleList->Remove(AddNode1);
	DoubleList->Remove(head);
	DoubleList->Remove(5);
	cout << "노드 삭제 후 List" << endl;
	DoubleList->PrintList();

	return 0;
}