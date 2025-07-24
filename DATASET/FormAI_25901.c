//FormAI DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of rows to print the pattern: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }

        for (int j = n-i; j >= 1; j--) {
            printf("  ");
        }

        for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}