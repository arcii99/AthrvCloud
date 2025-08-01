//FormAI DATASET v1.0 Category: Pattern printing ; Style: immersive
#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("\n\n");

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-i; j++) {
            printf("  ");
        }
        for (int j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    for (int i=n-1; i>=1; i--) {
        for (int j=1; j<=n-i; j++) {
            printf("  ");
        }
        for (int j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n\n");

    return 0;
}