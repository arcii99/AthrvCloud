//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main() {
    int n, i, j, k, m;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (k = n - i; k >= 1; k--)
            printf(" ");

        for (j = 1; j <= i; j++)
            printf("%d", j);

        for (m = i - 1; m >= 1; m--)
            printf("%d", m);

        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (k = n - i; k >= 1; k--)
            printf(" ");

        for (j = 1; j <= i; j++)
            printf("%d", j);

        for (m = i - 1; m >= 1; m--)
            printf("%d", m);

        printf("\n");
    }

    return 0;
}