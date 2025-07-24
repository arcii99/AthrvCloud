//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

int main() {

    int rows, cols, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix[i][j] = i * j;
        }
    }

    printf("\nPrinting the matrix.\n\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nPrinting the C Pattern.\n\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%3d ", matrix[i][j]);
            }
            else if (i >= j) {
                printf("%3d ", matrix[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }

    return 0;
}