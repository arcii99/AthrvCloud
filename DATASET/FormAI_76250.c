//FormAI DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25

void printFractal(char fractal[HEIGHT][WIDTH]) {
    int i,j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }
}

void generateFractal(int depth, int left, int right, int top, int bottom, char fractal[HEIGHT][WIDTH]) {
    int i, j;

    if (depth == 0) return;

    for (i = top; i < bottom; i++) {
        for (j = left; j < right; j++) {
            if ((i == top) || (i == bottom-1) || (j == left) || (j == right-1)) {
                // Border
                fractal[i][j] = '*';
            }
        }
    }

    int m1 = (left + right) / 2;
    int m2 = (top + bottom) / 2;
    generateFractal(depth - 1, left, m1, top, m2, fractal);
    generateFractal(depth - 1, m1, right, top, m2, fractal);
    generateFractal(depth - 1, left, m1, m2, bottom, fractal);
    generateFractal(depth - 1, m1, right, m2, bottom, fractal);
}

int main(int argc, char** argv) {
    char fractal[HEIGHT][WIDTH];
    int i, j;

    // Initialize to spaces
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fractal[i][j] = ' ';
        }
    }

    generateFractal(7, 0, WIDTH, 0, HEIGHT, fractal);
    printFractal(fractal);
    return 0;
}