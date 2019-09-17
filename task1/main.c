#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char first_name[] = "Lyubov", middle_name[] = "Mikhailovna", last_name[] = "Miloserdova";
    int n = strlen(first_name) * strlen(middle_name) * strlen(last_name); // искомое произведение

    int bin_int[32]; // двоичное представление отрицательного 32-битного целого, модуль которого равен найденному произведению
    for (int i = 0; i < 32; i++) {
		bin_int[i] = 1;
	}
	int m = n, k = 31, z = 31;
	while (m > 0) {
		bin_int[k] = (m % 2 + 1) % 2;
		if (bin_int[k] == 0)
			z = k; // ищем самый левый ноль *на будущее*
		k--;
		m /= 2;
	}
	for (int i = 0; i < 32; i++) {
		printf("%d", bin_int[i]);
	}
	printf("\n");

	int bin_float[32]; // двоичное представление положительного числа с плавающей запятой единичной точности по стандарту IEEE 754, модуль которого равен найденному произведению
	for (int i = 0; i < 32; i++) {
		bin_float[i] = 0;
	}
	int j = 8;
	m = 31 - (k + 1) + 127;
	while (m) {
		bin_float[j] = m % 2;
		j--;
		m /= 2;
	}
	for (int i = 9; z + i - 8 < 32; i++) {
		bin_float[i] = (bin_int[z + i - 8] + 1) % 2; // вот оно - будущее!
	}
	for (int i = 0; i < 32; i++) {
		printf("%d", bin_float[i]);
	}
	printf("\n");

	int bin_double[64]; // двоичное представление отрицательного числа с плавающей запятой двойной точности по стандарту IEEE 754, модуль которого равен найденному произведению
	bin_double[0] = 1;
	for (int i = 1; i < 64; i++) {
		bin_double[i] = 0;
	}
	j = 11;
	m = 31 - k + 1023;
	while (m) {
		bin_double[j] = m % 2;
		j--;
		m /= 2;
	}
	for (int i = 12; i - 3 < 32; i++) {
		bin_double[i] = bin_float[i - 3];
	}
	for (int i = 0; i < 64; i++) {
		printf("%d", bin_double[i]);
	}
	printf("\n");

    return 0;
}
