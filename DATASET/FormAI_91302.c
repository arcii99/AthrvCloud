//FormAI DATASET v1.0 Category: Pattern printing ; Style: mathematical
#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Upper Half
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++)
            printf("   ");

        for (j = 1; j <= i; j++)
            printf("%2d ", j);

        for (j = i - 1; j >= 1; j--)
            printf("%2d ", j);

        printf("\n");
    }

    // Lower Half
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i; j++)
            printf("   ");

        for (j = 1; j <= i; j++)
            printf("%2d ", j);

        for (j = i - 1; j >= 1; j--)
            printf("%2d ", j);

        printf("\n");
    }

    return 0;
}