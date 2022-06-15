#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int func(int* N, int* M, int k) {

	int Sum, s, i, j, l;
	int** arr = new int* [k]; 
	for (i = 0; i < k; i++) {
		arr[i] = new int[k];
		arr[i][i] = 0;
	}
	for (i = 1; i < k; i++) {
		for (j = 0; j < k - i; j++) {
			s = 0;
			Sum = INT_MAX;
			for (l = 0; l < i; l++) {
				s = arr[j][j + l] + arr[j + l + 1][i + j] + N[j] * M[j + l] * M[i + j];
				if (s < Sum) Sum = s;
			}
			arr[j][j + i] = Sum; 
		}
	}
	return arr[0][k - 1];
}

int main() {
	int k = 0, m = 0, l = 0;
	fin >> k;

	int* N = new int[k];
	int* M = new int[k];
	for (int i = 0; i < k; i++) {
		fin >> N[i]  >> M[i];
	}
	fout << func(N, M, k);
}
