#include <iostream>
#include <vector>
using namespace std;
#include <queue>

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

// BFS
vector<bool> discovered; // �߰� ����

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

// BFS�� ť�� ���� �ý����� ����� �ȴ�.
void BFS(int here)
{
	// ������ ���ؼ� �߰� �Ǿ�����?
	vector<int> parent(6, -1);

	// ���� ������ ��ŭ ������ �ִ���?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here); // �߰��� ������ �о� �־���
	discovered[here] = true;
	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false) 
	{
		here = q.front();
		q.pop();

		cout << "VISITED : " << here << endl;

		for (int there : adjacent[here]) // int there = 0; there < 6; there++ - ���� ���
		{
			if (discovered[there]) // adjacent[here][there] == 0 - ���� ���
				continue;

			q.push(there); // ���� ť�� �����ϰ�
			discovered[there] = true; // �߰� ���¸� 'true'��

			parent[there] = here; // ������ ���ؼ� �߰� �Ǿ�����?
			distance[there] = distance[here] + 1; // ���� ������ ��ŭ ������ �ִ���?
		}
	}
	// DFS�� �߰��� ������ �湮�� ������ ��ġ������
	// BFS�� �߰߸� �ϰ� �湮���� ���� ���� �ִ�.
}

// ��� ���� ��ȸ
void BSF_ALL()
{
	for (int i = 0; i < 6; i++)
		if (discovered[i] == false)
			BFS(i);
}

int main()
{
	CreateGraph();

	discovered = vector<bool>(6, false);
	BSF_ALL();

}