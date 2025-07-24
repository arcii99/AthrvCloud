//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>

int main() {
    int i, j, k, n = 7;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for(k = i + 1; k <= n; k++) {
            printf("  ");
        }
        printf("| ");
        for(k = n; k > i; k--) {
            printf("  ");
        }
        for(j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }

    for(i = n - 1; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for(k = i + 1; k <= n; k++) {
            printf("  ");
        }
        printf("| ");
        for(k = n; k > i; k--) {
            printf("  ");
        }
        for(j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}