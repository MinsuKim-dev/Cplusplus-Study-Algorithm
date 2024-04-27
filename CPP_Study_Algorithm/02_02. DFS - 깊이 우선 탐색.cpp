#include <iostream>
#include <vector>
using namespace std;

// Ž��
// Ž���� Ư�� �˰��� ���ؼ� ��ȸ�ϴ� ��

// Ž�� ���
// ���� �켱 Ž�� : DFS - Depth First Search
// �ʺ� �켱 Ž�� : BFS - Breadth First Search

// ���� �켱 Ž���� �ǵ��� ���� �ʰ� ������ Ž���ϴ� ���
// �ʺ� �켱 Ž���� ���������� ����� ������ ���ʴ�� Ž���ϴ� ���

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent; // �������
vector<vector<int>> adjacent_matrix; // �������

// DFS
vector<bool> visited; // �湮���
// ������ Ž���Ϸ��� �̹� Ž���� �ߴ����� ���� ���θ� ����ؾ� ��

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);

	// ���� ����Ʈ
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

	// ���� ���
	adjacent_matrix = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0,},
		{ 0, 0, 0, 0, 1, 0,},
		{ 0, 0, 0, 0, 0, 0,},
		{ 0, 0, 0, 0, 1, 0,},
	};
}

// DFS
void DFS(int here) // ��𼭺��� Ž���� �ߴ°�?
{
	// ������ �湮!
	visited[here] = true;
	cout << "VISITED : " << here << endl;

	// ���� ����Ʈ ���� - ��� ���� ������ ��ȸ�Ѵ�.
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];

		if (visited[there] == false)
			DFS(there); // ��� �Լ� ���
	}

	// ���� ��� ���� - ��� ���� ������ ��ȸ�Ѵ�.
	/*
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		// ���� �湮���� ���� ���� ������ �湮�Ѵ�.
		if (visited[there] == false)
			DFS(there);
	}
	*/
}

// DFS�� Ž������ ���� �������� ó���ϱ� ���� �� ���� ��ȸ
void DFS_ALL()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
		if (visited[i] == false)
			DFS(i);
}

int main()
{
	CreateGraph();
	DFS_ALL();
}