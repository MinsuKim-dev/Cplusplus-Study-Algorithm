#include <iostream>
#include <vector>
using namespace std;

// 그래프 기초

// 그래프는 현실 세계의 사물이나 추상적인 개념 간의 연결 관계를 표현
// 정점(Vertex) : 데이터를 표현(사물, 개념 등)
// 간선(Edge)	: 정점들을 연결하는데 사용
// 정점은 여러 개의 정점과 연결 될 수 있다.

// 가중치 그래프(Weighted Graph)
// 연결이 어떻게 되어 있는가

// 방향 그래프(Directed Graph)
// 연결의 방향이 있는 그래프

// -----------------------------------------------------------------------------------
// 방향 그래프 표현
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

	// Q) 0번과 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}

	// 범위 기반 for문
	// for(TYPE NAME : DATA_LIST)
	// 기존의 for문과 달리, 시작과 끝점을 알려주지 않아도 알아서 처음부터 끝까지 순회
}

// 연결된 목록을 따로 관리
void CreateGraph_2()
{
	struct Vertex
	{
		vector<Vertex*> edges;
	};

	vector<Vertex> v;
	v.resize(6);

	vector<vector<int>> adjacent(6); // adjacent = 인접한

	// adjacent[n] -> n번 째 정점과 연결된 정점 목록
	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// Q) 0번과 3번 정점이 연결되어 있나요?
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

// 정점이 엄청 많다면?
// 지하철 노선도처럼 드문 드문 연결되어 있다면 vector방식을 그대로 사용해도 좋지만
// 빽빽하게 연결 되어 있다면, 찾거나 순회하는데 오래 걸린다.
// 따라서 행렬같은 2차 배열을 이용하는 것이 낫다.

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
	// 메모리를 많이 소모하지만 빠르게 접근할 수 있는 장점이 생김

	// 읽는 방법 : adjacent[from][to]
	// 행렬을 이용한 그래프 표현(2차원 배열)
	// 메모리 소모가 심하지만, 빠른 접근이 가능하다.
	// 간선이 많은 경우 이점이 있다.
	vector<vector<bool>> adjacent(6, vector<bool>(6, false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;

	// Q) 0번과 3번 정점이 연결되어 있나요?
	bool connected = adjacent[0][3];
}

// -----------------------------------------------------------------------------------
// 가중치 그래프 표현
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

	// Q) 0번과 3번 정점이 연결되어 있나요?
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
