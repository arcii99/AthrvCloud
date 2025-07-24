//FormAI DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr1[] = {89, 12, 54, 87, 47, 91, 33, 8, 27, 61};
    int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    printf("Original Array: ");
    printArray(arr1, arr1_size);
    bubbleSort(arr1, arr1_size);
    printf("Bubble Sorted Array: ");
    printArray(arr1, arr1_size);

    int arr2[] = {89, 12, 54, 87, 47, 91, 33, 8, 27, 61};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    printf("Original Array: ");
    printArray(arr2, arr2_size);
    insertionSort(arr2, arr2_size);
    printf("Insertion Sorted Array: ");
    printArray(arr2, arr2_size);

    return 0;
}