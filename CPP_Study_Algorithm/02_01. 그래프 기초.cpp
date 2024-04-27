#include <iostream>
#include <vector>
using namespace std;

// �׷��� ����

// �׷����� ���� ������ �繰�̳� �߻����� ���� ���� ���� ���踦 ǥ��
// ����(Vertex) : �����͸� ǥ��(�繰, ���� ��)
// ����(Edge)	: �������� �����ϴµ� ���
// ������ ���� ���� ������ ���� �� �� �ִ�.

// ����ġ �׷���(Weighted Graph)
// ������ ��� �Ǿ� �ִ°�

// ���� �׷���(Directed Graph)
// ������ ������ �ִ� �׷���

// -----------------------------------------------------------------------------------
// ���� �׷��� ǥ��
void CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0���� 3�� ������ ����Ǿ� �ֳ���?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}

	// ���� ��� for��
	// for(TYPE NAME : DATA_LIST)
	// ������ for���� �޸�, ���۰� ������ �˷����� �ʾƵ� �˾Ƽ� ó������ ������ ��ȸ
}

// ����� ����� ���� ����
void CreateGraph_2()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	vector<vector<int>> adjacent(6); // adjacent = ������

	// adjacent[n] -> n�� ° ������ ����� ���� ���
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// Q) 0���� 3�� ������ ����Ǿ� �ֳ���?
	int connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}

	// STL
	vector<int>& adj = adjacent[0];
	bool connectedFind = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}

// ������ ��û ���ٸ�?
// ����ö �뼱��ó�� �幮 �幮 ����Ǿ� �ִٸ� vector����� �״�� ����ص� ������
// �����ϰ� ���� �Ǿ� �ִٸ�, ã�ų� ��ȸ�ϴµ� ���� �ɸ���.
// ���� ��İ��� 2�� �迭�� �̿��ϴ� ���� ����.

void CreateGraph_3()
{
	struct Vertex
	{
		
	};

	vector<Vertex> v;
	v.resize(6);

	vector<vector<int>> adjacent(6);

	// [X][O][X][O][X][X]
	// [O][X][O][O][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]
	// [X][X][X][X][X][X]
	// [X][X][X][X][O][X]
	// �޸𸮸� ���� �Ҹ������� ������ ������ �� �ִ� ������ ����

	// �д� ��� : adjacent[from][to]
	// ����� �̿��� �׷��� ǥ��(2���� �迭)
	// �޸� �Ҹ� ��������, ���� ������ �����ϴ�.
	// ������ ���� ��� ������ �ִ�.
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// Q) 0���� 3�� ������ ����Ǿ� �ֳ���?
	bool connected = adjacent[0][3];
}

// -----------------------------------------------------------------------------------
// ����ġ �׷��� ǥ��
void CreateGraph_4()
{
	struct Vertex
	{

	};

	vector<Vertex> v;
	v.resize(6);

	vector<vector<int>> adjacent =
	{
		vector<int> { -1, 15, -1, 35, -1, -1 },
		vector<int> { 15, -1, +5, 10, -1, -1 },
		vector<int> { -1, -1, -1, -1, -1, -1 },
		vector<int> { -1, -1, -1, -1, +5, -1 },
		vector<int> { -1, -1, -1, -1, -1, -1 },
		vector<int> { -1, -1, -1, -1, +5, -1 },
	};

	// Q) 0���� 3�� ������ ����Ǿ� �ֳ���?
	bool connected = (adjacent[0][3] != -1);
	int value = adjacent[0][3];
}


int main()
{
	CreateGraph_1();
	CreateGraph_2();
	CreateGraph_3();
	CreateGraph_4();
}
