//FormAI DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>

int main() {
    int i, j, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Upper half of the pattern
    for(i = 1; i <= n; i++) {
        for(j = i; j < n; j++) {
            printf(" ");
        }
        printf("*");
        for(j = 1; j < 2*(i-1); j++) {
            printf(" ");
        }
        if(i > 1) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half of the pattern
    for(i = n-1; i >= 1; i--) {
        for(j = i; j <= n-1; j++) {
            printf(" ");
        }
        printf("*");
        for(j = 1; j < 2*(i-1); j++) {
            printf(" ");
        }
        if(i > 1) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}