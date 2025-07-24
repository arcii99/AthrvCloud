//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>

int main() {
    int rows, i, j, k;
    printf("Enter the number of rows:");
    scanf("%d", &rows);
    printf("\n");

    for (i = 0; i < rows; i++) {
        for (j = rows - 1; j > i; j--) {
            printf(" ");
        }
        for (k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = rows - 1; i >= 0; i--) {
        for (j = rows - 1; j > i; j--) {
            printf(" ");
        }
        for (k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}