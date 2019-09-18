#include <stdio.h>

void bin(char* str, int value, int size)	//conversion to binary notation with writing to a string
{											//size - bit number
	str[abs(size)] = '\0';					//if size is positive, the least bit corresponds to the lowest index
	int i;									//if size is negative, the least bit corresponds to the largest index
	if (size > 0)							//str - result string
	{
		for (i = 0; (i < size) && value; i++)
		{
			str[i] = value % 2 + '0';
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
			str[i] = value % 2 + '0';
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
	if (!value)
		value++;
	for (i = 0; value; i++)
		value /= 2;
	return i;
}

int main()
{
	const char name[] = "Anton";
	const char surname[] = "Kazancev";
	const char patron[] = "Alexeyevich";

	int multiple = strlen(name) * strlen(surname) * strlen(patron);

	//return of negative 32 bit number

	char bit32[33];
	bin(bit32, multiple - 1, -32);

	bit32[0] = '1';
	for (int i = 1; i < 32; i++)
		bit32[i] = !(bit32[i] - '0') + '0';

	printf("%s\n", bit32);		//in bit32 we have (-1) * multiple in binary represented in string,
								//the least bit corresponds to the largest index for easy printf


	int std_bin_count = dimension(multiple);
	char mantissa[65];
	bin(mantissa, multiple, 1 - std_bin_count);
	int size;

	// return of positive number in IEEE 754 binary32

	char IEEE754bin32[33];
	IEEE754bin32[32] = '\0';
	bin(IEEE754bin32, std_bin_count + 126, -9);	
	for (int i = 9; i < 8 + std_bin_count; i++)
		IEEE754bin32[i] = mantissa[i - 9];
	for (int i = 8 + std_bin_count; i < 32; i++)
		IEEE754bin32[i] = '0';

	printf("%s\n", IEEE754bin32);	//in IEEE754bin32 we have multiple in IEEE 754 binary 32
									//the least bit corresponds to the largest index for easy printf

	// return of negative number in IEEE 754 binary64

	char IEEE754bin64[65];
	IEEE754bin64[64] = '\0';
	bin(IEEE754bin64, std_bin_count + 1023, -12);
	IEEE754bin64[0] = '1';
	for (int i = 12; i < 11 + std_bin_count; i++)
		IEEE754bin64[i] = mantissa[i - 12];
	for (int i = 11 + std_bin_count; i < 64; i++)
		IEEE754bin64[i] = '0';

	printf("%s\n", IEEE754bin64);	//in IEEE754bin64 we have multiple in IEEE 754 binary 64
									//the least bit corresponds to the largest index for easy printf

	return 0;
}
