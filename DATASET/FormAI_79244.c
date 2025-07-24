//FormAI DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

int main() {
    
    int n = 7; // The size of the pattern
    
    // To print the first half of the pattern
    for (int i = 1; i <= n; i++) {
        
        // Print spaces equal to (n - i) times 2
        for (int j = 1; j <= ((n - i) * 2); j++) {
            printf(" ");
        }
        
        // Print the numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        // Print the numbers from i - 1 to 1
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        
        // Print a new line after each row
        printf("\n");
    }
    
    // To print the second half of the pattern
    for (int i = n - 1; i >= 1; i--) {
        
        // Print spaces equal to (n - i) times 2
        for (int j = 1; j <= ((n - i) * 2); j++) {
            printf(" ");
        }
        
        // Print the numbers from 1 to i
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        
        // Print the numbers from i - 1 to 1
        for (int j = i - 1; j >= 1; j--) {
            printf("%d ", j);
        }
        
        // Print a new line after each row
        printf("\n");
    }
    
    return 0;
}