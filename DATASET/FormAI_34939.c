//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

typedef struct {
    int x;
    int y;
} Point;

int main(void) {
    char buffer[WIDTH * HEIGHT];
    const double center_x = -0.5;
    const double center_y = 0.0;
    const double zoom = 4.0 / WIDTH;
    const int max_iterations = 256;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            const double complex c = ((x - WIDTH/2.0) * zoom + center_x) + ((y - HEIGHT/2.0) * zoom + center_y) * I;
            double complex z = 0.0 + 0.0*I;
            int i;
            for (i = 0; i < max_iterations; i++) {
                z = z*z + c;
                if (cabs(z) >= 2.0) {
                    break;
                }
            }
            buffer[x + y * WIDTH] = i == max_iterations ? ' ' : i < max_iterations / 8 ? '.' : i < max_iterations / 4 ? ':' : i < max_iterations / 2 ? 'o' : i < max_iterations ? 'O' : '#';
        }
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", buffer[x + y * WIDTH]);
        }
        printf("\n");
    }

    return 0;
}