//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int rows = 10;
    int starred_rows = 5;
    int i, j;

    // Meet Romeo and Juliet
    printf("Meet Romeo and Juliet, the C pattern stars:\n\n");

    // Print top half
    for(i = 1; i <= starred_rows; i++) {
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Print middle row
    printf("C ");
    for(i = 1; i < rows; i++) {
        printf("* ");
    }
    printf("\n");

    // Print bottom half
    for(i = starred_rows; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // "Parting is such sweet sorrow"
    printf("\nAlas, Romeo and Juliet must part ways.\n");

    return 0;
}