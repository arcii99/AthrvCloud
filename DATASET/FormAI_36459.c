//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main() {
    int n;
    printf("Enter the length of pattern: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        for (int j = 1; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        for (int j = 1; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}