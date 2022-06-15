#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <set>
#include <iterator>
#include <fstream>
#include <algorithm>


using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream out("output.txt");
	long long s = 0;
	set <long long> Su;
	for (long long i = 0; fin.good(); i++) {
		int a;
		fin >> a;
		Su.insert(a);
	}
    set<long long>::iterator it;
	for (it = Su.begin(); it != Su.end(); it++) {
		s += *it;
	}
    //cout << s;
	out << s;
	return 0;
}
