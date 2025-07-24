//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fibonacci_visualizer(int n) {
    if (n <= 0) {
        printf("Invalid input!\n");
        return;
    }
    
    int a = 0, b = 1;
    int i, temp;
    
    // Print first two numbers
    printf("Fibonacci Sequence:\n");
    printf("%d %d ", a, b);
    
    // Print remaining numbers
    for (i = 3; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
        
        // Print current number with visual representation
        printf("%d [", b);
        int j;
        for (j = 0; j < b/2; j++) {
            printf("+");
        }
        printf("]\n");
    }
}

int main() {
    int n;
    char c;
    printf("How many terms of the Fibonacci Sequence would you like to see? ");
    scanf("%d", &n);
    
    fibonacci_visualizer(n);
    
    printf("\nPress any key to exit...");
    scanf(" %c", &c);
    return 0;
}