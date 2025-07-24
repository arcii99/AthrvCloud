//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main() {
    int rows = 6;
    int i, j, k;

    // Printing the top part of the letter C
    for (i = 1; i < rows; i++) {
        for (j = i; j < rows; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Printing the middle part of the letter C
    for (i = 0; i < rows / 2; i++) {
        for (j = 0; j <= i; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // Printing the bottom part of the letter C
    for (i = rows / 2; i < rows - 1; i++) {
        for (j = i; j < rows - 2; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    // Printing the end of the letter C
    for (i = 0; i < rows - 1; i++) {
        printf("*");
    }

    return 0;
}