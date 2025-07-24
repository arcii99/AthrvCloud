//FormAI DATASET v1.0 Category: Pattern printing ; Style: ultraprecise
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the number of rows you want in your C pattern: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("*");
        for (j = 0; j < n; j++) {
            if (i == 0 || i == n - 1) {
                printf("*");
            } else if (j == n - 1 && i <= n / 2) {
                printf("*");
            } else if (i == n / 2 && j <= n / 2) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}