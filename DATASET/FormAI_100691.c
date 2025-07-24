//FormAI DATASET v1.0 Category: Pattern printing ; Style: accurate
#include <stdio.h>

int main() {
    int n = 5; // number of rows in the pattern

    /* Pattern 1 */
    printf("Pattern 1:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }

    /* Pattern 2 */
    printf("Pattern 2:\n");
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }

    /* Pattern 3 */
    printf("Pattern 3:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("%c ", j + 64); // display A, B, C, ...
        printf("\n");
    }

    /* Pattern 4 */
    printf("Pattern 4:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    /* Pattern 5 */
    printf("Pattern 5:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("%d ", i);
        printf("\n");
    }

    /* Pattern 6 */
    printf("Pattern 6:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("%d ", j % 2);
        printf("\n");
    }

    /* Pattern 7 */
    printf("Pattern 7:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("%d ", (i+j) % 2);
        printf("\n");
    }

    /* Pattern 8 */
    printf("Pattern 8:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i+1; j++)
            printf("%c ", j + 64); // display A, B, C, ...
        printf("\n");
    }

    /* Pattern 9 */
    printf("Pattern 9:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++)
            printf("  ");
        for (int j = 1; j <= 2*i-1; j++)
            printf("* ");
        printf("\n");
    }

    /* Pattern 10 */
    printf("Pattern 10:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-i; j++)
            printf("  ");
        for (int j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }

    return 0;
}