#include <stdio.h>

void bin(char* str, int value, int size)	//переводит value в строку с его бинарным представлением
{											//size - количество бит
	str[abs(size)] = '\0';					//младшему индексу в строке соответствует младший бит, если size полож
	int i;									//младшему индексу в строке соответствует стфрший бит, если size отриц
	if (size > 0)							//str - строка в которую будет записан результат
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

int dimension(int value)		//выводит количество бит, необходимое дл€ записи числа
{
	int i;
	if (!value)		//дл€ value = 0
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
	const char name[] = "јнтон";
	const char surname[] = " азанцев";
	const char patron[] = "јлексеевич";

	int multiple = strlen(name) * strlen(surname) * strlen(patron);

	char bin_str[65];

	// вывод отрицательного 32 битного числа

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

	// вывод положительного представлени€ числа в IEEE 754 binary32

	printf("0");
	bin(bin_str, std_bin_count + 126, -8);	//вывод экспоненты
	for (int i = 0; i < 8; i++)
	{
		printf("%c", bin_str[i]);
	}

	bin(bin_str, multiple, -(std_bin_count - 1));	//вывод мантисы
	for (int i = 0; i < std_bin_count - 2; i++)
	{
		printf("%c", bin_str[i]);
	}
	for (int i = 24 - std_bin_count; i >= 0; i--)
	{
		printf("0");
	}
	printf("\n");

	// вывод отрицательного представлени€ числа в IEEE 754 binary64

	printf("1");

	bin(bin_str, std_bin_count + 1022, -11);	//вывод экспоненты двойной точности
	for (int i = 0; i < 11; i++)
	{
		printf("%c", bin_str[i]);
	}

	bin(bin_str, multiple, -(std_bin_count - 1));	//вывод мантисы
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