//FormAI DATASET v1.0 Category: Fractal Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 70      // height of the fractal
#define WIDTH 100       // width of the fractal
#define MAX_DEPTH 10    // maximum depth of recursion

char fractal[HEIGHT][WIDTH + 1];

// initialize the fractal to all spaces
void initializeFractal() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fractal[i][j] = ' ';
        }
        fractal[i][WIDTH] = '\0';
    }
}

// print the fractal to the console
void printFractal() {
    int i;
    for (i = 0; i < HEIGHT; i++) {
        printf("%s\n", fractal[i]);
    }
}

// recursive function to generate the fractal
void generateFractal(int depth, int x1, int y1, int x2, int y2) {
    if (depth == 0) {
        return;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    int x3 = x2 - dy;
    int y3 = y2 + dx;
    int x4 = x1 - dy;
    int y4 = y1 + dx;
    int x5 = (x1 + x2) / 2 + dy/2;
    int y5 = (y1 + y2) / 2 - dx/2;

    generateFractal(depth-1, x1, y1, x4, y4);
    generateFractal(depth-1, x4, y4, x3, y3);
    generateFractal(depth-1, x3, y3, x2, y2);
    generateFractal(depth-1, x5, y5, x4, y4);
    generateFractal(depth-1, x5, y5, x3, y3);
}

int main() {
    srand(time(NULL));

    initializeFractal();

    int x1 = rand() % WIDTH, y1 = rand() % HEIGHT;
    int x2 = rand() % WIDTH, y2 = rand() % HEIGHT;

    generateFractal(MAX_DEPTH, x1, y1, x2, y2);

    printFractal();

    return 0;
}