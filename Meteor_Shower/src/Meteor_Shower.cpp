#include <bits/stdc++.h>

using namespace std;


int main() {
	int M;
	cin >> M;
	int time = 0;
	int destroyed[310][310];
	vector<int> dx = {0, -1, 1, 0};
	vector<int> dy = {1, 0, 0, -1};

	for(int i = 0; i < 310; i++){
		for(int j = 0; j < 310; j++){
			destroyed[i][j] = INT_MAX;
		}
	}

	set<pair<int, int>> visited;
	queue<pair<int, int>> meteors;

	for(int i = 0; i < M; i++){
		int X, Y, T;
		cin >> X >> Y >> T;

		destroyed[X][Y] = min(destroyed[X][Y], T);

		for(int j = 0; j < 4; j++){
			if(X + dx[j] < 0 || X + dx[j] >= 310){
				continue;
			}
			if(Y + dy[j] < 0 || Y + dy[j] >= 310){
				continue;
			}

			destroyed[X + dx[j]][Y + dy[j]] = min(destroyed[X + dx[j]][Y + dy[j]], T);
		}
	}

	meteors.push(make_pair(0, 0));
	meteors.push(make_pair(-1, -1));

	time = 0;
	while(!meteors.empty()){
		pair<int, int> node = meteors.front();
		meteors.pop();

		if(node.first == -1 && node.second == -1 && !meteors.empty()){
			meteors.push(make_pair(-1, -1));
			time++;
			continue;
		}
		if(destroyed[node.first][node.second] <= time){
			continue;
		}
		if(destroyed[node.first][node.second] == INT_MAX){
			cout << time << endl;
			return 0;
		}


		for(int i = 0; i < (int) dx.size(); i++) {
			int x = node.first + dx[i];
			int y = node.second + dy[i];

			if(x < 0 || x >= 310){
				continue;
			}
			if(y < 0 || y >= 310){
				continue;
			}
			if(visited.find(make_pair(x, y)) != visited.end()){
				continue;
			}
			if(destroyed[x][y] <= time){
				continue;
			}

			visited.insert(make_pair(x, y));
			meteors.push(make_pair(x, y));
		}
	}
	cout << -1 << endl;

	return 0;
}