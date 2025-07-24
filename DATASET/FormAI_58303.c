//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define WIDTH 160
#define HEIGHT 80

void printFractal(char fractal[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }
}

double complex calculate(int x, int y, double scale) {
    double complex z = ((double)x - WIDTH / 2.0) / (0.5 * scale * WIDTH) +
                       ((double)y - HEIGHT / 2.0) / (0.5 * scale * HEIGHT) * I;
    return z;
}

char color(double complex c) {
    double complex z = 0 + 0*I;
    int i;
    for(i = 0; i < 100; i++) {
        z = z*z + c;
        if(cabs(z) > 2) break;
    }
    if(i == 100) return '@';
    else return ' ';
}

int main() {
    char fractal[HEIGHT][WIDTH];
    double scale = 1.0;
    for(int i = 0; i <= HEIGHT; i++) {
        for(int j = 0; j <= WIDTH; j++) {
            fractal[i][j] = color(calculate(j, i, scale));
        }
    }
    printFractal(fractal);
    return 0;
}