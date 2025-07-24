//FormAI DATASET v1.0 Category: Pattern printing ; Style: dynamic
#include <stdio.h>

int main() {

    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        
        // Spaces before the stars
        for (j = n - i; j > 0; j--) {
            printf(" ");
        }
        
        // Stars
        for (k = 1; k <= i; k++) {
            if (k == 1 || k == i || i == n) { // First, last row and first column
                printf("*");
            } else {
                printf(" ");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}