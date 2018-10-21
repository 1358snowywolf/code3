//============================================================================
// Name        : Lookup.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> answer (N, 0);
	vector<int> heights;
	stack<int> indexes;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		heights.push_back(input);
	}

//	cout << "HERE" << endl;

	for(int i = 0; i < (int) heights.size(); i++){
		while(!indexes.empty() && heights[i] > heights[indexes.top()]){
			int top = indexes.top();
			indexes.pop();
			answer[top] = i + 1;
		}

		indexes.push(i);
	}

	for(int i = 0; i < N; i++){
		cout << answer[i] << endl;
	}

	return 0;
}
