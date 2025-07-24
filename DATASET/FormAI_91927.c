//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 1000

bool fractal[WIDTH][HEIGHT]; // represents the fractal

// returns the number of iterations needed to escape the point
int escape_time(double x, double y) {
    double cx = x;
    double cy = y;
    int iterations = 0;
    while (cx * cx + cy * cy < 16 && iterations < MAX_ITERATIONS) {
        double temp_x = cx * cx - cy * cy + x;
        cy = 2 * cx * cy + y;
        cx = temp_x;
        iterations++;
    }
    return iterations;
}

// fills the fractal array based on the escape time of each point
void fill_fractal() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            double x = (i - WIDTH / 2) * 4.0 / WIDTH;
            double y = (j - HEIGHT / 2) * 4.0 / HEIGHT;
            int iterations = escape_time(x, y);
            fractal[i][j] = (iterations == MAX_ITERATIONS);
        }
    }
}

// prints the fractal in ASCII art
void print_fractal() {
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            printf("%c ", fractal[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    fill_fractal();
    print_fractal();
    return 0;
}