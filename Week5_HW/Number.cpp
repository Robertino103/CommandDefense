#include "Number.h"
using namespace std;

char* toString(long long n) {
	char* s = new char[50];
	int i = 0;

	bool b = false;
	if (n < 0) {
		n = -n;
		b = true;
	}

	while (n != 0) {
		int d = n % 10;

		s[i++] = '0' + d;

		n /= 10;
	}

	if (b) {
		s[i++] = '-';
	}

	s[i] = '\0';

	for (int l = 0; l < i / 2; l++) {
		char aux = s[l];
		s[l] = s[i - l - 1];
		s[i - l - 1] = aux;
	}

	return s;
}

Number::Number(const char* value, int base)
{
	this->number_value = new char[strlen(value)];
	memcpy(number_value, value, strlen(value) + 1);
	this->number_base = base;
}

Number::~Number()
{
}

Number::Number(const Number& n)
{
	this->number_base = n.number_base;
	this->number_value = n.number_value;
}

Number::Number(const Number&& n)
{
	this->number_base = n.number_base;
	this->number_value = n.number_value;
}

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

int Number::switchbase10(char* s, int currentbase)
{
	int len = strlen(this->number_value);
	int power = 1;
	int result_10 = 0;
	int i, num;
	for (i = len - 1; i >= 0; i--)
	{
		result_10 += val(number_value[i]) * power;
		power = power * number_base;
	}
	return result_10;
}

int Number::normalizeDigit(char c) {
	return c >= 'A' ? c - 'A' + 10 : c - '0';
}

char Number::formalizeDigit(int n) {
	return n >= 10 ? 'A' + (n - 10) : '0' + n;
}

char* Number::convertbase(int n, int base)
{
	char* c = new char[50];
	int i = 0;

	while (n != 0) {
		int d = n % base;
		c[i++] = formalizeDigit(d);

		n /= base;
	}
	c[i] = '\0';

	for (int l = 0; l < i / 2; l++) {
		char aux = c[l];
		c[l] = c[i - l - 1];
		c[i - l - 1] = aux;
	}

	return c;
}


void Number::SwitchBase(int newBase)
{
	long long n = switchbase10(number_value, number_base);
	char* newValue = convertbase(n, newBase);

	number_value = newValue;
	number_base = newBase;
}

void Number::Print()
{
	std::cout << this->number_value;
	std::cout << " --> In baza : ";
	std::cout << this->number_base;
}

int Number::GetDigitsCount()
{
	return strlen(this->number_value);
}

int Number::GetBase()
{
	return this->number_base;
}

int Number::getBaseTen() {
	int n = switchbase10(number_value, number_base);
	return n;
}

Number operator+(const Number& n1, const Number& n2)
{
	Number a = n1;
	Number b = n2;
	int base = a.GetBase() > b.GetBase() ? a.GetBase() : b.GetBase();


	int nr = a.getBaseTen() + b.getBaseTen();
	char* c = toString(nr);

	Number num(c, 10);
	num.SwitchBase(base);
	return num;
}

Number operator-(const Number& n1, const Number& n2)
{
	Number a = n1;
	Number b = n2;
	int base = a.GetBase() > b.GetBase() ? a.GetBase() : b.GetBase();


	int nr = a.getBaseTen() - b.getBaseTen();
	char* c = toString(nr);

	Number num(c, 10);
	num.SwitchBase(base);
	return num;
}

bool Number::operator>(Number& n)
{
	int n1 = this->getBaseTen();
	int n2 = n.getBaseTen();
	return n1 > n2;
}

bool Number::operator<(Number& n)
{
	int n1 = this->getBaseTen();
	int n2 = n.getBaseTen();
	return n1 < n2;
}

bool Number::operator>=(Number& n)
{
	int n1 = this->getBaseTen();
	int n2 = n.getBaseTen();
	return n1 >= n2;
}

bool Number::operator<=(Number& n)
{
	int n1 = this->getBaseTen();
	int n2 = n.getBaseTen();
	return n1 <= n2;
}

void Number::operator=(int n) {
	Number nr(toString(n), 10);
	nr.SwitchBase(number_base);
	*this = nr;
}

void Number::operator=(const char* s) {
	Number nr(s, 10);
	*this = nr;
}

void Number::operator=(const Number& n) {
	number_base = n.number_base;
	number_value = n.number_value;
}
