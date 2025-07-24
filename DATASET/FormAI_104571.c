//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next, c;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    // Check if there are more than 0 terms
    if (n < 1) {
        printf("Invalid input. Please enter a positive integer.");
        return 0;
    }
    
    // Print the first two terms
    printf("Fibonacci Series:\n");
    printf("%d %d ", first, second);
    
    // Generate the rest of the sequence and print
    for (c = 3; c <= n; c++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }
    
    printf("\n");
    
    return 0;
}