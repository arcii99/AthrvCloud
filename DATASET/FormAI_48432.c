//FormAI DATASET v1.0 Category: Fractal Generation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 100
#define HEIGHT 50

int iterations(int x, int y) {
    double complex C = ((double) x - WIDTH / 2) / (WIDTH / 4.0) + ((double) y - HEIGHT / 2) / (HEIGHT / 4.0) * I;
    double complex Z = 0;
    int i = 0;
    while (i < 1000) {
        Z = Z * Z + C;
        if (cabs(Z) > 2) break;
        i++;
    }
    return i;
}

void print_fractal(int array[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (array[x][y] > 10) printf("*");
            else if (array[x][y] > 5) printf(".");
            else printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int array[WIDTH][HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            array[x][y] = iterations(x, y);
        }
    }
    print_fractal(array);
    return 0;
}