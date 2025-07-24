//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

int main() {
    // declaring variables
    int n, i, j, k;
    
    // taking input from user
    printf("Enter the number of rows (odd number): ");
    scanf("%d", &n);
    
    // checking if input is odd
    if (n % 2 == 0) {
        printf("Number of rows should be odd.");
        exit(0);
    }
    
    // printing C pattern
    for (i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            for (j = 1; j <= n; j++) {
                printf("*");
            }
        } else {
            for (j = 1; j <= n; j++) {
                if (j == 1 || j == n) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}