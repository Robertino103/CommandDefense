#pragma once
#include <iostream>
using namespace std;

class Sort

{
    int NumberOfElements;
    int* vector;

public:

    Sort(int n, int minim, int maxim);

    Sort(int NumberOfElements, int *vector);

    Sort(int v[100], int);

    Sort(int n, ...);

    Sort(char* s);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int index);

};