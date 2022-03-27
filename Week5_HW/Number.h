#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

class Number

{
	char* number_value;
	int number_base;

public:

	Number(const char* value, int base); // where base is between 2 and 16

	~Number();

	Number(const Number& n); // move constructor

	Number(const Number&& n); //copy constructor


	friend Number operator+ (const Number& n1, const Number& n2);
	friend Number operator- (const Number& n1, const Number& n2);
	bool operator> (Number& n);
	bool operator< (Number& n);
	bool operator>=(Number& n);
	bool operator<=(Number& n);

	void operator= (const char*);
	void operator= (const Number& n);
	void operator= (int n);


	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

	int  getBaseTen();

private:
	int switchbase10(char* s, int currentbase);
	char* convertbase(int n, int base);
	int normalizeDigit(char c);
	char formalizeDigit(int n);
};