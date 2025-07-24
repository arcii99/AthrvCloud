//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    int i, j, k;

    for (i = 1; i <= n; i++) {
        for (j = n; j > i; j--) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = n; j > i; j--) {
            printf(" ");
        }
        for (k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}