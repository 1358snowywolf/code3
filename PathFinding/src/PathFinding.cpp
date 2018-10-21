//============================================================================
// Name        : PathFinding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	queue<int> q;
	unordered_set<int> visited;
	map<int, vector<int>> graph;

	for(int i = 0; i < N; i++){
		vector<int> input;
		graph.insert({i, input});
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int input;
			cin >> input;

			if(input != 0){
				graph[i].push_back(j);
			}
		}
	}

//	for(auto i : graph){
//		for(int number : i.second){
//			cout << number << " ";
//		}
//		cout << endl;
//	}

	vector<int> output;

	q.push(M - 1);
	visited.insert(M - 1);
	q.push(-1);

	while(!q.empty()){
		int top = q.front();
		q.pop();

		if(top == -1){
			sort(output.begin(), output.end());

			for(int i = 0; i < output.size(); i++){
				cout << output[i];
				if(i != output.size() - 1){
					cout << " ";
				}
			}

			cout << endl;

			output.clear();

			if(q.empty()){
				break;
			}

			q.push(-1);
			continue;
		}

		output.push_back(top + 1);

//		if(q.size() > 1){
//			cout << " ";
//		}

		for(int i : graph[top]){
			if(visited.find(i) == visited.end()){
//				cout << "push" << i;
//				cout << endl;
				q.push(i);
				visited.insert(i);
			}
		}
	}

	return 0;
}
