//FormAI DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>
int main() {
    int n, m, i, j, space;

    printf("Enter the number of lines to print: ");
    scanf("%d", &n);

    m = n * 2 - 1; // the width of the pattern
    
    for (i = 1; i <= n; i++) {
        space = m - i * 2 + 1;
        for (j = 1; j <= i * 2 - 1; j++) {
            printf("*");
        }
        for (j = 1; j <= space; j++) {
            printf(" ");
        }
        for (j = 1; j <= i * 2 - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    for (i = n - 1; i >= 1; i--) {
        space = m - i * 2 + 1;
        for (j = 1; j <= i * 2 - 1; j++) {
            printf("*");
        }
        for (j = 1; j <= space; j++) {
            printf(" ");
        }
        for (j = 1; j <= i * 2 - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}