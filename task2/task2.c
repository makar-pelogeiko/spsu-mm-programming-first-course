#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
main()
{
	int a[3], k, i;
	for (i = 0; i < 3; i++) scanf_s("%d", &a[i]);
	for (i = 0; i < 2; i++)
	{
		for (int j = 0; j < (2 - i); j++)
		{
			if (a[j] > a[j + 1])
			{

				k = a[j];
				a[j] = a[j + 1];
				a[j + 1] = k;
			}
		}
	}
	if ((a[0] * a[0] + a[1] * a[1]) == (a[2] * a[2]))
	{


		while (a[0] != a[1] && (a[0] > 1) && (a[1] > 1))
		{

			if (a[1] > a[0]) a[1] = (a[1] % a[0]);
			else a[0] = (a[0] % a[1]);

		}
		if (a[0] == 1 || a[1] == 1) printf("Pythagorean, primitive");
		else printf("Pythagorean, not a primitive");
	}

	else printf("non-Pythagorean");

}
