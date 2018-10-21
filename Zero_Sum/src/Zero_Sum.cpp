/*
ID: isabell13
TASK: zerosum
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;
vector<string> solutions;
vector<char> methods = {' ', '+', '-'};
ifstream fin ("zerosum.in");
ofstream fout ("zerosum.out");
int N;

bool equalZero(vector<char> functions){
	stack<int> numbers;
	stack<char> operators;

	for(int i = (int) functions.size() + 1; i >= 1; i--){
		numbers.push(i);
	}

	for(int i = (int) functions.size() - 1; i >= 0; i--){
		operators.push(functions[i]);
	}

	while(!operators.empty()){
		char op = operators.top();
		operators.pop();
		int a = numbers.top();
		numbers.pop();
		int b = numbers.top();
		numbers.pop();

		if(op == ' '){
			numbers.push(10 * a + b);
		}else{
			if(!operators.empty() && operators.top() == ' '){
				operators.pop();
				int c = numbers.top();
				numbers.pop();
				numbers.push(b * 10 + c);
				numbers.push(a);
				operators.push(op);
			}
			else{
				if(op == '+'){
					numbers.push(a + b);
				}
				else if(op == '-'){
					numbers.push(a - b);
				}
			}
		}
	}

	return (numbers.top() == 0);
}

void print(vector<char> algorithm){
	for(int i = 0; i < N - 1; i++){
		fout << i + 1 << algorithm[i];
	}

	fout << N << endl;

}

void helper(vector<char> algorithm){
	if((int) algorithm.size() == N - 1){

		if(equalZero(algorithm)){
			print(algorithm);
		}

		return;
	}

	for(int i = 0; i < 3; i++){
		algorithm.push_back(methods[i]);
		helper(algorithm);
		algorithm.pop_back();
	}
}

int main() {
	vector<char> algorithm;
	fin >> N;

	helper(algorithm);
	return 0;
}
