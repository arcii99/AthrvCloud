//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 50

char pixels[HEIGHT][WIDTH];

void generatePixels() {
    int i, j, k;

    // initialize all pixels to ' '
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pixels[i][j] = ' ';
        }
    }

    // add random pixels
    for (k = 0; k < 1000; k++) {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
        pixels[i][j] = 'X';
    }

    // add random lines
    for (k = 0; k < 10; k++) {
        int x1 = rand() % WIDTH;
        int y1 = rand() % HEIGHT;
        int x2 = rand() % WIDTH;
        int y2 = rand() % HEIGHT;

        int dx = x2 - x1;
        int dy = y2 - y1;

        int d = dx*dx + dy*dy;

        if (d == 0) {
            continue;
        }

        int steps = sqrt(d);
        int stepx = dx / steps;
        int stepy = dy / steps;

        for (i = 0; i < steps; i++) {
            int x = x1 + i*stepx;
            int y = y1 + i*stepy;

            pixels[y][x] = 'O';
        }
    }

    // add corners
    int cornerSize = 10;
    for (i = 0; i < cornerSize; i++) {
        for (j = 0; j < cornerSize; j++) {
            pixels[i][j] = '+';
            pixels[HEIGHT-i-1][j] = '+';
            pixels[i][WIDTH-j-1] = '+';
            pixels[HEIGHT-i-1][WIDTH-j-1] = '+';
        }
    }
}

void printPixels() {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            putchar(pixels[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    srand((unsigned) time(NULL));
    generatePixels();
    printPixels();

    return 0;
}