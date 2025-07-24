//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print all the elements of an integer array using recursion
void printArray(int *arr, int size)
{
    if (size == 0) // base case
        return;

    printf("%d ", *arr);
    printArray(arr + 1, size - 1); // recursive call
}

// Function to check if a number is prime using recursion
bool isPrime(int num, int currDivisor)
{
    if (currDivisor == 1) // base case
        return true;
    
    if (num % currDivisor == 0) // check if the number is divisible
        return false;
        
    return isPrime(num, currDivisor - 1); // recursive call
}

// Function to calculate the nth fibonacci number using recursion
int fibonacci(int n)
{
    if (n <= 1) // base case
        return n;
    
    return fibonacci(n-1) + fibonacci(n-2); // recursive call
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array elements: ");
    printArray(arr, size);
    printf("\n");
    
    int num = 17;
    printf("%d is%s a prime number.\n", num, isPrime(num, num-1) ? "" : " not");
    
    int n = 8;
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");
    
    return 0;
}