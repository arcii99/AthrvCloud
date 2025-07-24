//FormAI DATASET v1.0 Category: Fractal Generation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 50

typedef struct {
    double x, y;
} complex;

int main(void) {
    // Initialize random number generator
    srand(time(NULL));
    // Initialize window
    int window[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            window[i][j] = 0;
        }
    }
    // Initialize constants
    double a = (double) (rand() % (WIDTH - 100)) * 0.01 - 2;
    double b = (double) (rand() % (HEIGHT - 100)) * 0.01 - 1.5;
    double zoom = 1;
    // Calculate fractal
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            complex c = {a + (double) j * 0.002 * zoom, b + (double) i * 0.002 * zoom};
            complex z = {0, 0};
            int n = 0;
            while (n < MAX_ITERATIONS && z.x * z.x + z.y * z.y < 4) {
                complex z_next = {z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y};
                z = z_next;
                n++;
            }
            window[i][j] = n;
        }
    }
    // Print fractal
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (window[i][j] == MAX_ITERATIONS) {
                printf(".");
            } else if (window[i][j] > MAX_ITERATIONS / 2) {
                printf("*");
            } else if (window[i][j] > MAX_ITERATIONS / 4) {
                printf("+");
            } else if (window[i][j] > MAX_ITERATIONS / 8) {
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}