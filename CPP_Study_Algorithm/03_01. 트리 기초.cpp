#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// 트리 기초

// 트리의 개념
// : 계층적 구조를 갖는 데이터를 표현하기 위한 자료구조
// 노드(Node) - 데이터를 표현
// 간선(Edge) - 노드의 계층 구조를 표현

// 트리의 예시) 기업 조직 구성도, 파일 탐색기 구조

// 트리 용어
// 부모 노드 : parent
// 자식 노드 : child
// 형제 노드 : sibling
// 선조		 : ancestor
// 자손		 : descendant
// 루트		 : root								- 최상위 노드
// 잎		 : leaf
// 깊이		 : depth							- root로부터 몇 번 째 층인가?
// 높이		 : height							- root로부터 트리는 몇 층이 있는가?
// 트리의 재귀적 속성 및 서브 트리 : subtree	- 트리의 일부분을 개별적으로 봐도 트리다.
// 트리는 재귀함수와 자주 사용된다.

// 범위 기반 for문
// for(지역 변수 : array)
// 루프는 각 배열의 요소를 반복하여 지역 변수에 현재 배열 요소의 값을 할당한다.
// 루프에 포함되는 배열은 배열의 크기를 알 수 있는 상태여야 한다.

using NodeRef = shared_ptr<struct Node>;

struct Node
{
	Node() { }
	Node(const string& data) : data(data) { }
	string			data;
	vector<NodeRef>	children;
};

NodeRef CreateTree()
{
	NodeRef root = make_shared<Node>("개발실");
	{
		NodeRef node = make_shared<Node>("디자인팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("전투");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("경제");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("스토리");
			node->children.push_back(leaf);
		}
	}
	{
		NodeRef node = make_shared<Node>("프로그래밍팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("서버");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("클라");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("엔진");
			node->children.push_back(leaf);
		}
	}
	{
		NodeRef node = make_shared<Node>("아트팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("배경");
			node->children.push_back(leaf);
		}
		{
			NodeRef leaf = make_shared<Node>("캐릭터");
			node->children.push_back(leaf);
		}
	}
	return root;
}

void PrintTree(NodeRef root, int depth)
{
	for (int i = 0; i < depth; i++)
		cout << "-";

	cout << root->data << endl;

	for (NodeRef& child : root->children)
	{
		PrintTree(child, depth + 1);
	}
}

// 깊이(depth)	: 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수 (aka. 몇 층?)
// 높이(height)	: 가장 깊숙히 있는 노드의 깊이 (max(depth))
int GetHeight(NodeRef root)
{
	int height = 1;

	for (NodeRef& child : root->children)
	{
		height = max(height, GetHeight(child) + 1);
	}

	return height;
}

int main()
{
	NodeRef root = CreateTree();
	PrintTree(root, 0);

	int height = GetHeight(root);
}