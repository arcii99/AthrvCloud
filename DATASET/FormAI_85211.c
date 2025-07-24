//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 40

void printFractal(char *screen) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", screen[i * WIDTH + j]);
        }
        printf("\n");
    }
}

void generateFractal(char *screen, int x, int y, int width, int height) {
    if (width <= 2 || height <= 2) return;

    int x1 = x + width / 3;
    int x2 = x + 2 * width / 3;
    int y1 = y + height / 3;
    int y2 = y + 2 * height / 3;

    // Draw horizontal lines
    for (int i = x + 1; i < x + width - 1; i++) {
        screen[y1 * WIDTH + i] = '-';
        screen[y2 * WIDTH + i] = '-';
    }

    // Draw vertical lines
    for (int i = y + 1; i < y + height - 1; i++) {
        screen[i * WIDTH + x1] = '|';
        screen[i * WIDTH + x2] = '|';
    }

    generateFractal(screen, x, y, width / 3, height / 3);
    generateFractal(screen, x1, y, width / 3, height / 3);
    generateFractal(screen, x2, y, width / 3, height / 3);
    generateFractal(screen, x, y1, width / 3, height / 3);
    generateFractal(screen, x2, y1, width / 3, height / 3);
    generateFractal(screen, x, y2, width / 3, height / 3);
    generateFractal(screen, x1, y2, width / 3, height / 3);
    generateFractal(screen, x2, y2, width / 3, height / 3);
}

int main() {
    char screen[WIDTH * HEIGHT];
    // Initialize the screen with spaces
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        screen[i] = ' ';
    }

    // Generate the fractal
    generateFractal(screen, 0, 0, WIDTH, HEIGHT);

    // Print the fractal
    printFractal(screen);

    return 0;
}