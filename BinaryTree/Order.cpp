#include "BinaryTree.h"

int main()
{
	BinaryTree<char> tree;
	BinaryTree<char>::Node* A = tree.CreateNode('A');
	BinaryTree<char>::Node* B = tree.CreateNode('B');
	BinaryTree<char>::Node* C = tree.CreateNode('C');
	BinaryTree<char>::Node* D = tree.CreateNode('D');
	BinaryTree<char>::Node* E = tree.CreateNode('E');
	BinaryTree<char>::Node* F = tree.CreateNode('F');
	BinaryTree<char>::Node* G = tree.CreateNode('G');

	tree.Root(A);

	A->Left = B;

	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	cout << "PreOrder" << endl;
	tree.PreOrder(A);
	cout << endl;

	cout << "InOrder" << endl;
	tree.InOrder(A);
	cout << endl;

	cout << "PostOrder" << endl;
	tree.PostOrder(A);

	return 0;
}