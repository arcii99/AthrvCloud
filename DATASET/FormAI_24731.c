//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    int n = 5, i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
    for (i = n-1; i >= 1; i--) {
        for (j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    return 0;
}