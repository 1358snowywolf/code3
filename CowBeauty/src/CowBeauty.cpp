#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> first;
vector<pair<int, int>> second;

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

	hide[i][j] = spot;
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	for(int k = 0; k < 4; k++){
		floodfill(hide, spot, i + dx[k], j + dy[k]);
	}

}

int main() {
	int N, M;
	ifstream fin ("pageant.in");
	ofstream fout ("pageant.out");
	vector<vector<char>> hide;
	fin >> N >> M;

	for(int i = 0; i < N; i++){
		vector<char> row;

		for(int j = 0; j < M; j++){
			char input;
			fin >> input;
			row.push_back(input);
		}

		hide.push_back(row);
	}

	int spot = '1';

	for(int i = 0; i < (int) hide.size(); i++){
		for(int j = 0; j < (int) hide[i].size(); j++){
			if(hide[i][j] == '.' || hide[i][j] == '1'){
				continue;
			}

			floodfill(hide, spot, i, j);
			spot = '2';
		}
	}

	int minimum = INT_MAX;
	for(int i = 0; i < (int) first.size(); i++){
		for(int j = 0; j < (int) second.size(); j++){
			int distance = abs(first[i].first - second[j].first) + abs(first[i].second - second[j].second);

			if(distance < minimum){
				minimum = distance;
			}
		}
	}

	fout << minimum - 1 << endl;
	return 0;
}
