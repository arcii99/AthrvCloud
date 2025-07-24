//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define WIDTH 70
#define HEIGHT 30
#define MAX_ITER 100

int fractal[HEIGHT][WIDTH];

void generateFractal() {
    int row, col, iter;
    double x, y, xTemp;

    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            x = ((double)col - WIDTH/2) * 4.0 / WIDTH;
            y = ((double)row - HEIGHT/2) * 4.0 / HEIGHT;

            int i = 0;
            while (x*x + y*y < 4 && i < MAX_ITER) {
                xTemp = x*x - y*y + 0.6;
                y = 2*x*y + 0.35;
                x = xTemp;
                i++;
            }

            fractal[row][col] = i;
        }
    }
}

void printFractal() {
    int row, col;
    char display[WIDTH+1];
    for (row = 0; row < HEIGHT; row++) {
        for (col = 0; col < WIDTH; col++) {
            char c;
            if (fractal[row][col] == MAX_ITER)
                c = ' ';
            else if (fractal[row][col] > MAX_ITER / 2)
                c = '.';
            else if (fractal[row][col] > MAX_ITER / 4)
                c = 'o';
            else
                c = '#';

            display[col] = c;
        }
        display[WIDTH] = '\0';
        printf("%s\n", display);
    }
}

int main() {
    generateFractal();
    printFractal();
    return 0;
}