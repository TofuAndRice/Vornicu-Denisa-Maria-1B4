#include "Sort.h"
#include <iostream>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void Sort::Print() {
	for (int i = 0; i < size; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

Sort::Sort(int n, int minim, int maxim) {
	srand(time(NULL));
	v = new int[n];
	size = n;
	int aux = (maxim - minim + 1);
	for (int i = 0; i < n; i++) {
		v[i] = rand() % aux + minim;
	}
}

Sort::Sort(): v(new int[5] {1, 2, 3, 4, 5}) { 
	size = 5;
}

Sort::Sort(int *a, int n) {
	v = a;
	size = n;
}

Sort::Sort(int n, ...) {
	v = new int[n];
	size = n;
	va_list l;
	va_start(l, n);
	for (int i = 0; i < n; i++) {
		v[i] = va_arg(l, int);
	}
	va_end(l);
}

Sort::Sort(char* b) {
	v = new int[20];
	char *next_token = nullptr;
	char *p = strtok_s(b, ",", &next_token);
	int i = 0;
	while (p) {
		v[i++] = atoi(p);
		p = strtok_s(NULL, ",", &next_token);
	}
	size = i;
}

void Sort::InsertSort(bool ascendent) {
	int i, key, j;
	for (i = 1; i < size; i++) {
		key = v[i];
		j = i - 1;
		while (j >= 0 && v[j] < key) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}


int partition(int*v, int start, int end){
	int pivot = v[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (v[i] >= pivot)
			count++;
	}
	int pivotIndex = start + count;
	swap(v[pivotIndex], v[start]);
	int i = start, j = end;
	while (i < pivotIndex && j > pivotIndex) {
		while (v[i] >= pivot) {
			i++;
		}
		while (v[j] < pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			swap(v[i++], v[j--]);
		}
	}
	return pivotIndex;
}

void Sort::QuickSort(bool ascendent, int start, int end){
	if (start >= end) return;
	int p = partition(v, start, end);
	QuickSort(ascendent, start, p - 1);
	QuickSort(ascendent, p + 1, end);
}

void Sort::BubbleSort(bool ascendent){
	int i, j;
	bool swapped;
	for (i = 0; i < size - 1; i++) {
		swapped = false;
		for (j = 0; j < size - i - 1; j++) {
			if (v[j] < v[j + 1]) {
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

int Sort::GetElementsCount() {
	return size;
}

int Sort::GetElementFromIndex(int index) {
	return v[index];
}
