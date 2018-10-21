
#include <bits/stdc++.h>

using namespace std;

float solve(string str){
	map<char, int> functions;
	functions.insert({'+', 1});
	functions.insert({'-', 2});
	functions.insert({'*', 5});
	functions.insert({'/', 6});
	stack<float> numbers;
	stack<int> operations;
	int level = 0;

	for(int i = 0; i < (int) str.size(); i++){
		if(isdigit(str[i])){
			numbers.push((float) (str[i] - '0'));
		}
		else if(str[i] == '('){
			level += 10;
		}
		else if(str[i] == ')'){
			level -= 10;
		}
		else{
			int x = (functions[str[i]] + level);

			while(!operations.empty() && x < operations.top()){
				float b = numbers.top();
				numbers.pop();
				float a = numbers.top();
				numbers.pop();
				int op = operations.top();
				operations.pop();

				if(op % 10 == 1){
					numbers.push((float) (a + b));
				}
				else if(op % 10 == 2){
					numbers.push((float) (a - b));
				}
				else if(op % 10 == 5){
					numbers.push((float) (a * b));
				}
				else{
					numbers.push((float (a) / b));
				}
			}

			operations.push(x);
		}
	}

	while((int) numbers.size() != 1){
		float b = numbers.top();
		numbers.pop();
		float a = numbers.top();
		numbers.pop();
		int op = operations.top();
		operations.pop();

		if(op % 10 == 1){
			numbers.push((float) (a + b));
		}
		else if(op % 10 == 2){
			numbers.push((float) (a - b));
		}
		else if(op % 10 == 5){
			numbers.push((float) (a * b));
		}
		else{
			numbers.push((float (a) / b));
		}
	}

	return numbers.top();
}

int main() {
	string algorithm = "1+2*3-4/5";
	cout << solve(algorithm) << endl;
	return 0;
}
