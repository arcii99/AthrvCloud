//FormAI DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>

int main() {
    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Upper half
    for(i=1; i<=n/2; i++) {
        for(j=1; j<=i; j++)
            printf("%d", j);
        for(k=1; k<=2*(n/2-i); k++)
            printf(" ");
        for(j=i; j>=1; j--)
            printf("%d", j);
        printf("\n");
    }

    // Middle row
    for(j=1; j<=n/2; j++)
        printf("%d", j);
    printf("0");
    for(j=n/2; j>=1; j--)
        printf("%d", j);
    printf("\n");

    // Lower half
    for(i=n/2; i>=1; i--) {
        for(j=1; j<=i; j++)
            printf("%d", j);
        for(k=1; k<=2*(n/2-i); k++)
            printf(" ");
        for(j=i; j>=1; j--)
            printf("%d", j);
        printf("\n");
    }

    return 0;
}