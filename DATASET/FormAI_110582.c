//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

int main() {
    int rows = 15;
    int i, j, k; 

    for (i = 1; i <= rows; i++) {
        // pattern 1
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");

        // pattern 2
        for (k = rows; k >= i; k--) {
            printf("  ");
        }
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = rows - 1; i >= 1; i--) {
        // pattern 3
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");

        // pattern 4
        for (k = rows; k >= i; k--) {
            printf("  ");
        }
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}