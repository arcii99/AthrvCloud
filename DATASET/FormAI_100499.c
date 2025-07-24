//FormAI DATASET v1.0 Category: Fractal Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define SCALE 0.003
#define PERTURB 0.3

int x = 0, y = 0;
double lastValue = 0;
double fractal[WIDTH][HEIGHT];

double perturb(double value) {
    double perturbation = (double)rand() / RAND_MAX * 2.0 - 1.0;
    return value + perturbation * PERTURB;
}

void diamond(int x1, int y1, int x2, int y2) {
    int centerX = (x1 + x2) / 2;
    int centerY = (y1 + y2) / 2;

    double avg = (fractal[x1][y1] + fractal[x2][y1] + fractal[x1][y2] + fractal[x2][y2]) / 4.0;
    double value = perturb(avg);

    fractal[centerX][centerY] = value;

    if (x2 - x1 > 1) {
        square(x1, y1, centerX, centerY);
        square(centerX, y1, x2, centerY);
        square(x1, centerY, centerX, y2);
        square(centerX, centerY, x2, y2);
    }
}

void square(int x1, int y1, int x2, int y2) {
    int centerX = (x1 + x2) / 2;
    int centerY = (y1 + y2) / 2;

    if (fractal[centerX][centerY] == 0.0) {
        double sum = 0.0;
        int count = 0;

        if (x1 > 0) {
            sum += fractal[x1-1][centerY];
            count++;
        }

        if (y1 > 0) {
            sum += fractal[centerX][y1-1];
            count++;
        }

        if (x2 < WIDTH - 1) {
            sum += fractal[x2+1][centerY];
            count++;
        }
        
        if (y2 < HEIGHT - 1) {
            sum += fractal[centerX][y2+1];
            count++;
        }

        double avg = sum / count;
        double value = perturb(avg);
        fractal[centerX][centerY] = value;
    }

    if (x2 - x1 > 1) {
        diamond(x1, y1, centerX, centerY);
        diamond(centerX, y1, x2, centerY);
        diamond(x1, centerY, centerX, y2);
        diamond(centerX, centerY, x2, y2);
    }
}

double noise(double x, double y) {
    int xFloor = (int)floor(x / SCALE);
    int yFloor = (int)floor(y / SCALE);

    int x1 = xFloor;
    int x2 = xFloor + 1;
    int y1 = yFloor;
    int y2 = yFloor + 1;

    double xFrac = x / SCALE - xFloor;
    double yFrac = y / SCALE - yFloor;

    double value1 = fractal[x1][y1] * (1.0 - xFrac) + fractal[x2][y1] * xFrac;
    double value2 = fractal[x1][y2] * (1.0 - xFrac) + fractal[x2][y2] * xFrac;

    double value = value1 * (1.0 - yFrac) + value2 * yFrac;

    if (value != lastValue) {
        lastValue = value;
        int displayX = (int)((double)WIDTH * x / 3.0);
        int displayY = (int)((double)HEIGHT * y / 5.0);
        printf("\e[%d;%dH*", displayY, displayX);
    }

    return value;
}

int main() {
    int i, j;
    srand(1234567);

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            fractal[i][j] = 0.0;
        }
    }

    fractal[0][0] = perturb(0.5);
    fractal[0][HEIGHT-1] = perturb(0.5);
    fractal[WIDTH-1][0] = perturb(0.5);
    fractal[WIDTH-1][HEIGHT-1] = perturb(0.5);

    square(0, 0, WIDTH-1, HEIGHT-1);

    for (i = 0; i < 300; i++) {
        double x = (double)(rand()) / RAND_MAX * 3.0;
        double y = (double)(rand()) / RAND_MAX * 5.0;
        noise(x, y);
    }

    printf("\e[%d;%dH\n", HEIGHT, 0); // Move cursor to bottom of screen
    return 0;
}