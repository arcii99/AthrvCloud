//FormAI DATASET v1.0 Category: Recursive ; Style: recursive
#include <stdio.h>

int sum(int n) {
    if(n == 0) {
        return 0;
    }
    return n + sum(n-1);
}

int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void print_binary(int n) {
    if(n == 0) {
        return;
    }
    print_binary(n/2);
    printf("%d", n % 2);
}

void print_array(int *arr, int size) {
    if(size == 0) {
        return;
    }
    printf("%d ", arr[0]);
    print_array(arr+1, size-1);
}

int find_max(int *arr, int size) {
    if(size == 1) {
        return arr[0];
    }
    int max = find_max(arr+1, size-1);
    return (arr[0] > max) ? arr[0] : max;
}

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int n = 5;
    printf("Sum of 1 to %d: %d\n", n, sum(n));
    printf("Fibonacci sequence up to %d: ", n);
    for(int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\nBinary representation of %d: ", n);
    print_binary(n);
    printf("\n");
    int arr[] = {1, 3, 5, 7, 9};
    printf("Array: ");
    print_array(arr, 5);
    printf("\n");
    printf("Max element in array: %d\n", find_max(arr, 5));
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}