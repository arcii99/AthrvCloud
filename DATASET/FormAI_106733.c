//FormAI DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n, i, j;
    printf("Enter a positive integer to define size of square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = abs(i - j);
        }
    }

    printf("\nOutput:\n\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}