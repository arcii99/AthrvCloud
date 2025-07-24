//FormAI DATASET v1.0 Category: Fractal Generation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 100

int buffer[WIDTH][HEIGHT];

void generate_fractal(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int cx = x1 + dx / 2;
    int cy = y1 + dy / 2;

    if (dx == 0 && dy == 0) {
        buffer[cx][cy] = 255;
    } else {
        int i, j;
        double phi = (sqrt(5) + 1) / 2;

        int x[5] = {x1, cx, x2, cx, x1};
        int y[5] = {y1, cy, y2, cy, y1};

        for (i = 0; i < 4; i++) {
            int x3 = x[i] + (x[i+1] - x[i]) / 3;
            int y3 = y[i] + (y[i+1] - y[i]) / 3;
            int x4 = x[i] + (2 * (x[i+1] - x[i])) / 3;
            int y4 = y[i] + (2 * (y[i+1] - y[i])) / 3;
            int x5 = x3 + (x4 - x3) * cos(phi * M_PI / 180) - (y4 - y3) * sin(phi * M_PI / 180);
            int y5 = y3 + (x4 - x3) * sin(phi * M_PI / 180) + (y4 - y3) * cos(phi * M_PI / 180);

            generate_fractal(x[i], y[i], x3, y3);
            generate_fractal(x3, y3, x5, y5);
            generate_fractal(x5, y5, x4, y4);
            generate_fractal(x4, y4, x[i+1], y[i+1]);
        }
    }
}

int main() {
    int i, j;
    double min, max;

    generate_fractal(0, 0, WIDTH-1, HEIGHT-1);

    min = buffer[0][0];
    max = buffer[0][0];

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (min > buffer[i][j]) {
                min = buffer[i][j];
            }
            if (max < buffer[i][j]) {
                max = buffer[i][j];
            }
        }
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            double value = (buffer[i][j] - min) / (max - min) * 255;
            printf("%d ", (int)value);
        }
        printf("\n");
    }

    return 0;
}