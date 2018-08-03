#include <iostream>
#include <vector>
#include "sort.h"
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
int main(int argc, char** argv)
{
	int test_number = atoi(argv[1]), n = atoi(argv[2]);
	double quickSort_time=0, quickSort_G_time=0, mergeSort_time=0, bubbleSort_time=0, insertSort_time=0;
	int *vec1 = new int [n], *vec2 = new int [n], *vec3 = new int [n], *vec4 = new int [n], *vec5 = new int[n];
	//下面是生成排序数组
	fstream fs;
	srand(time(NULL));
	fs.open("data", ios::out);
	for (int i = 0; i < 100; i++) {
		int len = n;
		for (int j = 0; j < len - 1; j++) {
			fs << rand() << ' ';
		}
		fs << rand() << endl;
	}
	fs.close();
	//进行排序
	cout << "write complete" << endl;
	fs.open("data", ios::in);
	string p;
	for (int j = 0; j < test_number; j++)
	{
		int i = 0;
		for (int k = 0; k < n; k++)
		{
			fs >> p;
			vec1[i] = stoi(p);
			vec2[i] = stoi(p);
			vec3[i] = stoi(p);
			vec4[i] = stoi(p);
			vec5[i] = stoi(p);
			i++;
		}
		
		clock_t start_time = clock();
		cout << "begin to quick sort" << endl;
		quickSort(vec1, 0, n - 1);
		quickSort_time += (clock()-start_time);
		
		start_time = clock();
		cout << "begin to quick sort boost" << endl;
		quickSortG(vec2, 0, n - 1);
		quickSort_G_time += (clock()-start_time);
		
		cout << "begin to merge sort" << endl;
		start_time = clock();
		mergeSort(vec3, 0, n - 1);
		mergeSort_time += (clock()-start_time);
		if (argc != 4) {
			start_time = clock();
			cout << "begin to bubble sort" << endl;
			bubbleSort(vec4, 0, n - 1);
			bubbleSort_time += (clock()-start_time);
		}
		
		
		start_time = clock();
		cout << "begin to insert sort" << endl;
		insertSort(vec5, 0, n - 1);
		insertSort_time += (clock()-start_time);
	}
	printf("快速排序耗时：%fs\n", quickSort_time/(test_number*CLOCKS_PER_SEC));
	printf("优化快速排序耗时：%fs\n", quickSort_G_time/(test_number*CLOCKS_PER_SEC));
	printf("归并排序耗时：%fs\n", mergeSort_time/(test_number*CLOCKS_PER_SEC));
	if (argc != 4) {
		printf("冒泡排序耗时：%fs\n", bubbleSort_time/(test_number*CLOCKS_PER_SEC));
	}
	printf("插入排序耗时：%fs\n", insertSort_time/(test_number*CLOCKS_PER_SEC));
	delete[] vec1;
	delete[] vec2;
	delete[] vec3;
	delete[] vec4;
	delete[] vec5;
	fs.close();
	return 0;
}