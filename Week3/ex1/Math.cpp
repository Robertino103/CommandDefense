#include "Math.h"
#include <iostream>
#include <stdarg.h>
#include <string.h>

#pragma warning(disable:4996)

int Math::Add(const int x1,const int x2)
{
	return x1 + x2;
}
int Math::Add(const int x1, const int x2, const int x3)
{
	return x1 + x2 + x3;
}
double Math::Add(const double x1, const double x2)
{
	return x1 + x2;
}
double Math::Add(const double x1, const double x2, const double x3)
{
	return x1 + x2 + x3;
}
int Math::Mul(const int x1, const int x2)
{
	return x1 * x2;
}
int Math::Mul(const int x1, const int x2, const int x3)
{
	return x1 * x2 * x3;
}
double Math::Mul(const double x1, const double x2)
{
	return x1 * x2;
}
double Math::Mul(const double x1, const double x2, const double x3)
{
	return x1 * x2 * x3;
}

int Math::Add(int count, ...)
{
	va_list list;
	va_start(list, count);
	int x, sum = 0;
	for (int i = 0; i < count; i++)
	{
		x = va_arg(list, int);
		sum += x;
	}
	va_end(list);
	return sum;
}

char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr) return nullptr;
	if (b == nullptr) return nullptr;
	
	char* buffer = new char[strlen(a) + strlen(b) + 1];
	strcpy(buffer, a);
	strcpy(buffer + strlen(a), b);
	buffer[strlen(a) + strlen(b) + 1] = '\0';
	
	return buffer;
}