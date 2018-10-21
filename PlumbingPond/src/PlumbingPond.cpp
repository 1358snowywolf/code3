#include <bits/stdc++.h>

using namespace std;

bool moreTwo(vector<vector<int>> pond, int i, int j){
	int count = 0;

	for(int x = -1; x <= 1; x++){
		for(int y = -1; y <= 1; y++){
			if(x + i < 0 || x + i >= (int) pond.size()){
				continue;
			}
			if(y + j < 0 || y + j >= (int) pond[0].size()){
				continue;
			}

			if(pond[i][j] == pond[i + x][j + y]){
				count++;

				if(count >= 2){
					return true;
				}
			}
		}
	}

	if(count >= 2){
		return true;
	}
	else{
		return false;
	}
}

int main() {
	int R, C;
	cin >> R >> C;
	int maximum = INT_MIN;
	vector<vector<int>> pond;

	for(int i = 0; i < R; i++){
		vector<int> row;
		for(int j = 0; j < C; j++){
			int input;
			cin >> input;
			row.push_back(input);
		}
		pond.push_back(row);
	}

	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(moreTwo(pond, i, j)){
				maximum = max(maximum, pond[i][j]);
			}
		}
	}

	cout << maximum << endl;

	return 0;
}
