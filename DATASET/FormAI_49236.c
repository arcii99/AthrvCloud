//FormAI DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    int length, depth;
    printf("Enter the length and depth of the fractal: ");
    scanf("%d %d", &length, &depth);

    int arraySize = pow(2, depth);
    char fractal[arraySize][arraySize];

    for(int i = 0; i < arraySize; i++) {
        for(int j = 0; j < arraySize; j++) {
            fractal[i][j] = ' ';
        }
    }

    int mid = arraySize / 2;
    fractal[mid][mid] = '*';

    for(int n = 0; n < depth; n++) {
        int size = pow(2, n);
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(fractal[i][j] == '*') {
                    fractal[i][j+size] = '*';
                    fractal[i+size][j] = '*';
                    fractal[i+size][j+2*size] = '*';

                    if(n == depth - 1)
                        fractal[i+size][j+size] = '*';
                }
            }
        }
    }

    printf("\n");
    for(int i = 0; i < arraySize; i++) {
        for(int j = 0; j < arraySize; j++) {
            printf("%c ", fractal[i][j]);
        }
        printf("\n");
    }

    return 0;
}