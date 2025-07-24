//FormAI DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Invasive function to generate Fibonacci sequence
int fib(int n) {
    if (n == 0) {
        printf("Hey you! Give me a positive integer to calculate Fibonacci of: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Wow, you're really pushing my limits here. Please enter a positive integer: ");
            scanf("%d", &n);
        }
    }
    if (n == 1 || n == 2) {
        return 1;
    } else {
        int result = (fib(n-1) + fib(n-2));
        printf("Fibonacci of %d is %d\n", n, result);
        return result;
    }
}

int main() {
    printf("Welcome to the invasive Fibonacci calculator!\n");
    printf("This program will calculate the Fibonacci sequence up to the number you provide.\n");
    
    int num;
    printf("Please enter a positive integer: ");
    scanf("%d", &num);
    if (num <= 0) {
        printf("I'm sorry, did you not understand what 'positive' meant? Let's try this again...\n");
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    }
    
    printf("Calculating Fibonacci sequence...\n");
    fib(num);
    
    printf("Thank you for using the invasive Fibonacci calculator.\n");
    return 0;
}