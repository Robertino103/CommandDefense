#include "Canvas.h"

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;

	m = new char* [width];
	for (int i = 0; i < width; i++)
	{
		m[i] = new char[height];
	}

	Clear();
}

void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			m[i][j] = ' ';
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			std::cout << m[i][j];
		}
		std::cout << std::endl;
	}
}

bool isPossible(int x, int y, int ray,int width, int height)
{
	if (x + ray < width && y + ray < height && x - ray>0 && y - ray>0) return true;
	return false;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	bool ok = isPossible(x, y, ray, width, height);
	if (ok == false) {
		std::cout << "Valori eronate pentru DrawCircle()" << std::endl;
		exit(1);
	}

	for (int i = x-ray; i <= x+ray; i++)
	{
		int max = 0, storedj = 0, poz;
		for (int j = y-ray; j <= y+ray; j++)
		{
			poz = (i - x) * (i - x) + (j - y) * (j - y);
			if (poz >= max && poz <= ray * ray)
			{
				max = poz;
				storedj = j;
			}
		}
		SetPoint(i, storedj, ch);
	}

	for (int i = x - ray; i <= x + ray; i++)
	{
		int min = 1000, storedj = 0, poz;
		for (int j = y - ray; j <= y + ray; j++)
		{
			poz = (i - x) * (i - x) + (j - y) * (j - y);
			if (j <= min && poz <= ray * ray)
			{
				min = j;
			}
		}
		SetPoint(i, min, ch);
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	bool ok = isPossible(x, y, ray, width, height);
	if (ok == false) {
		std::cout << "Valori eronate pentru FillCircle()" << std::endl;
		exit(2);
	}

	for (int i = x - ray; i <= x + ray; i++)
	{
		for (int j = y - ray; j <= y + ray; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				SetPoint(i, j, ch);
			}
		}
	}
}

void Braseham(char** m, int x1, int y1, int x2, int y2, int dx, int dy, int decide, char ch)
{
	int pk = 2 * dy - dx;
	for (int i = 0; i <= dx; i++)
	{
		x1 < x2 ? x1++ : x1--;

		if (pk < 0)
		{
			if (decide == 0)
			{
				m[x1][y1] = ch;
				pk = pk + 2 * dy;
			}
			else
			{
				m[y1][x1] = ch;
				pk = pk + 2 * dy;
			}
		}
		else
		{
			y1 < y2 ? y1++ : y1--;

			if (decide == 0)
			{
				m[x1][y1] = ch;
			}
			else
			{
				m[y1][x1] = ch;
			}
			pk = pk + 2 * dy - 2 * dx;
		}
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	if (dx > dy)
	{
		Braseham(m, x1, y1, x2, y2, dx, dy, 0, ch);
	}
	else
	{
		Braseham(m, y1, x1, y2, x2, dy, dx, 1, ch);
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	Canvas::DrawLine(top, left, bottom, left, ch);
	Canvas::DrawLine(bottom, left, bottom, right, ch);
	Canvas::DrawLine(top, right, bottom, right, ch);
	Canvas::DrawLine(top, left, top, right, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
	{
		for (int j = left; j <= right; j++)
		{
			SetPoint(i, j, ch);
		}
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	m[x][y] = ch;
}