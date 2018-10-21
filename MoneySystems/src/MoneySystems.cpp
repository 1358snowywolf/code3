/*
ID: isabell13
TASK: money
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int V, N;
	vector<int> coins;
	ifstream fin ("money.in");
	ofstream fout ("money.out");

	fin >> V >> N;

	for(int i = 0; i < V; i++){
		int input;
		fin >> input;
		coins.push_back(input);
	}

	vector<vector<long long>> dp (V + 1, vector<long long> (N + 1, 0));

	for(int i = 0; i <= V; i++){
		dp[i][0] = 1;
	}

	for(int i = 0; i <= (int) coins.size(); i++){
		for(int j = 1; j <= N; j++){
			dp[i][j] = (i - 1 < 0 ? 0 : dp[i - 1][j]) + (j - coins[i] < 0 ? 0 : dp[i][j - coins[i]]);
		}
	}

	fout << dp[V][N] << endl;

	return 0;
}
