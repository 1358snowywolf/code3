#include <bits/stdc++.h>

using namespace std;
int possible = 0;

void recursion(vector<vector<pair<bool, int>>> DP, vector<int> values, set<int> used, int i, int j){
	if(i < 0 || j < 0){
		return;
	}
	if(!DP[i][j].first){
		return;
	}

	if(j == 0){
		for(auto itr : used){
			cout << itr << " ";
		}

		cout << endl;
		possible++;
		return;
	}

	recursion(DP, values, used, i - 1, j);
	used.insert(values[i - 1]);
	recursion(DP, values, used, i - 1, j - values[i - 1]);
}

int main() {
	int sum = 8;
	set<int> numbers;
	vector<int> values = {3, 34, 4, 12, 5, 2, 6};
	vector<vector<pair<bool, int>>> DP (values.size() + 1, vector<pair<bool, int>> (sum + 1, make_pair(false, 0)));

	for(int i = 0; i < (int) DP.size(); i++){
		DP[i][0].first = true;
		DP[i][0].second = 1;
	}

	for(int i = 1; i < (int) DP.size(); i++){
		for(int j = 1; j < (int) DP[i].size(); j++){
			DP[i][j].first = DP[i - 1][j].first || ((j - values[i - 1] >= 0) ?  DP[i - 1][j - values[i - 1]].first : false);

			if(DP[i][j].first){
				DP[i][j].second = DP[i - 1][j].second + ((j - values[i - 1] >= 0) ?  DP[i - 1][j - values[i - 1]].second : 0);
			}
		}
	}

	cout << "Possible? " << ((DP[DP.size() - 1][DP[0].size() - 1].first) ? "Yes" : "No") << endl;
	cout << "Ways? " << DP[DP.size() - 1][DP[0].size() - 1].second << endl;
	cout << "Numbers used: " << endl;
	recursion(DP, values, numbers, DP.size() - 1, DP[0].size() - 1);

	return 0;
}