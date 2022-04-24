#include "LinkedList.h"

int main()
{
	LinkedList<int>::Node* head = LinkedList<int>::Create(10); // ��� ��� ����
	LinkedList<int>::Node* node1 = LinkedList<int>::Create(20); // ��� ����
	LinkedList<int>::Node* node2 = LinkedList<int>::Create(30); // ��� ����
	LinkedList<int>::Node* node3 = LinkedList<int>::Create(40); // ��� ����
	LinkedList<int>::Node* node4 = LinkedList<int>::Create(50); // ��� ����
	LinkedList<int>::Node* node5 = LinkedList<int>::Create(60); // ��� ����

	LinkedList<int>* List = new LinkedList<int>(head);
	List->Push(node1);
	List->Push(node2);
	List->Push(node3);
	List->Push(node4);
	List->Push(node5);

	int listCount = List->GetNodeCount();
	LinkedList<int>::Node* current = List->GetNode(4); // ���� ����� ������ �� 50
	LinkedList<int>::Node* AddNode = LinkedList<int>::Create(70); // ��� ����
	LinkedList<int>::Node* AddNode2 = LinkedList<int>::Create(80); // ��� ����

	List->Insert(AddNode, current);
	List->Insert(AddNode2, 5);
	//List->PrintList();

	LinkedList<int>::Node* AddNode3 = LinkedList<int>::Create(100); // ��� ����
	LinkedList<int>::Node* node6 = LinkedList<int>::Create(200);
	List->Insert(AddNode3, node6);
	List->Insert(AddNode3, 10);
	List->Insert(AddNode3, -1);

	cout << "���� �� List" << endl;
	List->PrintList();
	cout << endl;
	List->Remove();
	cout << "���� �� List" << endl;
	List->PrintList();

	return 0;
}