//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>

int main() {
    int rows, i, j, space, k = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for(i = 1; i <= rows; i++) {
        for(space = 1; space <= rows - i; space++) {
            printf("  ");
        }

        for(j = 1; j <= i; j++) {
            printf("%d ", k++);
        }

        printf("\n");
    }

    return 0;
}