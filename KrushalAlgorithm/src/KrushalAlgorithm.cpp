//============================================================================
// Name        : KrushalAlgorithm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;
vector<int> parent;
vector<pair<int, int>> edges;

int findParent(int u){
	while(parent[u] != u){
		u = parent[u];
	}

	return u;
}

void join(int u, int v){
	int a = findParent(u);
	int b = findParent(v);

	if(a == b){
		return;
	}
	else{
		parent[a] = v;
		edges.push_back({u, v});
	}
}

int main() {
	for(int i = 0; i < 5; i++){
		parent.push_back(i);
	}

	vector<tuple<int, int, int>> graph;
	tuple<int, int, int> input = make_tuple(8, 0, 1);
	graph.push_back(input);
	input = make_tuple(6, 1, 4);
	graph.push_back(input);
	input = make_tuple(5, 1, 2);
	graph.push_back(input);
	input = make_tuple(1, 1, 3);
	graph.push_back(input);
	input = make_tuple(3, 2, 4);
	graph.push_back(input);
	input = make_tuple(4, 2, 3);
	graph.push_back(input);
	input = make_tuple(6, 0, 3);
	graph.push_back(input);

	sort(graph.begin(), graph.end());

	for(int i = 0; i < (int) graph.size(); i++){
		int a, b, c;
		tie(a, b, c) = graph[i];
		join(b, c);
	}

	for(int i = 0; i < (int) edges.size(); i++){
		cout << edges[i].first << " " << edges[i].second << endl;
	}

	for(int i = 0; i < (int) parent.size(); i++){
		cout << parent[i] << " ";
	}

	cout << endl;

	return 0;
}