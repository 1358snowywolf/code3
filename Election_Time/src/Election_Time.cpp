#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<tuple<int, int, int> > results;

	if(N == 1){
		cout << 1 << endl;
		return 0;
	}

	for(int i = 0; i < N; i++){
		int first, second;
		cin >> first >> second;
		results.push_back(make_tuple(first, second, i));
	}

	sort(results.begin(), results.end());
	reverse(results.begin(), results.end());
	vector<tuple<int, int, int> > finals;

	for(int i = 0; i < K; i++){
		finals.push_back(results[i]);
	}

	int a, b, c, d, e, f;
	tie(a, b, c) = finals[0];
	int maximum = 0;

	for(int i = 1; i < (int) finals.size(); i++){
		tie(a, b, c) = finals[i];
		tie(d, e, f) = finals[maximum];

		if(b > e){
			maximum = i;
		}
	}

	tie(a, b, c) = finals[maximum];
	cout << c + 1 << endl;

	return 0;
}