#define _CRT_SECURE_NO_DEPRECATE
#include "Week1Header.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

#define Max_Chars_Count 200

int Sum(int a, int b) { return a + b; }
int Dif(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

void ParseSources()
{
	char input[38] = "---H***E+++L+++L///O---P+++O/+-**O---";
	func Operatori[4] = {Sum, Dif, Mul, Div};
	int S=0, V;
	Content x;
	x.p1 = 0;
	x.p2 = 0;
	int idx;
	int i;
	for (i = 0; i < strlen(input); i++)
	{
		switch (input[i] - 42)
		{
			case INMULTIRE:
				idx = 2;
				x.p1 = 3;
				x.p2 = 3;
				break;
			case SUMA:
				idx = 0;
				x.p1 = 7;
				x.p2 = 5;
				break;
			case DIFERENTA:
				idx = 1;
				x.p1 = 10;
				x.p2 = 1;
				break;
			case IMPARTIRE:
				idx = 3;
				x.p1 = 8;
				x.p2 = 4;
				break;
		}

		S = S + Operatori[idx](x.p1, x.p2);
	}

	//S=337
	printf("S = %d\n", S);
}

// Week 1 - using C API
void ReadTopScore()
{

	FILE* fptr;
	fptr = fopen("UserScores.txt", "r");
	if (!fptr)
	{
		perror("Fisier gol");
	}
	int i, j, maxpoints = 0;
	char line[Max_Chars_Count];
	char numemax[Max_Chars_Count];
	while (!feof(fptr))
	{
		fgets(line, Max_Chars_Count, fptr);
		for (i = 0; i < strlen(line); i++)
		{
			if (line[i] >= 48 && line[i] <= 57) break;
		}
		for (j = i; j < strlen(line); j++)
		{
			if (!(line[j] >= 48 && line[j] <= 57)) break;
		}
		int points = 0;
		for (int k = j - 1; k >= i; k--)
		{
			points = points * 10 + line[k];
		}
		if (points > maxpoints) {
			strncpy(numemax, line, i - 1);
			maxpoints = points;
			numemax[i] = '\0';
		}
	}
	printf(numemax);
	fclose(fptr);
}