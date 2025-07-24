//FormAI DATASET v1.0 Category: Educational ; Style: mathematical
#include <stdio.h>

// Function to compute the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int num, i;
    
    // Get the number of terms of the Fibonacci sequence to generate
    printf("Enter the number of terms of the Fibonacci sequence to generate: ");
    scanf("%d", &num);
    
    // Print the Fibonacci sequence
    printf("Fibonacci sequence:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }
    
    return 0;
}