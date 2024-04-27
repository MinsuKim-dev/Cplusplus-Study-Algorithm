#include <iostream>
#include <vector>
using namespace std;

// 탐색
// 탐색은 특정 알고리즘에 의해서 순회하는 것

// 탐색 방법
// 깊이 우선 탐색 : DFS - Depth First Search
// 너비 우선 탐색 : BFS - Breadth First Search

// 깊이 우선 탐색은 되돌아 오지 않고 끝까지 탐색하는 방법
// 너비 우선 탐색은 시작점에서 가까운 곳부터 차례대로 탐색하는 방법

struct Vertex
{

};

vector<Vertex> vertices;
vector<vector<int>> adjacent; // 인접목록
vector<vector<int>> adjacent_matrix; // 인접행렬

// DFS
vector<bool> visited; // 방문목록
// 끝까지 탐색하려면 이미 탐색을 했는지에 대한 여부를 기억해야 함

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);

	// 인접 리스트
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);

	// 인접 행렬
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
void DFS(int here) // 어디서부터 탐색을 했는가?
{
	// 시작점 방문!
	visited[here] = true;
	cout << "VISITED : " << here << endl;

	// 인접 리스트 버전 - 모든 인접 정점을 순회한다.
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];

		if (visited[there] == false)
			DFS(there); // 재귀 함수 사용
	}

	// 인접 행렬 버전 - 모든 인접 정점을 순회한다.
	/*
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳이 있으면 방문한다.
		if (visited[there] == false)
			DFS(there);
	}
	*/
}

// DFS로 탐색하지 못한 정점들을 처리하기 위해 한 번더 순회
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