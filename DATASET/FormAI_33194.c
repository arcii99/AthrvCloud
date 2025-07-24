//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, spaces, stars, i, j;

    printf("Enter the number of rows to print the pattern: ");
    scanf("%d", &rows);

    if (rows <= 0) {
        printf("Number of rows should be greater than 0\n");
        exit(0);
    }

    for(i = 1; i <= rows; i++) {
        for(spaces = 1; spaces <= rows-i; spaces++) {
            printf("  ");
        }
        for(stars = 1; stars <= i; stars++) {
            printf("* ");
        }
        printf("\n");
    }

    for(i = 1; i <= rows; i++) {
        for(spaces = 1; spaces <= i-1; spaces++) {
            printf("  ");
        }
        for(stars = 1; stars <= rows-i+1; stars++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}