/**
 * @file Bogdanov_515i_2021.c
 * @author Богданов М. Е., гр. 515и
 * @date 2 июля 2021
 * @brief практика
*/

#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

int main() {
	setlocale(LC_CTYPE, "rus");

	struct {
		float x, y;
	} ax, * pt, rs;
	float angle;
	int pointNum;
	_Bool valid;

	do {
		printf("Введите количество точек (>0): ");
		valid = scanf_s("%d", &pointNum);
		while (fgetc(stdin) != '\n');
	} while (!valid || pointNum <= 0);
	pt = calloc(pointNum, sizeof(*pt));
	if (pt == NULL) {
		return 3;
	}

	for (unsigned i = 0; i < pointNum; i++) {
		do {
			printf("Введите точку [%d] (x y): ", i + 1);
			valid = scanf_s("%f %f", &((pt + i)->x), &((pt + i)->y));
			while (fgetc(stdin) != '\n');
		} while (!valid);
	}
	
	do {
		printf("Введите ось поворота (x y): ");
		valid = scanf_s("%f %f", &ax.x, &ax.y);
		while (fgetc(stdin) != '\n');
	} while (!valid);

	do {
		printf("Введите угол поворота: ");
		valid = scanf_s("%f", &angle);
		while (fgetc(stdin) != '\n');
	} while (!valid);

	printf("\n");
	for (unsigned i = 0; i < pointNum; i++) {
		rs.x = ax.x + cos(M_PI / 180 * angle) * ((pt + i)->x - ax.x) - sin(M_PI / 180 * angle) * ((pt + i)->y - ax.y);
		rs.y = ax.y + sin(M_PI / 180 * angle) * ((pt + i)->x - ax.x) + cos(M_PI / 180 * angle) * ((pt + i)->y - ax.y);
		printf("Точка [%d]:\tx = %lg\ty = %lg\n", i, floor(rs.x * 100) / 100, floor(rs.y * 100) / 100);
	}

	free(pt);
	return 0;
}