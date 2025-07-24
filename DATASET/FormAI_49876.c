//FormAI DATASET v1.0 Category: Recursive ; Style: automated
#include <stdio.h>

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int Fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
}

void printArray(int *arr, int size) {
    if(size == 0) {
        return;
    }
    printf("%d ", arr[size - 1]);
    printArray(arr, size - 1);
}

int main() {
    int num, fact, fib;
    printf("Enter a number: ");
    scanf("%d", &num);

    fact = factorial(num);
    printf("The factorial of %d is %d\n", num, fact);

    fib = Fibonacci(num);
    printf("The %dth number in the Fibonacci sequence is %d\n", num, fib);

    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    printf("\n");

    return 0;
}