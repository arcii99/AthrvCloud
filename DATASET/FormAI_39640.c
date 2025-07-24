//FormAI DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>

int main() {
    int rows = 6;
    int cols = 6;
    int matrix[rows][cols];
    int num = 0;
    // Initialize the matrix with 0's
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }
    // Fill in the C pattern with numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            matrix[j][i] = ++num;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                printf("%.2d ", matrix[i][j]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}