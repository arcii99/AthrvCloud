//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cryptic
#include <stdio.h>

int main() {
    int i, j, k, n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = n-i; j >= 1; j--) {
            printf(" ");
        }

        for(k = 1; k <= i; k++) {
            printf("%c ", 64+k);
        }

        printf("\n");
    }

    for(i = n-1; i >= 1; i--) {
        for(j = n-i; j >= 1; j--) {
            printf(" ");
        }

        for(k = 1; k <= i; k++) {
            printf("%c ", 64+k);
        }

        printf("\n");
    }

    return 0;
}