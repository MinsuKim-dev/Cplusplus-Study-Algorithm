#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 다익스트라 알고리즘
// 모든 정점까지의 최단거리를 구하는 알고리즘

// BFS와의 차이점
// BFS는 발견한 순서대로 방문을 함
// Dijkstra Algorithm은 발견 순서와 방문 순서가 다를 수도 있고 간선 비용을 계산 비교하여 방문함

// Dijkstra Algorithm
// 시작점을 기준으로 가장 가까이에 있는 정점을 방문하고자 인접한 모든 정점을 스캔

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent; // 인접 행렬

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	
	adjacent[0][1] = 15;
	adjacent[0][3] = 35;
	adjacent[1][0] = 15;
	adjacent[1][2] = 5;
	adjacent[1][3] = 10;
	adjacent[3][4] = 5;
	adjacent[5][4] = 5;
}

void Dijkstra(int here)
{
	struct VertexCost
	{
		int vertex;
		int cost;
	};

	list<VertexCost> discovered; // 발견 목록, 먼저 발견 했다고 먼저 방문한다는 보장이 없기 때문에 queue대신 list로
	vector<int> best(6, INT32_MAX); // 각 정점별로 지금까지 발견한 최소 거리
	vector<int> parent(6, -1); // 경로 추적

	// 초기화 및 시작점 설정
	discovered.push_back(VertexCost{ here, 0 });
	best[here] = 0;
	parent[here] = here;

	while (discovered.empty() == false)
	{
		// 제일 좋은 후보를 찾는다
		list<VertexCost>::iterator bestIt;
		int bestCost = INT32_MAX;

		for (auto it = discovered.begin(); it != discovered.end(); ++it)
		{
			if (it->cost < bestCost)
			{
				bestCost = it->cost;
				bestIt = it;
			}
		}

		// 제일 좋은 후보를 꺼낸다.
		int cost = bestIt->cost;
		here = bestIt->vertex;
		discovered.erase(bestIt);

		// 방문? 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost)
			continue;

		// 실제 방문
		for (int there = 0; there < 6; there++)
		{
			// 연결되지 않았으면 스킵
			if (adjacent[here][there] == -1)
				continue;

			// 더 좋은 경로를 이전에 찾았으면 스킵
			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
				continue;

			discovered.push_back(VertexCost{ there, nextCost });
			best[there] = nextCost;
			parent[there] = here;
		}
	}

	int a = 3; // 디버깅 용도
}

int main()
{
	CreateGraph();
	Dijkstra(0);
}