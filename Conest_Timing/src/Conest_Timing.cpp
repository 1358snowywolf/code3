//============================================================================
// Name        : Conest_Timing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin ("ctiming.in");
	ofstream fout ("ctiming.out");
	int day,hours, minutes;
	int total = 0;

	fin >> day >> hours >> minutes;

	if(day < 11){
		fout << "-1" << endl;
		return 0;
	}
	if(day == 11 && hours < 11){
		fout << "-1" << endl;
		return 0;
	}
	if(day == 1 && hours == 11 && minutes < 11){
		fout << "-1" << endl;
		return 0;
	}

	total += ((day - 11) * 24 * 60);
	total += ((hours - 11) * 60);
	total += (minutes - 11);

	fout << total << endl;

	return 0;
}
