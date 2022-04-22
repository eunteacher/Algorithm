#include <string>
#include "BinaryTree.h"

void Expression(const char* postfix, BinaryTree<char>::Node** node)
{
	char* str = const_cast<char*>(postfix);

	size_t length = strlen(str);

	char tocken = str[length - 1]; // 제일 뒤에 글자
	str[length - 1] = '\0';
	
	switch (tocken)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		{
			*node = BinaryTree<char>::CreateNode(tocken);

			Expression(postfix, &(*node)->Right);
			Expression(postfix, &(*node)->Left);
		}
			break;

		default:
		{
			*node = BinaryTree<char>::CreateNode(tocken);
		}
			break;
	}
}

float Evaluate(BinaryTree<char>::Node* node)
{
	if (node == NULL)
	{
		return 0.0f;
	}

	switch (node->Data)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		{
			float left = Evaluate(node->Left);
			float right = Evaluate(node->Right);

			switch (node->Data)
			{
				case '+':return left + right;
				case '-':return left - right;
				case '*':return left * right;
				case '/':return left / right;
				case '%':return (int)left % (int)right;
			}
		}
			break;

		default:
		{
			char temp[4];
			memset(temp, 0, sizeof(temp));

			temp[0] = node->Data;

			return atof(temp);
		}
	}

	return 0.0f;
}

int main()
{
	BinaryTree<char>::Node* root = NULL;

	string postfix = "34*12+32/*-";
	Expression(postfix.c_str(), &root);

	BinaryTree<char> tree;
	tree.Root(root);

	cout << "-- PreOrder --" << endl;
	tree.PreOrder(root);

	cout << endl;

	cout << "-- InOrder --" << endl;
	tree.InOrder(root);

	cout << endl;

	cout << "-- PostOrder --" << endl;
	tree.PostOrder(root);

	cout << endl;

	cout << "Evaluate : " << Evaluate(root) << endl;

	return 0;
}