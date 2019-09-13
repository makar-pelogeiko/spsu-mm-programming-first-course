#include <stdio.h>
#include <math.h>
#include <locale.h>

const float def = 57.2958;

float solve(float a, float b, float c)
{
	return (a * a + b * b - c * c) / (2 * a * b);
}

void radToAngle(float x)
{
	float now;
	now = acos(x) * def;
	double angle, minutes, seconds;

	modf(now, &angle);
	now = (now - angle) * 60;

	modf(now, &minutes);
	now = (now - minutes) * 60;

	modf(now, &seconds);
	printf("%f градусов\n%f минут\n%f секунд\n\n", angle, minutes, seconds);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	float side1, side2, side3;
	float angle1, angle2, angle3;

	scanf("%e%e%e", &side1, &side2, &side3);

	angle1 = solve(side2, side3, side1);
	angle2 = solve(side1, side3, side2);
	angle3 = solve(side1, side2, side3);

	printf("Угол 1\n");
	radToAngle(angle1);

	printf("Угол 2\n");
	radToAngle(angle2);

	printf("Угол 3\n");
	radToAngle(angle3);
	return 0;
}