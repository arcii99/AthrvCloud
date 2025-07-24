//FormAI DATASET v1.0 Category: Pattern printing ; Style: decentralized
#include <stdio.h>

int main () {
    int n, i, j, k;
    printf("Enter an odd integer value for the pattern size: ");
    scanf("%d", &n);
    if (n%2 == 0) {
        printf("Please enter an odd integer value for the pattern size.\n");
        return 0;
    }

    // upper half of the pattern
    for (i = 1; i <= n/2+1; i++) {
        for (j = 1; j <= n-i+1; j++) {
            printf("* ");
        }
        for (j = 1; j < i*2-1; j++) {
            printf("  ");
        }
        for (j = 1; j <= n-i+1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // lower half of the pattern
    for (i = 1; i <= n/2; i++) {
        for (j = 1; j <= i+1; j++) {
            printf("* ");
        }
        for (j = 1; j <= (n-2*i); j++) {
            printf("  ");
        }
        for (j = 1; j <= i+1; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}