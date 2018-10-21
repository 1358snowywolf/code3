#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, D;
	cin >> N >> D;
	vector<pair<int, int>> drops;
	int minimum = INT_MAX;
	int maximum = INT_MIN;

	for(int i = 0; i < N; i++){
		int X, Y;
		cin >> X >> Y;
		drops.push_back(make_pair(X, Y));
		minimum = min(minimum, Y);
		maximum = max(maximum, Y);
	}

	if(maximum - minimum < D){
		cout << -1 << endl;
		return 0;
	}

	sort(drops.begin(), drops.end());

	multiset<int> current;
	int i = 0, j = 0;
	int result = INT_MAX;
	current.insert(drops[0].second);

	while(true){
		if(i <= j && *current.rbegin() - *current.begin() >= D){
			result = min(result, abs(drops[i].first - drops[j].first));
			auto itr = current.find(drops[i].second);
			current.erase(itr);
			i++;
		}
		else{
			if(j == (int) drops.size() - 1){
				break;
			}
			else{
				current.insert(drops[++j].second);
			}
		}
	}

	cout << result << endl;

	return 0;
}
