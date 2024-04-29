#include <iostream>
#include <vector>
using namespace std;
#include <queue>

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

// BFS
vector<bool> discovered; // 발견 여부

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

// BFS는 큐로 예약 시스템을 만들면 된다.
void BFS(int here)
{
	// 누구에 의해서 발견 되었는지?
	vector<int> parent(6, -1);

	// 시작 점에서 얼만큼 떨어져 있는지?
	vector<int> distance(6, -1);

	queue<int> q;
	q.push(here); // 발견한 순서를 밀어 넣어줌
	discovered[here] = true;
	parent[here] = here;
	distance[here] = 0;

	while (q.empty() == false) 
	{
		here = q.front();
		q.pop();

		cout << "VISITED : " << here << endl;

		for (int there : adjacent[here]) // int there = 0; there < 6; there++ - 인접 행렬
		{
			if (discovered[there]) // adjacent[here][there] == 0 - 인접 행렬
				continue;

			q.push(there); // 다음 큐를 예약하고
			discovered[there] = true; // 발견 상태를 'true'로

			parent[there] = here; // 누구에 의해서 발견 되었는지?
			distance[there] = distance[here] + 1; // 시작 점에서 얼만큼 떨어져 있는지?
		}
	}
	// DFS는 발견한 순서와 방문한 순서가 일치하지만
	// BFS는 발견만 하고 방문하지 않을 수도 있다.
}

// 모든 정점 순회
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