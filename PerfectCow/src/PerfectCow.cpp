//============================================================================
// Name        : PerfectCow.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> total;
	int N;
	cin >> N;

	for(int i = 0; i < N; i++){
		vector<int> row;
		for(int i = 0; i < N; i++){ //row
			int input;
			cin >> input;
			row.push_back(input);
		}

		sort(row.begin(), row.end());
		total.push_back(row[(int) row.size() / 2]);
	}

	sort(total.begin(), total.end());

	cout << total[(int) total.size() / 2] << endl;

	return 0;
}
