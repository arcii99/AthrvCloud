//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int max_element(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }
    int max = max_element(arr, size-1);
    if (max > arr[size-1]) {
        return max;
    } else {
        return arr[size-1];
    }
}

int main() {
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\nMax element: %d\n", max_element(arr, SIZE));
    return 0;
}