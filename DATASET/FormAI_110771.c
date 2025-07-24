//FormAI DATASET v1.0 Category: Pattern printing ; Style: decentralized
#include <stdio.h>

int main() {
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++) {
        // Printing upper half
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Printing lower half
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }

    for (int i = rows - 1; i >= 1; i--) {
        // Printing upper half
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        // Printing lower half
        for (int j = i - 1; j >=1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}