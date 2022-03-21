#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <ctime>
#include <cstdlib>
#include <cstdarg>
#include <string.h>

int char_to_int(char* s)
{
	if (s == nullptr) return 0;
	int res = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

Sort::Sort(int n, int minim, int maxim)
{
	this->NumberOfElements = n;
	srand(time(NULL));
	vector = new int[NumberOfElements];
	for (int i = 0; i < NumberOfElements; i++)
	{
		int random = rand() % (maxim - minim + 1) + minim;
		vector[i] = random;
	}
}

Sort::Sort(int n, int* vector)
{
	this->NumberOfElements = NumberOfElements;
	this->vector = new int[NumberOfElements];
	for (int i = 0; i < NumberOfElements; i++)
	{
		this->vector[i] = vector[i];
	}

}

Sort::Sort(int v[100], const int n)
{
	this->NumberOfElements = n;
	vector = new int[NumberOfElements];
	for (int i = 0; i < NumberOfElements; i++)
	{
		vector[i] = v[i];
	}
}

Sort::Sort(int n, ...)
{
	this->NumberOfElements = n;
	vector = new int[NumberOfElements];
	va_list arg;
	va_start(arg, n);
	for (int i = 0; i < NumberOfElements; i++)
	{
		this->vector[i] = va_arg(arg, int);
	}
	va_end(arg);
}

Sort::Sort(char* s)
{
	int nr = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ';') nr++;
	}
	this->NumberOfElements = nr + 1;
	vector = new int[NumberOfElements];
	char* numar;
	char s2[500];
	strcpy(s2, s);
	numar = strtok(s2, ";");
	int i = 0;
	while (numar != NULL)
	{
		this->vector[i] = char_to_int(numar);
		i++;
		numar = strtok(NULL, ";");
	}
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < NumberOfElements - 1; i++)
	{
		for (int j = i + 1; j < NumberOfElements; j++)
		{
			if (vector[i] > vector[j]) swap(vector[i], vector[j]);
		}
	}
}

void Sort::InsertSort(bool ascendent)
{
	int i, j, key;
	for (i = 1; i < NumberOfElements; i++)
	{
		key = vector[i];
		j = i - 1;
		while (j >= 0 && vector[j] > key)
		{
			vector[j + 1] = vector[j];
			j--;
		}
		vector[j + 1] = key;
	}
}

int partition(int arr[], int p, int q)
{
	int pivot = arr[q];
	int i = p - 1;
	for (int j = p; j <= q - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[q]);
	return (i + 1);
}

void quicksort_alg(int arr[], int p, int q)
{
	if (p < q)
	{
		int index = partition(arr, p, q);
		quicksort_alg(arr, p, index - 1);
		quicksort_alg(arr, index + 1, q);
	}
}

void Sort::QuickSort(bool ascendent)
{
	int p = 0;
	int q = this->NumberOfElements - 1;
	quicksort_alg(this->vector, p, q);
}


void Sort::Print()
{
	for (int i = 0; i < NumberOfElements; ++i)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

int Sort::GetElementsCount()
{
	return (this->NumberOfElements);
}

int Sort::GetElementFromIndex(int index)
{
	return (this->vector[index]);
}


