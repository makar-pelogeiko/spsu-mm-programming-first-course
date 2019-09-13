#include <stdio.h>
#include <locale.h>

int isPrime(unsigned int x)
{
	int d = 2;
	if (x % 2 == 0)
		return x == 2;
	d = 3;
	while (d * d <= x)
	{
		if (x % d == 0)
		{
			return 0;
		}
		d = d + 2;
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned int x = 1;

	for (int i = 0; i < 32; i++) {
		x = x << 1;
		if (isPrime(x - 1))
		{
			printf("Число %u - простое\n", x - 1);
		}
	}
	return 0;
}