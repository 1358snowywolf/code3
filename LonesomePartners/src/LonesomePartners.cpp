//============================================================================
// Name        : LonesomePartners.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int one, two;
	float maximum = 0;
	vector<pair<int, int>> cows;
	cin >> N;

	for(int i = 0; i < N; i++){
		int first, second;
		cin >> first >> second;
		cows.push_back(make_pair(first, second));
	}

	for(int i = 0; i < (int) cows.size(); i++){
		for(int j = i + 1; j < (int) cows.size(); j++){
			float xDifference = (cows[i].first - cows[j].first) * (cows[i].first - cows[j].first);
			float yDifference = (cows[i].second - cows[j].second) * (cows[i].second - cows[j].second);
			float input = sqrt((xDifference + yDifference));

			if(input > maximum){
				one = i;
				two = j;
				maximum = input;
			}
		}
	}

	cout << min(one, two) + 1 << " " << max(one, two) + 1 << endl;

	return 0;
}
