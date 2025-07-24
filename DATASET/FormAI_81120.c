//FormAI DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int n = 5; // size of the coat of arms
    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" "); // print spaces to align elements
        }

        for (k = 1; k <= i; k++) {
            printf("* "); // print the first pattern
        }

        for (j = 1; j <= n - i; j++) {
            printf(" "); // print spaces to align elements
        }

        for (j = 1; j <= n - i; j++) {
            printf(" "); // print spaces to align elements
        }

        for (k = 1; k <= i; k++) {
            printf("* "); // print the second pattern
        }

        printf("\n"); // move to the next line
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++) {
            printf(" "); // print spaces to align elements
        }

        for (k = 1; k <= i; k++) {
            printf("* "); // print the third pattern
        }

        for (j = 1; j <= n - i; j++) {
            printf(" "); // print spaces to align elements
        }

        for (j = 1; j <= n - i; j++) {
            printf(" "); // print spaces to align elements
        }

        for (k = 1; k <= i; k++) {
            printf("* "); // print the fourth pattern
        }

        printf("\n"); // move to the next line
    }

    return 0;
}