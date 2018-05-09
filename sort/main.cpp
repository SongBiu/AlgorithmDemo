#include <iostream>
#include <vector>
#include "sort.h"
#include <random>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;
int main(int argc, char** args) {
	int *vec1, *vec2;
	srand(time(NULL));
	int n = stoi(args[1]);
	vec1 = new int[n];
	vec2 = new int[n];
	for (int i = 0; i < n; i++) {
		int c = rand();
		vec1[i] = c;
		vec2[i] = c;
	}
	cout << "rand over!\n";
	quickSortT(vec1, 0, n-1);
	quickSortGT(vec2, 0, n-1);
	delete[] vec1;
	delete[] vec2;
	return 0;
}