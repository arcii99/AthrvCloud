//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 64
#define HEIGHT 32

void printFractal(char fractal[HEIGHT][WIDTH]);

int main(void) {
    char fractal[HEIGHT][WIDTH];
    int i, j, k;
    int x, y;
    int centerX, centerY;
    int radius;
    int color;

    // Initialize fractal
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fractal[i][j] = ' ';
        }
    }

    // Set up fractal parameters
    centerX = WIDTH / 2;
    centerY = HEIGHT / 2;
    radius = 15;
    color = 0x80;

    // Draw first circle
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            x = j - centerX;
            y = i - centerY;
            if ((x * x + y * y) <= radius * radius) {
                fractal[i][j] = color;
            }
        }
    }

    // Draw additional circles until no more space is left
    while (radius > 1) {
        radius = radius / 2;
        color = color + 0x10;
        for (i = centerY - radius; i <= centerY + radius; i += 2 * radius) {
            for (j = centerX - radius; j <= centerX + radius; j += 2 * radius) {
                for (k = 0; k < radius; k++) {
                    x = j + k;
                    y = i;
                    if ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)
                            && (fractal[y][x] == ' ')) {
                        fractal[y][x] = color;
                    }

                    x = j - k;
                    y = i;
                    if ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)
                            && (fractal[y][x] == ' ')) {
                        fractal[y][x] = color;
                    }

                    x = j;
                    y = i + k;
                    if ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)
                            && (fractal[y][x] == ' ')) {
                        fractal[y][x] = color;
                    }

                    x = j;
                    y = i - k;
                    if ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)
                            && (fractal[y][x] == ' ')) {
                        fractal[y][x] = color;
                    }
                }
            }
        }
    }

    // Print fractal to console
    printFractal(fractal);

    return 0;
}

void printFractal(char fractal[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", fractal[i][j] == ' ' ? '.' : fractal[i][j]);
        }
        printf("\n");
    }
}