//FormAI DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 8, 14, 1, 16, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}