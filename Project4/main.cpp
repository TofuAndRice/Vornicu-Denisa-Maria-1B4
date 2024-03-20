#include "Sort.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	Sort x1(5, 1, 5);
	Sort x2;
	int* a = new int[5] { 6, 3, 5, 0, 12 };
	Sort x3(a, 5);
	Sort x4(5, 1, 2, 3, 4, 5);
	//char* b =new char[15]{"10,11,12,13,14"};
	char* b = new char[15];
	strcpy_s(b, 15, "16,10,23,3,0");
	Sort x5(b);

	x1.Print();
	x2.Print();
	x3.Print();
	x4.Print();
	x5.Print();
	cout << endl;
	x1.InsertSort();
	cout << "InsertSort: ";
	x1.Print();

	bool ascendent = false;
	x3.QuickSort(ascendent , 0, x3.GetElementsCount() - 1);
	cout << "QuickSort: ";
	x3.Print();

	x5.BubbleSort();
	cout << "BubbleSort: ";
	x5.Print();

	int q = 2;
	cout << endl << "x5 : The element from index " << q <<" is "<< x5.GetElementFromIndex(q) << endl;

	return 0;
}