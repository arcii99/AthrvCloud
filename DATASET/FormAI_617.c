//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main() {
    int i, j, k;
    int height = 7; // height of the pattern

    // first half of the pattern
    for (i = 1; i <= height / 2 + 1; i++) {
        for (j = 1; j <= height / 2 + 1 - i; j++) {
            printf("*");
        }
        for (j = 1; j <= i * 2 - 1; j++) {
            printf(" ");
        }
        for (j = 1; j <= height / 2 + 1 - i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // second half of the pattern
    for (i = height / 2; i >= 1; i--) {
        for (j = 1; j <= height / 2 + 1 - i; j++) {
            printf("*");
        }
        for (j = 1; j <= i * 2 - 1; j++) {
            printf(" ");
        }
        for (j = 1; j <= height / 2 + 1 - i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}