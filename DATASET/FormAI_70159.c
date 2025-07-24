//FormAI DATASET v1.0 Category: Fractal Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define SIZE 2048
#define MAX_ITER 100

void generate_fractal(int fractal[SIZE][SIZE], int x, int y, int size, int iter) {
    // Base case
    if (size == 1) {
        fractal[x][y] = iter % 2;
        return;
    }

    // Draw three scaled-down copies
    int new_size = size / 2;
    generate_fractal(fractal, x, y, new_size, iter + 1);
    generate_fractal(fractal, x + new_size, y, new_size, iter + 1);
    generate_fractal(fractal, x, y + new_size, new_size, iter + 1);

    // Draw a fourth copy if iter is odd
    if (iter % 2 == 1) {
        generate_fractal(fractal, x + new_size, y + new_size, new_size, iter + 1);
    }
}

int main() {
    srand(time(NULL));

    // Generate the fractal
    int fractal[SIZE][SIZE];
    memset(fractal, 0, SIZE * SIZE * sizeof(int));
    generate_fractal(fractal, 0, 0, SIZE, 0);

    // Print the fractal
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", (fractal[i][j] == 1) ? '#' : ' ');
        }
        printf("\n");
    }

    return 0;
}