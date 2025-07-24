//FormAI DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>

int main() {
    int n = 5;
    int i, j, k;

    printf("Printing a 'C' pattern using asterisks (*)\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n) {
                printf("*");
            } else if (j == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");

    printf("Printing a 'C' pattern using letters (C-O-D-E)\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1) {
                printf("C");
            } else if (i == 2 || i == 3) {
                printf(" ");
            } else if (j == n) {
                printf("E");
            } else if (i == 4 || i == 5) {
                printf(" ");
            } else if (j == n - 1) {
                printf("O");
            } else if (i == 6) {
                printf("D");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}