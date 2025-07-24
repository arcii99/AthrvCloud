//FormAI DATASET v1.0 Category: Sorting ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    srand(time(NULL));
    const int SIZE = 10;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Initial array: ");
    printArray(arr, SIZE);

    // Sort using insertion sort
    printf("Sorting using insertion sort...\n");
    insertionSort(arr, SIZE);
    printArray(arr, SIZE);

    // Sort using bubble sort
    printf("Sorting using bubble sort...\n");
    bubbleSort(arr, SIZE);
    printArray(arr, SIZE);

    // Sort using selection sort
    printf("Sorting using selection sort...\n");
    selectionSort(arr, SIZE);
    printArray(arr, SIZE);

    return 0;
}