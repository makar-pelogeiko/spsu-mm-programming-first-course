#include <stdio.h>

void bin(char* str, int value, int size)	//conversion to binary notation with writing to a string
{											//size - bit number
	str[abs(size)] = '\0';					//if size is positive, the least bit corresponds to the lowest index
	int i;									//if size is negative, the least bit corresponds to the largest index
	if (size > 0)							//str - result string
	{
		for (i = 0; (i < size) && value; i++)
		{
			if (value % 2)
			{
				str[i] = '1';
			}
			else
			{
				str[i] = '0';
			}
			value /= 2;
		}
		for (i; i < size; i++)
		{
			str[i] = '0';
		}
	}
	else
	{
		size = -size;
		for (i = size - 1; (i >= 0) && value; i--)
		{
			if (value % 2)
			{
				str[i] = '1';
			}
			else
			{
				str[i] = '0';
			}
			value /= 2;
		}
		for (i; i >= 0; i--)
		{
			str[i] = '0';
		}
	}
}

int dimension(int value)		//number of bits for conversion to binary
{
	int i;
	if (!value)		//for value == 0
	{
		value++;
	}
	for (i = 0; value; i++)
	{
		value /= 2;
	}
	return i;
}

int main()
{
	const char name[] = "Anton";
	const char surname[] = "Kazancev";
	const char patron[] = "Alexeyevich";

	int multiple = strlen(name) * strlen(surname) * strlen(patron);

	char bin_str[65];

	//return of negative 32 bit number

	int bit_count = 32;
	bin(bin_str, multiple, bit_count);

	printf("1");
	for (int i = bit_count - 2; i >= 0; i--)
	{
		if (bin_str[i] - '0')
		{

			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	printf("\n");

	int std_bin_count = dimension(multiple);

	// return of positive number in IEEE 754 binary32

	printf("0");
	bin(bin_str, std_bin_count + 126, -8);	//exhibitor
	for (int i = 0; i < 8; i++)
	{
		printf("%c", bin_str[i]);
	}

	bin(bin_str, multiple, -(std_bin_count - 1));	//mantissa
	for (int i = 0; i < std_bin_count - 2; i++)
	{
		printf("%c", bin_str[i]);
	}
	for (int i = 24 - std_bin_count; i >= 0; i--)
	{
		printf("0");
	}
	printf("\n");

	// return of negative number in IEEE 754 binary64

	printf("1");

	bin(bin_str, std_bin_count + 1022, -11);	//exhibitor
	for (int i = 0; i < 11; i++)
	{
		printf("%c", bin_str[i]);
	}

	bin(bin_str, multiple, -(std_bin_count - 1));	//mantissa
	for (int i = 0; i < std_bin_count - 2; i++)
	{
		printf("%c", bin_str[i]);
	}
	for (int i = 53 - std_bin_count; i >= 0; i--)
	{
		printf("0");
	}
	printf("\n");

	return 0;
}