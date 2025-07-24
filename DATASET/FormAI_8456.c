//FormAI DATASET v1.0 Category: Pattern printing ; Style: genious
#include <stdio.h>

int main() {
    int i, j, k, n = 5;

    // upper half of the C pattern
    for (i = 1; i <= n; i++) { // rows
        for (j = 1; j <= n; j++) { // cols
            if (i == 1 || j == 1 || i == n) { // printing C
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    // lower half of the C pattern
    for (i = 1; i <= n; i++) { // rows
        for (j = 1; j <= n; j++) { // cols
            if (j == 1 || i == n) { // printing C
                printf("* ");
            } else {
                for (k = 1; k <= n - 2; k++) {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    printf("\nGenius, right?\n");
    return 0;
}