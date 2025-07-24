//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, space;
    printf("Enter the number of rows for the pattern: ");
    scanf("%d", &n);
    space = n-1;

    for(i=1; i<=n; i++) {  // Loop for upper section of pattern
        for(j=1; j<=space; j++) {
            printf(" ");
        }

        for(k=1; k<=2*i-1; k++) {
            printf("*");
        }

        printf("\n");
        space--;
    }

    space = 1;

    for(i=n-1; i>=1; i--) {  // Loop for lower section of pattern
        for(j=1; j<=space; j++) {
            printf(" ");
        }

        for(k=1; k<=2*i-1; k++) {
            printf("*");
        }

        printf("\n");
        space++;
    }

    return 0;
}