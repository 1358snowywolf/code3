#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> first;
vector<pair<int, int>> second;
vector<pair<int, int>> third;

void floodfill(vector<vector<char>>& hide, char spot, int i, int j){
	if(i < 0 || i >= (int) hide.size()){
		return;
	}
	if(j < 0 || j >= (int) hide[0].size()){
		return;
	}
	if(hide[i][j] != 'X'){
		return;
	}

	if(spot == '1'){
		first.push_back({i, j});
	}
	if(spot == '2'){
		second.push_back({i, j});
	}
	if(spot == '3'){
		third.push_back({i, j});
	}

	hide[i][j] = spot;
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	for(int k = 0; k < 4; k++){
		floodfill(hide, spot, i + dx[k], j + dy[k]);
	}
}

void BFS(vector<vector<char>> hide, vector<pair<int, int>> root, vector<vector<int>>& fill){
	int index = 0;
	queue<pair<int, int>> q;
	set<pair<int, int>> visited;
	for(auto p : root){
		visited.insert(p);
		q.push(p);
	}

	q.push(make_pair(-1, -1));
	int dx[] = {0, -1, 1, 0};
	int dy[] = {1, 0, 0, -1};

	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();

		if(top == make_pair(-1, -1)){
			if(q.empty()){
				break;
			}

			index++;
			q.push(make_pair(-1, -1));
			continue;
		}

		if(hide[top.first][top.second] == '.'){
			fill[top.first][top.second] = index;
		}

		for(int k = 0; k < 4; k++){
			if(top.first + dx[k] < 0 || top.first + dx[k] >= (int) hide.size()){
				continue;
			}
			if(top.second + dy[k] < 0 || top.second + dy[k] >= (int) hide[0].size()){
				continue;
			}
			if(visited.find(make_pair(top.first + dx[k], top.second + dy[k])) != visited.end()){
				continue;
			}

			visited.insert(make_pair(top.first + dx[k], top.second + dy[k]));
			q.push(make_pair(top.first + dx[k], top.second + dy[k]));
		}
	}
}

int connect(vector<vector<int>> one, vector<vector<int>> two, vector<vector<int>> three, vector<vector<char>> hide){
	int minimum = INT_MAX;

	for(int i = 0; i < (int) hide.size(); i++){
		for(int j = 0; j < (int) hide[0].size(); j++){
			if(hide[i][j] == '.'){
				minimum = min(minimum, one[i][j] + two[i][j] + three[i][j]);
			}
		}
	}

	return minimum;
}

int main() {
	int N, M;
	vector<vector<char>> hide;
	cin >> N >> M;
	vector<vector<int>> one (N, vector<int> (M, 0));
	vector<vector<int>> two (N, vector<int> (M, 0));
	vector<vector<int>> three (N, vector<int> (M, 0));

	for(int i = 0; i < N; i++){
		vector<char> row;

		for(int j = 0; j < M; j++){
			char input;
			cin >> input;
			row.push_back(input);
		}

		hide.push_back(row);
	}

	int spot = '1';

	for(int i = 0; i < (int) hide.size(); i++){
		for(int j = 0; j < (int) hide[i].size(); j++){
			if(hide[i][j] == '.' || hide[i][j] == '1' || hide[i][j] == '2'){
				continue;
			}

			floodfill(hide, spot, i, j);

			if(spot == '1'){
				spot = '2';
			}
			else if(spot == '2'){
				spot = '3';
			}
			else{
				break;
			}
		}
	}

	BFS(hide, first, one);
	BFS(hide, second, two);
	BFS(hide, third, three);
	int center = connect(one, two, three, hide);
	int minimum12 = INT_MAX;
	int minimum23 = INT_MAX;
	int minimum13 = INT_MAX;

	for(int i = 0; i < (int) first.size(); i++){
		for(int j = 0; j < (int) second.size(); j++){
			int distance = abs(first[i].first - second[j].first) + abs(first[i].second - second[j].second);
			if(distance < minimum12){
				minimum12 = distance;
			}
		}
	}

	for(int i = 0; i < (int) first.size(); i++){
		for(int j = 0; j < (int) third.size(); j++){
			int distance = abs(first[i].first - third[j].first) + abs(first[i].second - third[j].second);

			if(distance < minimum13){
				minimum13 = distance;
			}
		}
	}

	for(int i = 0; i < (int) second.size(); i++){
		for(int j = 0; j < (int) third.size(); j++){
			int distance = abs(second[i].first - third[j].first) + abs(second[i].second - third[j].second);

			if(distance < minimum23){
				minimum23 = distance;
			}
		}
	}

	cout << min(center, min(minimum12 + minimum23, min(minimum12 + minimum13, minimum13 + minimum23))) - 2 << endl;

	return 0;
}
