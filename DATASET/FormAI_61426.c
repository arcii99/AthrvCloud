//FormAI DATASET v1.0 Category: Fractal Generation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000

float map(float value, float start1, float stop1, float start2, float stop2) {
	return start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
}

float complex transformCoordinates(int x, int y) {
	float real = map(x, 0, WIDTH, -2.0, 2.0);
	float imag = map(y, 0, HEIGHT, -2.0, 2.0);

	return real + imag * I;
}

int mandelbrot(int x, int y) {
	float complex c = transformCoordinates(x, y);
	float complex z = 0;

	for (int i = 0; i < MAX_ITERATIONS; i++) {
		z = z * z + c;

		if (creal(z) * creal(z) + cimag(z) * cimag(z) > 4) {
			return i;
		}
	}

	return MAX_ITERATIONS;
}

void drawFractal(int (*function)(int, int)) {
	FILE *fp;
	fp=fopen("fractal.ppm", "wb");
	fprintf(fp, "P6\n%d %d 255\n", WIDTH, HEIGHT);

	for(int y = 0; y < HEIGHT; y++) {
		for(int x = 0; x < WIDTH; x++) {
			int iter = function(x, y);
			unsigned char r = (unsigned char) map(iter, 0, MAX_ITERATIONS, 0, 255);
			unsigned char g = (unsigned char) map(iter, 0, MAX_ITERATIONS, 0, 255);
			unsigned char b = (unsigned char) map(iter, 0, MAX_ITERATIONS, 0, 255);
			fwrite(&r, 1, 1, fp);
			fwrite(&g, 1, 1, fp);
			fwrite(&b, 1, 1, fp);
		}
	}

	fclose(fp);
}

int main() {
	drawFractal(mandelbrot);

	return 0;
}