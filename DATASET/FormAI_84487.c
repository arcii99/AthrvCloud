//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

int **generateFractal(int depth);
void printFractal(int **fractal, int depth);

int main() {
    int depth;
    printf("Enter the depth of the Sierpinski triangle fractal you want to generate: ");
    scanf("%d", &depth);

    int **fractal = generateFractal(depth);
    printFractal(fractal, depth);

    return 0;
}

int **generateFractal(int depth) {
    int **fractal = malloc(depth * sizeof(int *));
    for (int i = 0; i < depth; i++) {
        fractal[i] = calloc((1 << i), sizeof(int));
    }
    fractal[0][0] = 1;
    for (int i = 1; i < depth; i++) {
        for (int j = 0; j < (1 << i); j++) {
            fractal[i][j] = fractal[i-1][j/2] + fractal[i-1][(j+1)/2];
        }
    }
    return fractal;
}

void printFractal(int **fractal, int depth) {
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < (1 << i); j++) {
            printf("%c ", fractal[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}