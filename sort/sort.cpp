#include "sort.h"
#include <cstring>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <algorithm>
using namespace std;
void insertSort(int *array, int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		int temp = array[i];
		for (int j = i - 1; j >= left; j--)
		{
			if (array[j] > temp)
			{
				array[j + 1] = array[j];
				array[j] = temp;
			}
			else
			{
				break;
			}
		}
	}
}
int partition(int *array, int left, int right)
{
	int index = (left + right) / 2;
	int tmp = array[index];
	int l = left, r = right;
	array[index] = array[r];
	while (l < r)
	{
		while (l < r && array[l] < tmp)
		{
			l++;
		}
		if (l < r)
		{
			array[r] = array[l];
		}
		while (l <= r && array[r] > tmp)
		{
			r--;
		}
		if (l < r)
		{
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
void quickSortG(int *array, int left, int right)
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
void merge(int *array, int left, int right)
{
	int *tmp = new int[right - left + 2];
	int mid = (left + right) / 2;
	int l = left, r = mid + 1;
	int i = 0;
	while (l <= mid && r <= right)
	{
		if (array[l] <= array[r])
		{
			tmp[i++] = array[l++];
		}
		else
		{
			tmp[i++] = array[r++];
		}
	}
	while (l <= mid)
	{
		tmp[i++] = array[l++];
	}
	while (r <= right)
	{
		tmp[i++] = array[r++];
	}
	for (int j = 0; j < i; j++)
	{
		array[left + j] = tmp[j];
	}
	delete[] tmp;
}
void mergeSort(int *array, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	merge(array, left, right);
}

void bubbleSort(int *array, int left, int right)
{
	for (int i = left; i <= right; i++)
	{
		for (int j = left; j <= right - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{

				swap(array[j], array[j+1]);
			}
		}
	}
	return;
}
bool check(int *array_1, int* array_2, int* array_3, int* array_4, int n)
{

	int *tmp = new int[n];
	memcpy(tmp, array_1, sizeof(int) * n);
	sort(tmp, tmp + n);
	for (int i = 0; i < n; i++)
	{
		if (tmp[i] != array_1[i])
		{
			cout << "快排错误" << endl;
			return false;
		}
		if (tmp[i] != array_2[i])
		{
			cout << "改良快排错误" << endl;
			return false;
		}
		if (tmp[i] != array_3[i])
		{
			cout << "归并排序错误" << endl;
			return false;
		}
		if (tmp[i] != array_4[i])
		{
			cout << "冒泡排序错误" << endl;
			return false;
		}
	}
	return true;
}