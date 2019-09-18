#include <stdio.h>

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
	unsigned int x = 2;

	for (int i = 1; i < 32; i++) {
		x = x << 1;
		if (isPrime(x - 1))
		{
			printf("Number %u is prime.\n", x - 1);
		}
	}
	return 0;
}