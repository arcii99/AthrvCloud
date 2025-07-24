//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
// This is an example program that demonstrates the use of loops and functions in C.

#include <stdio.h>

int factorial(int num) {
    // recursive function to calculate factorial of a number
    if (num == 1 || num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

int main() {
    printf("Welcome to Ada Lovelace's factorial program!\n\n");
    
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("\nSorry, factorial of negative numbers is not defined.\n");
    } else {
        printf("\nFactorial of %d is %d\n", num, factorial(num));
    }
    
    printf("\nThank you for using Ada Lovelace's program!\n");
    
    // loop to print first 10 numbers in fibonacci series
    int fib1 = 0, fib2 = 1;
    printf("\nFirst 10 numbers in fibonacci series:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fib1);
        int temp = fib1;
        fib1 = fib2;
        fib2 = temp + fib2;
    }
    
    return 0;
}