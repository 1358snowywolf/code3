//============================================================================
// Name        : Knapsack0-1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
	int maxWeight = 50;
//	vector<int> answer (maxWeight + 1, 0);
	vector<int> value = {60, 100, 120};
	vector<int> weight = {10, 20, 30};

//	for(int i = 1; i < (int) answer.size(); i++){
//		int maximum = INT_MIN;
//
//		for(int j = 0; j < (int) value.size(); j++){
//			if(i - weight[j] < 0){
//				continue;
//			}
//
//			maximum = max(maximum, answer[i - weight[j] + value[j]]);
//		}
//
//		answer[i] = maximum;
//	}
//
//	cout << answer[maxWeight] << endl;

	vector<vector<int>> answer (value.size() + 1, vector<int> (maxWeight + 1, 0));

	for(int i = 1; i < (int) answer.size(); i++){
		for(int j = 1; j < (int) answer[i].size(); j++){
			answer[i][j] = max(answer[i - 1][j], (j - weight[i] < 0) ? 0 : answer[i - 1][j - weight[i]] + value[i]);
		}
	}

	for(int i = 0; i < (int) answer.size(); i++){
		for(int j = 0; j < (int) answer[i].size(); j++){
			cout << answer[i][j] << " ";
		}

		cout << endl;
	}

	cout << answer[value.size()][maxWeight] << endl;

	return 0;
}
