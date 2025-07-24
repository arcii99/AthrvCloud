//FormAI DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

int main() {
    int i, j, k, l, m, n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    
    // Upper triangle
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        
        for (k = 0; k <= i; k++) {
            printf("*");
        }
        
        for (l = 0; l < i; l++) {
            printf("*");
        }
        printf("\n");
    }
    
    // Lower triangle
    for (m = n - 1; m >= 0; m--) {
        for (j = 0; j < n - m - 1; j++) {
            printf(" ");
        }
        
        for (k = 0; k <= m; k++) {
            printf("*");
        }
        
        for (l = 0; l < m; l++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}