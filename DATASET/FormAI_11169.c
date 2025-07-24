//FormAI DATASET v1.0 Category: Recursive ; Style: invasive
#include <stdio.h>

// This code will invade your mind and force you to think recursively

// Recursive function to calculate the factorial of a number
int invadeFactorial(int n) {
    // Print a message to let you know what's happening
    printf("I'm invading your mind to calculate %d! ", n);
    
    if (n == 0) {
        // Base case
        printf("The answer is 1\n");
        return 1;
    } else {
        // Recursive case
        int result = n * invadeFactorial(n - 1);
        printf("The answer is %d\n", result);
        return result;
    }
}

// Recursive function to calculate the nth fibonacci number
int invadeFibonacci(int n) {
    // Print a message to let you know what's happening
    printf("I'm invading your mind to calculate the %dth fibonacci number ", n);
    
    if (n == 0) {
        // Base case
        printf("The answer is 0\n");
        return 0;
    } else if (n == 1) {
        // Base case
        printf("The answer is 1\n");
        return 1;
    } else {
        // Recursive case
        int result = invadeFibonacci(n - 1) + invadeFibonacci(n - 2);
        printf("The answer is %d\n", result);
        return result;
    }
}

// Recursive function to print elements of an array in reverse order
void invadeReverseArray(int arr[], int start, int end) {
    // Print a message to let you know what's happening
    printf("I'm invading your mind to reverse an array from index %d to %d ", start, end);
    
    if (start >= end) {
        // Base case
        printf("The array is now reversed!\n");
        return;
    } else {
        // Recursive case
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        invadeReverseArray(arr, start + 1, end - 1);
    }
}

int main() {
    // Generate an array of numbers to reverse
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Calculate some factorials and fibonacci numbers using recursion
    int fact5 = invadeFactorial(5);
    int fact7 = invadeFactorial(7);
    int fib10 = invadeFibonacci(10);
    
    // Print the results
    printf("5! = %d\n", fact5);
    printf("7! = %d\n", fact7);
    printf("The 10th fibonacci number is %d\n", fib10);
    
    // Reverse the array and print the result
    printf("Before: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    invadeReverseArray(arr, 0, n - 1);
    
    printf("After: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}