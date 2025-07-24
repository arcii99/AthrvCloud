//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int i, j, k;
    int n = 9;

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) {
            printf("%d", j % 2);
        }

        for (j = i - 1; j >= 1; j--) {
            printf("%d", j % 2);
        }

        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {

        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) {
            printf("%d", j % 2);
        }

        for (j = i - 1; j >= 1; j--) {
            printf("%d", j % 2);
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}