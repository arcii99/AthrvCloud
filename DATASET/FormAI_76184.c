//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

// Recursive function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// Function to print the first n Fibonacci numbers
void print_fibonacci(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

int main() {
    int n;
    printf("Enter the number of Fibonacci numbers to print: ");
    scanf("%d", &n);
    printf("The first %d Fibonacci numbers are: ", n);
    print_fibonacci(n);
    return 0;
}