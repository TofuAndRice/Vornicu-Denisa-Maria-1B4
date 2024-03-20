#pragma once
class Sort
{
    int* v;
    int size;
public:
    Sort(int n, int minim, int maxim); //random values
    Sort(); //from initialization list
    Sort(int* v, int n); // from existing vector
    Sort(int n, ...); //variadic
    Sort(char* v);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent, int start, int end);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};