//FormAI DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols, i, j;
    printf("Enter number of rows and columns (must be odd): ");
    scanf("%d %d", &rows, &cols);
    if (rows % 2 == 0 || cols % 2 == 0) {
        printf("Error: rows and columns must be odd!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1 || i == j || i + j == rows - 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}