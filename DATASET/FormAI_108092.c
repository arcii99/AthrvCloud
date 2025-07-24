//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main() {
    int i, j, k, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        // Printing '*' in increasing order
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        // Printing spaces
        for(k = 1; k <= 2 * (n - i); k++) {
            printf("  ");
        }
        // Printing '*' in decreasing order
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Printing second half of the pattern in reverse order
    for(i = n; i >= 1; i--) {
        // Printing '*' in increasing order
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        // Printing spaces
        for(k = 1; k <= 2 * (n - i); k++) {
            printf("  ");
        }
        // Printing '*' in decreasing order
        for(j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}