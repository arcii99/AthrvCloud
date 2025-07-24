//FormAI DATASET v1.0 Category: Pattern printing ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    int n = 7;
    int i, j, k;
    for (i = 0; i <= n; i++) {
        for (k = 0; k <= n - i; k++)
            printf("  ");
        for (j = 0; j < i; j++)
            printf(" * ");
        printf("\n");
    }
    for (i = n - 1; i >= 0; i--) {
        for (k = 1; k <= n - i; k++)
            printf("  ");
        for (j = 0; j < i; j++)
            printf(" * ");
        printf("\n");
    }
    printf("\nOh dear, the C has formed,\nThe symbol of our love,\nOh Romeo, our love is true,\nAs true as stars above.\n");
    return 0;
}