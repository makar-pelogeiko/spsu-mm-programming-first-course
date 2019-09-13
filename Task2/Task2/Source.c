#include <stdio.h>
#include <locale.h>
#define swap(x, y) x = x + y; y = x - y; x = x - y;	

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int gcd(int a, int b)
{
	if (!b)
		return abs(a);
	gcd(b, a % b);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);

	if (min(x, y) == y)
	{
		swap(x, y);
	}
	if (min(x, z) == z)
	{
		swap(x, z);
	}
	if (min(y, z) == z)
	{
		swap(y, z);
	}

	if (x * x + y * y == z * z)
	{
		if (gcd(gcd(x, y), z) == 1)
		{
			printf("Тройка чисел является примитивной Пифагоровой тройкой.");
		}
		else
		{
			printf("Тройка чисел является Пифагоровой тройкой, но не примитивной Пифагоровой тройкой.");
		}
	}
	else
	{
		printf("Тройка чисел не является Пифагоровой тройкой.");
	}

	return 0;
}