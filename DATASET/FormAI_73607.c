//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main() {
    int rows = 5;
    int i, j, k;

    // Prints top half of the pattern
    for (i = 0; i < rows; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = i; k < rows; k++) {
            printf("* ");
        }
        printf("\n");
    }

    // Prints bottom half of the pattern
    for (i = rows; i > 0; i--) {
        for (j = 0; j < i-1; j++) {
            printf(" ");
        }
        for (k = i-1; k < rows; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}