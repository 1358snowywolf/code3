//============================================================================
// Name        : ThoseFads.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, L, K;
	int count = 0;
	cin >> N >> L >> K;
	vector<int> resistance;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		resistance.push_back(input);
	}

	sort(resistance.begin(), resistance. end());

	for(int i = 0; i < (int) resistance.size(); i++){
		if(resistance[i] > L){
			break;
		}

		L += K;
		count++;
	}

	cout << count << endl;

	return 0;
}
