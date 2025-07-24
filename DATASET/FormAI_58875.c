//FormAI DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int n = 7; // size of pattern

    printf("\n");

    // top part
    for(i=1; i<=n; i++) {
        for(j=i; j<=n; j++) {
            printf("* ");
        }

        for(j=1; j<=i*2-2; j++) {
            printf("  ");
        }

        for(j=i; j<=n; j++) {
            printf("* ");
        }

        printf("\n");
    }
    
    // middle part
    for(i=1; i<=n/2; i++) {
        for(j=1; j<=n-i; j++) {
            printf("* ");
        }

        for(j=1; j<=i*2; j++) {
            printf("+ ");
        }

        for(j=1; j<=n-i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    // bottom part
    for(i=n/2; i>=1; i--) {
        for(j=1; j<=n-i; j++) {
            printf("* ");
        }

        for(j=1; j<=i*2; j++) {
            printf("+ ");
        }

        for(j=1; j<=n-i; j++) {
            printf("* ");
        }

        printf("\n");
    }
    
    // bottom space
    for(i=1; i<=n; i++) {
        printf("  ");
    }

    printf("\n");

    return 0;
}