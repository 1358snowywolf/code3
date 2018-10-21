#include <bits/stdc++.h>

using namespace std;

int x[2000], y[2000];

int main() {
	int N;
	cin >> N;
	pair<int, int> answer;
	long long minimum = INT_MAX;
	vector<pair<int, int>> coordinates;

	for(int i = 0; i < N; i++){
		int X, Y;
		cin >> X >> Y;
//		coordinates.push_back(make_pair(x, y));
		x[i] = X;
		y[i] = Y;
	}

	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			int X = (coordinates[i].first - coordinates[j].first) * (coordinates[i].first - coordinates[j].first);
			int Y = (coordinates[i].second - coordinates[j].second) * (coordinates[i].second - coordinates[j].second);
//			long long  X = (x[i] - x[j]) * (x[i] - x[j]);
//			long long  Y = (y[i] - y[j]) * (y[i] - y[j]);

			long long distance = X + Y;

			if(distance < minimum){
				minimum = distance;
				answer.first = i + 1;
				answer.second = j + 1;
			}
		}
	}

	cout << answer.first  << " " << answer.second << endl;

	return 0;
}
