//============================================================================
// Name        : GoodGrass.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int findSum(vector<vector<int>> field, int i, int j){
	int sum = 0;

	for(int x = -1; x <= 1; x++){
		if(i + x >= (int) field.size() || i + x < 0){
			continue;
		}

		for(int y = -1; y <= 1; y++){
			if(j + y >= (int) field[i].size() || j + y < 0){
				continue;
			}

			sum += field[i + x][j + y];
		}
	}

	return sum;
}

int main() {
	int NR, NC;
	cin >> NR >> NC;
	vector<vector<int>> field;

	for(int i = 0; i < NR; i++){
		vector<int> row;

		for(int j = 0; j < NC; j++){
			int input;
			cin >> input;
			row.push_back(input);
		}

		field.push_back(row);
	}

	int maximum = INT_MIN;
	pair<int, int> coordinate = make_pair(0, 0);

	for(int i = 0; i < NR; i++){
		for(int j = 0; j < NC; j++){
			int sum = findSum(field, i, j);

			if(maximum < sum){
				maximum = sum;
				coordinate.first = i - 1;
				coordinate.second = j - 1;
			}
		}
	}

	cout << maximum << endl;
	cout << coordinate.first + 1 << " " << coordinate.second + 1 << endl;

	return 0;
}
