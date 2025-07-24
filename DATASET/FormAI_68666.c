//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>
int main() {
    // Welcome message
    printf("Hello there! I'm going to print a unique C pattern for you!\n");
    
    // Prompt for user input
    printf("Enter the size of the pattern (odd numbers only): ");
    int n;
    scanf("%d", &n);
    
    // Validate user input
    if (n % 2 == 0) {
        printf("Oops, that's an even number. Please enter an odd number.\n");
        return 0; // End program
    }
    
    // Print the pattern
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n-1 || j == 0 || j == n-1 || i == j || i + j == n-1) {
                printf("C ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    // Farewell message
    printf("Hope you enjoyed the pattern! Goodbye!\n");
    
    return 0;
}