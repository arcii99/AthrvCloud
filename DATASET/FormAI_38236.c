//FormAI DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>

int main() {
    int n, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Upper half of the pattern
    for(i=1; i<=n/2; i++) {
        for(j=1; j<=2*i-1; j++) {
            printf("*");
        }
        for(k=j; k<=2*n-1; k++) {
            printf(" ");
        }
        for(j=k; j<=2*n-i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half of the pattern
    for(i=n/2+1; i<=n; i++) {
        for(j=1; j<=2*n-i; j++) {
            printf("*");
        }
        for(k=j; k<=2*i-1; k++) {
            printf(" ");
        }
        for(j=k; j<=2*n-1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}