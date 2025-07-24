//FormAI DATASET v1.0 Category: Pattern printing ; Style: portable
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Printing the upper half of the pattern
    for(i=1; i<=n; i++) {
        for(j=1; j<=i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Printing the lower half of the pattern
    for(i=n-1; i>=1; i--) {
        for(j=1; j<=i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}