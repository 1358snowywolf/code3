#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(map<int, vector<pair<int, int>>> graph, int source){
	vector<int> answer (graph.size(), INT_MAX);
	priority_queue<pair<int, int>> pq;
	answer[source] = 0;
	pq.push({0, source});

	while(!pq.empty()){
		pair<int, int> front = pq.top();
		int distance = front.first * -1;
		int u = front.second;
		pq.pop();

		if(distance > answer[u]){
			continue;
		}

		for(auto v : graph[front.second]){
			if(answer[u] + v.second < answer[v.first]){
				answer[v.first] = answer[u] + v.second;
				pq.push({answer[v.first] * -1, v.first});
			}
		}
	}

	return answer;
}

int main() {
	map<int, vector<pair<int, int>>> graph;
	vector<pair<int, int>> zero = {{1, 11}, {3, 5}, {2, 4}};
	vector<pair<int, int>> first = {{0, 11}, {3, 15}, {4, 8}};
	vector<pair<int, int>> second = {{0, 4}, {3, 14}};
	vector<pair<int, int>> third = {{1, 15}, {2, 14}, {4, 17}};
	vector<pair<int, int>> four = {{1, 8}, {3, 17}};
	graph.insert({0, zero});
	graph.insert({1, first});
	graph.insert({2, second});
	graph.insert({3, third});
	graph.insert({4, four});

	vector<int> distance = dijkstra(graph, 0);

	for(int i = 0; i < (int) distance.size(); i++){
		cout << distance[i] << " ";
	}

	return 0;
}
