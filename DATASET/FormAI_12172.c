//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include <stdio.h>

int main() {
    int i, j, k, n = 5;
    printf("Surprise! Look at this unique pattern:\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    for (i = n - 1; i >=1; i--) {
        for (j = n - i; j >= 1; j--) {
            printf("  ");
        }
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\nWow, isn't that amazing?!\n");
    return 0;
}