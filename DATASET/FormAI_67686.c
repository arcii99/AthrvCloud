//FormAI DATASET v1.0 Category: Sorting ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int* arr, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int* selectionSort(int* arr, int size) {
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    return arr;
}

int* insertionSort(int* arr, int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return arr;
}

int main() {
    int arr[] = { 5, 4, 1, 3, 2 };
    int size = sizeof(arr) / sizeof(int);
    int* sortedArr;

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // bubble sort
    sortedArr = bubbleSort(arr, size);
    printf("\nBubble Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }

    // selection sort
    sortedArr = selectionSort(arr, size);
    printf("\nSelection Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }

    // insertion sort
    sortedArr = insertionSort(arr, size);
    printf("\nInsertion Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArr[i]);
    }

    return 0;
}