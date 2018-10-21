//============================================================================
// Name        : iCow.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int findMax(vector<int> ratings){
	int maximum = 0;

	for(int i = 0; i < (int) ratings.size(); i++){
		if(ratings[i] > ratings[maximum]){
			maximum = i;
		}
	}

	return maximum;
}

void change(vector<int>& ratings, int giving, int index){
	for(int i = 0; i < (int) ratings.size(); i++){
		if(index == i){
			continue;
		}

		ratings[i] += giving;
	}
}

void fix(vector<int>& ratings, int remainder, int index){
	int i = 0;

	while(remainder > 0){
		if(i != index){
			ratings[i]++;
			remainder--;
		}

		i++;
	}
}

int main() {
	int N, T;
	cin >> N >> T;
	vector<int> ratings;
	vector<int> answers;

	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		ratings.push_back(input);
	}

	if(N == 1){
		for(int i = 0; i < T; i++){
			cout << ratings[0] << endl;
		}

		return 0;
	}

	for(int i = 0; i < T; i++){
		if(i == N){
			break;
		}

		int index = findMax(ratings);
		answers.push_back(index + 1);
		int remainder = ratings[index] % (N - 1);
		int giving = ratings[index] / (N -1);
		ratings[index] = 0;

		change(ratings, giving, index);
		fix(ratings, remainder, index);
	}

	for(int i = 0; i < T; i++){
		cout << answers[i % (int) answers.size()] << endl;
	}

	return 0;
}
