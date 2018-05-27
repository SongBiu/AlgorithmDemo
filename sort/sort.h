#ifndef SORT_H
#define SORT_H
#include <vector>
extern void quickSort(int* array, int left, int right);
extern void quickSortG(int* array, int left, int right);
extern bool check(int* array_1, int* array_2, int* array_3, int* array_4, int n);
extern void mergeSort(int* array, int left, int right);
extern void bubbleSort(int* array, int left, int right);
extern void insertSort(int* array, int left, int right);
#endif