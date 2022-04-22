#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> tree;
	BinarySearchTree<int>::Node* root = BinarySearchTree<int>::CreateNode(12);

	tree.Root(root);

	tree.Insert(&root, BinarySearchTree<int>::CreateNode(22));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(99));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(42));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(17));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(3));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(98));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(34));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(75));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(32));
	tree.Insert(&root, BinarySearchTree<int>::CreateNode(1));

	tree.InOrder(root, 0);

	cout << endl;

	int depth = 0;
	BinarySearchTree<int>::Node* node = tree.Search(root, 98, depth);
	cout << "찾기 : " << node->Data << ", " << depth << "번" << endl;

	int a = 0;

	node = tree.Remove(root, NULL, 98);
	cout << "삭제 노드 : " << node->Data << endl;
	BinarySearchTree<int>::DestoryNode(&node);

	cout << endl;

	tree.InOrder(root, 0);
	cout << endl;

	return 0;
}