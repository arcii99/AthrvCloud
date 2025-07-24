//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main() {
    int row, col, size;
    char letter;

    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    printf("Enter the letter to be printed: ");
    scanf(" %c", &letter);

    for (row = 1; row <= size; row++) {
        for (col = 1; col <= size; col++) {
            if (col == row || col == size - row + 1) {
                printf("%c ", letter);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (row = 1; row <= size; row++) {
        for (col = 1; col <= size; col++) {
            if (row == 1 || row == size || col == 1 || col == size) {
                printf("%c ", letter);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (row = 1; row <= size; row++) {
        for (col = 1; col <= size; col++) {
            if (row == 1 || row == size || col == row || col == size - row + 1) {
                printf("%c ", letter);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}