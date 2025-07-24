//FormAI DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    // First half of the pattern
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (int j = i + 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Second half of the pattern
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (int j = i + 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}