//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void print_array(int arr[], int size) {
    if (size == 0) {
        printf("[]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < size - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[size - 1]);
}

int binary_search(int arr[], int target, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binary_search(arr, target, mid + 1, end);
    } else {
        return binary_search(arr, target, start, mid - 1);
    }
}

int main() {
    printf("Factorial of 5 is %d\n", factorial(5));
    printf("Fibonacci number at 8th position is %d\n", fibonacci(8));
    
    int arr1[] = {1, 2, 3, 4, 5};
    printf("Array 1 is ");
    print_array(arr1, 5);
    
    int arr2[] = {5, 4, 3, 2, 1};
    printf("Array 2 is ");
    print_array(arr2, 5);
    
    int index = binary_search(arr1, 3, 0, 4);
    printf("Index of 3 in Array 1 is %d\n", index);
    
    index = binary_search(arr2, 5, 0, 4);
    printf("Index of 5 in Array 2 is %d\n", index);
    
    return 0;
}