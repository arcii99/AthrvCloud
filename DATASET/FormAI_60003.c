//FormAI DATASET v1.0 Category: Pattern printing ; Style: Alan Touring
// Alan Turing-style C pattern printing program
#include <stdio.h>

int main() {
    int rows, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Loop to print the upper triangle
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (k = 1; k <= i; k++) {
            printf("*   ");
        }
        printf("\n");
    }

    // Loop to print the lower triangle
    for (i = rows - 1; i >= 1; i--) {
        for (j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (k = 1; k <= i; k++) {
            printf("*   ");
        }
        printf("\n");
    }

    return 0;
}