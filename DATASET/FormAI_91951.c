//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>

int main() {

    printf("Welcome to the world of patterns!\n\n");
    
    int i, j, n = 5;
    
    // Printing first half of the pattern
    for(i=1; i<=n; i++) {
        
        // Printing space
        for(j=n-i; j>=1; j--) {
            printf(" ");
        }
        
        // Printing digits
        for(j=1; j<=i; j++) {
            printf("%d ", i);
        }
        
        printf("\n");
    }
    
    // Printing second half of the pattern
    for(i=n-1; i>=1; i--) {
        
        // Printing space
        for(j=n-i; j>=1; j--) {
            printf(" ");
        }
        
        // Printing digits
        for(j=1; j<=i; j++) {
            printf("%d ", i);
        }
        
        printf("\n");
    }

    printf("\nThank you for exploring the pattern universe with me!");

    return 0;
}