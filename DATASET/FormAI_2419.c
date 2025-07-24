//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void factorial(int n, int *result) {
    if (n < 0) {
        return;
    } else if (n == 0) {
        *result = 1;
        return;
    } else {
        factorial(n-1, result);
        *result = *result * n;
    }
}

void printArray(int *arr, int size) {
    // Base case
    if (size <= 0) {
        printf("\n");
        return;
    }
    
    // Recursive call
    printArray(arr, size - 1);
    
    // Print current element
    printf("%d ", arr[size - 1]);
}

int main() {
    // Fibonacci example
    printf("Fibonacci sequence up to 10:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n\n");
    
    // Factorial example
    int n = 6;
    int result = 1;
    factorial(n, &result);
    printf("Factorial of %d: %d\n\n", n, result);
    
    // Array example
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array elements:\n");
    printArray(arr, size);
    printf("\n");
    
    return 0;
}