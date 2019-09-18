#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define swap(x, y) {x = x + y; y = x - y; x = x - y;}


int gcd(int a, int b)
{
	if (!b)
		return abs(a);
	gcd(b, a % b);
}

int check(char* s)
{
	int spaces = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (((int)s[i] < 48 || (int)s[i] > 57) && s[i] != ' ')
			return 0;
		if (s[i] == ' ')
			spaces++;
	}
	if (spaces != 2)
		return 0;
	return 1;
}

int* solve(int* a, char* s)
{
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		char temp[20];
		for (int k = 0; k < 20; k++)
			temp[k] = '\0';
		int f = 0;
		while (s[j] != ' ' && s[j] != '\0')
		{
			temp[f] = s[j];
			j++;
			f++;
		}
		a[i] = strToInt(temp);
		j++;
	}
}

int strToInt(char* s)
{
	int ans = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		ans = ans * 10 + ((int)s[i] - (int)'0');
		i++;
	}
	return ans;
}


int main()
{
	char*line[40];
	gets(line);
	int flag = check(line);
	while (flag != 1)
	{
		printf("Invalid input. Try again.\n");
		gets(line);
		flag = check(line);
	}

	int a[3];
	solve(a, line);
	
	int x = a[0], y = a[1], z = a[2];

	if (min(x, y) == y)
		swap(x, y);
	
	if (min(x, z) == z)
		swap(x, z);
	
	if (min(y, z) == z)
		swap(y, z);

	if (x * x + y * y == z * z)
	{
		if (gcd(gcd(x, y), z) == 1 || (x == 0 && y == 0 && z == 0))
			printf("The triple of numbers is a primitive Pythagorean triple.");
		else
			printf("The triple of numbers is the Pythagorean triple, but not the primitive Pythagorean triple.");
	}
	else
		printf("The triple of numbers is not the Pythagorean triple.");

	return 0;
}