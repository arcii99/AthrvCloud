//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Declare function to be used in main
int fib(int);

int main(void) {
    int num;

    printf("Enter the number of terms you want: ");
    scanf("%d", &num);

    // Check if the input is valid
    if (num <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 0;
    }

    printf("The %d terms of the Fibonacci sequence are:\n", num);

    // Loop through num terms and calculate Fibonacci number for each
    for (int i = 0; i < num; i++) {
        printf("%d ", fib(i));
    }

    printf("\n");

    return 0;
}

// Recursive function to calculate the nth Fibonacci number
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib(n-1) + fib(n-2);
    }
}