#include "sort.h"
#include <cstring>
#include <iostream>
#include <time.h>
using namespace std;
void insertSort(int* array, int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		int temp = array[i];
		for (int j = i - 1; j >= left; j--)
		{
			if (array[j] > temp)
			{
				array[j+1] = array[j];
				array[j] = temp;
			}
			else
			{
				break;
			}
		}
	}
}
int partition(int* array, int left, int right)
{
	int index = (left+right) / 2;
	int tmp = array[index];
	int l = left, r = right;
	array[index] = array[r];
	while (l < r)
	{
		while (l < r && array[l] < tmp)
		{
			l++;
		}
		if (l < r) {
			array[r] = array[l];
		}
		while (l < r && array[r] > tmp)
		{
			r--;
		}
		if (l < r) {
			array[l] = array[r];
		}
	}
	array[l] = tmp;
	return l;
}
void quickSort(int *array, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int tmp = partition(array, left, right);
	quickSort(array, left, tmp);
	quickSort(array, tmp + 1, right);
}
#define THRESHOLD 28
void quickSortG(int* array, int left, int right)
{
	if (right - left > THRESHOLD)
	{
		int tmp = partition(array, left, right);
		quickSortG(array, left, tmp);
		quickSortG(array, tmp + 1, right);
	}
	else
	{
		insertSort(array, left, right);
	}
}
void quickSortT(int* array, int left, int right) {
	long start, stop;
	start = clock();
	quickSort(array, left, right);
	stop = clock();
	cout << "quickSort Use Time: " << (stop-start)*1.0*1000 << endl;
}
void quickSortGT(int* array, int left, int right) {
	time_t start, stop;
	start = clock();
	quickSortG(array, left, right);
	stop = clock();
	cout << "quickSortG Use Time: " << (stop-start)*1.0*1000 << endl;
}
// void merge(int *left, int *right)
// {
// 	int *tmp = new int[right - left + 1];
// 	int *mid = (int *)(left + (right - left) / 2);
// 	int *l = left, *r = right;
// 	while (l != mid && mid != right)
// 	{
// 		if (*l <= *r)
// 		{
// 			*(tmp++) = *(l++);
// 		}
// 		else
// 		{
// 			*(tmp++) = *(r++);
// 		}
// 	}
// 	while (l != mid)
// 	{
// 		*(tmp++) = *(l++);
// 	}
// 	while (r != right)
// 	{
// 		*(tmp++) = *(r++);
// 	}
// 	memcpy(left, tmp, sizeof(int) * (right - left + 1));
// 	delete[] tmp;
// }
// void mergeSort(int *left, int *right)
// {
// 	if (left >= right)
// 	{
// 		return;
// 	}
// 	int *mid = (int *)(left + (right - left) / 2);
// 	mergeSort(left, mid);
// 	mergeSort(right, mid + 1);
// 	merge(left, right);
// }