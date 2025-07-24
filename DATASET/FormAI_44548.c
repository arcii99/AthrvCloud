//FormAI DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    printf("\n");

    // Printing upper half of the pattern
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Printing lower half of the pattern
    for (i = n - 1; i > 0; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}