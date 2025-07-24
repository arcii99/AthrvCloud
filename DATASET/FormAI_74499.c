//FormAI DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Recursive function to find the factorial of a number n
int factorial(int n) 
{
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Recursive function to calculate Fibonacci series up to n terms
void fibonacci(int n, int *arr) 
{
    if (n == 0) {
        arr[0] = 0;
    } else if (n == 1) {
        arr[0] = 0;
        arr[1] = 1;
    } else {
        fibonacci(n-1, arr);
        arr[n] = arr[n-1] + arr[n-2];
    }
}

// Recursive function to print a given string in reverse order
void printReverse(char *str) 
{
    if (*str) {
        printReverse(str+1);
        printf("%c", *str);
    }
}

// Recursive function to count the number of digits in an integer
int countDigits(int n) 
{
    if (n == 0) {
        return 0;
    } else {
        return 1 + countDigits(n/10);
    }
}

// Recursive function to calculate the sum of digits in an integer
int sumDigits(int n) 
{
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + sumDigits(n/10);
    }
}

int main() 
{
    // Example usage of the recursive functions
    int n = 5;
    int arr[n+1];

    printf("Factorial of %d is %d\n", n, factorial(n));

    fibonacci(n, arr);
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 0; i < n+1; i++) {
        printf("%d ", arr[i]);
    }

    char str[] = "Hello, world!";
    printf("\nReverse of '%s' is '", str);
    printReverse(str);
    printf("'\n");

    int num = 12345;
    printf("Number of digits in %d is %d\n", num, countDigits(num));
    printf("Sum of digits in %d is %d\n", num, sumDigits(num));

    return 0;
}