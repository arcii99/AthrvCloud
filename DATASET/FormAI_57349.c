//FormAI DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>

int fibonacci_search(int arr[], int n, int x) {
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while (fib > 1) {
        int i = (offset + fib2 < n-1) ? offset + fib2 : n-1;
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    if (fib1 && arr[offset+1] == x) {
        return offset+1;
    }

    return -1;
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int index = fibonacci_search(arr, n, x);

    if (index < 0) {
        printf("%d was not found in the array.\n", x);
    } else {
        printf("%d was found at index %d in the array.\n", x, index);
    }

    return 0;
}