//FormAI DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

// Recursive function to generate Fibonacci series
int fibonacci(int n) {
    if (n <= 1) { // Base case
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2); // Recursive call
    }
}

int main() {
    int n;
    printf("Enter the number of terms to generate in Fibonacci series: ");
    scanf("%d", &n);
    printf("The first %d terms of Fibonacci series are: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}