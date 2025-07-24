//FormAI DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
// Ada Lovelace-inspired C Recursive Example Program
// By OpenAI's Chatbot

#include <stdio.h>

// Define function to calculate the factorial of a number recursively
int factorial(int n) {
    if (n == 0) { // Base case: factorial of 0 is 1
        return 1;
    } else {
        return n * factorial(n-1); // Recursive case: compute factorial of n-1 and multiply by n
    }
}

// Define function to calculate the Fibonacci sequence recursively
int fibonacci(int n) {
    if (n == 0 || n == 1) { // Base case: fibonacci of 0 or 1 is n
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2); // Recursive case: compute fibonacci of n-1 and n-2 and add them together
    }
}

// Define function to calculate the sum of an array recursively
int array_sum(int array[], int size) {
    if (size == 0) { // Base case: sum of an empty array is 0
        return 0;
    } else {
        return array[size-1] + array_sum(array, size-1); // Recursive case: add the last element of the array to the sum of the rest of the array
    }
}

int main() {
    // Test the factorial function
    printf("Factorial of 5 is %d\n", factorial(5)); // Expected output: 120
    
    // Test the Fibonacci function
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i)); // Expected output: 0 1 1 2 3 5 8 13 21 34
    }
    printf("\n");
    
    // Test the array sum function
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(int);
    printf("Sum of the array {1, 2, 3, 4, 5} is %d\n", array_sum(array, size)); // Expected output: 15
    
    return 0;
}