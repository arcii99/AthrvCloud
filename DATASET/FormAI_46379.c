//FormAI DATASET v1.0 Category: Fractal Generation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 500
#define SCALE_FACTOR 0.5
#define SEED 1234

void drawFractal(int x, int y, double width, double height, int iterations, int pixels[][HEIGHT]);
double getRandomNumber();

int main(void) {
    int pixels[WIDTH][HEIGHT];
    int x, y;

    srand(SEED);

    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            pixels[x][y] = 0;
        }
    }

    drawFractal(0, 0, WIDTH, HEIGHT, MAX_ITERATIONS, pixels);

    printf("P2\n");
    printf("%d %d\n", WIDTH, HEIGHT);
    printf("255\n");

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%d ", pixels[x][y]);
        }
        printf("\n");
    }

    return 0;
}

void drawFractal(int x, int y, double width, double height, int iterations, int pixels[][HEIGHT]) {
    if (iterations == 0) {
        return;
    }

    double halfWidth = width / 2.0;
    double halfHeight = height / 2.0;

    double centerX = x + halfWidth;
    double centerY = y + halfHeight;

    double topLeftX = x;
    double topLeftY = y;
    double topRightX = x + width;
    double topRightY = y;
    double bottomLeftX = x;
    double bottomLeftY = y + height;
    double bottomRightX = x + width;
    double bottomRightY = y + height;

    double displacement = (halfWidth + halfHeight) * SCALE_FACTOR * getRandomNumber();
    double centerValue = (pixels[(int)centerX][(int)centerY] + pixels[(int)topLeftX][(int)topLeftY] +
                          pixels[(int)topRightX][(int)topRightY] + pixels[(int)bottomLeftX][(int)bottomLeftY] +
                          pixels[(int)bottomRightX][(int)bottomRightY]) / 5.0;
    double randomValue = centerValue + displacement;

    if (randomValue < 0) {
        randomValue = 0;
    }

    if (randomValue > 255) {
        randomValue = 255;
    }

    pixels[(int)centerX][(int)centerY] = (int)randomValue;

    drawFractal(x, y, halfWidth, halfHeight, iterations - 1, pixels);
    drawFractal(x + halfWidth, y, halfWidth, halfHeight, iterations - 1, pixels);
    drawFractal(x, y + halfHeight, halfWidth, halfHeight, iterations - 1, pixels);
    drawFractal(x + halfWidth, y + halfHeight, halfWidth, halfHeight, iterations - 1, pixels);
}

double getRandomNumber() {
    return ((double)rand() / (double)RAND_MAX) * 2.0 - 1.0;
}