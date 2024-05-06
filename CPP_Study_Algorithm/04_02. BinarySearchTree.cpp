#include "04_02. BinarySearchTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BinarySearchTree::PrintInOrder(Node* node)
{
	//   [중]
	// [좌][우]

	// 전위 순회 - preorder traverse
	// : [중]이 앞에 온다

	if (node == nullptr)
		return;
	
	cout << node->key << endl;
	PrintInOrder(node->left);
	PrintInOrder(node->right);

	// 중위 순회 - inorder
	// : [중]이 중간에 온다

	// 후위 순회 - postorder
	// : [중]이 마지막에 온다.
}

Node* BinarySearchTree::Search1(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		return Search1(node->left, key);
	else
		return Search1(node->right, key);
}

Node* BinarySearchTree::Search2(Node* node, int key)
{
	while (node && key != node->key)
	{
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	return node;
}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
		node = node->right;

	return node;
}

Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->prarent;

	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->prarent;
	}

	return parent;
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;

		if (key < node->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	newNode->prarent = parent;

	if (key < parent->key)
	{
		parent->left = newNode;
	}
	else
	{
		parent->right = newNode;
	}
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search1(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	if (node->left == nullptr)
	{
		Replace(node, node->right);
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	else
	{
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}
}

// u 서브 트리를 v 서브 트리로 교체
// 그리고 delete u
void BinarySearchTree::Replace(Node* u, Node* v)
{
	if (u->prarent == nullptr)
		_root = v;
	else if (u == u->prarent->left)
		u->prarent->left = v;
	else
		u->prarent->right = v;

	if (v)
		v->prarent = u->prarent;

	delete u;
}
