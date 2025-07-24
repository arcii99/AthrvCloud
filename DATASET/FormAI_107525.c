//FormAI DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>

void sierpinski(int iterations, int length);

int main() {
    int iterations, length;
    printf("Enter the number of iterations (depth) for the fractal: ");
    scanf("%d", &iterations);
    printf("Enter the length of each side of the base triangle: ");
    scanf("%d", &length);
    sierpinski(iterations, length);
    return 0;
}

void sierpinski(int iterations, int length) {
    if (iterations == 0) { // base case
        return;
    }
    // draw the three triangles making up the current iteration
    printf("Triangle: (%d, 0), (%d, %d), (%d, 0)\n", 0, length / 2, length, length);
    printf("Triangle: (%d, 0), (%d, %d), (%d, 0)\n", length / 2, 0, length / 2, length);
    printf("Triangle: (%d, %d), (%d, 0), (%d, %d)\n", length / 2, length, length, length / 2, length);
    // call sierpinski recursively for each triangle
    sierpinski(iterations - 1, length / 2);
    sierpinski(iterations - 1, length / 2);
    sierpinski(iterations - 1, length / 2);
}