//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define MAX_ITERATIONS 1000

bool isInsideMandelbrotSet(double a, double b) {
    double x = 0;
    double y = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        double x_new = x * x - y * y + a;
        double y_new = 2 * x * y + b;
        x = x_new;
        y = y_new;
        if (x * x + y * y > 4.0) {
            return false;
        }
    }
    return true;
}

void printFractal() {
    srand(time(NULL));
    for (int y = SCREEN_HEIGHT - 1; y >= 0; y--) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            double a = (x * 3.5 / SCREEN_WIDTH) - 2.5;
            double b = (y * 2.0 / SCREEN_HEIGHT) - 1.0;
            if (isInsideMandelbrotSet(a, b)) {
                printf("%c", (rand() % 10) + '0');
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printFractal();
    return 0;
}