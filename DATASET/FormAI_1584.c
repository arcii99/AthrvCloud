//FormAI DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int arr[SIZE];

    srand(time(NULL));
    // Initialize random array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Print unsorted array
    printf("Unsorted Array: ");
    printArray(arr, SIZE);

    // Bubble sort
    bubbleSort(arr, SIZE);
    printf("Bubble Sort: ");
    printArray(arr, SIZE);

    // Insertion sort
    insertionSort(arr, SIZE);
    printf("Insertion Sort: ");
    printArray(arr, SIZE);

    // Selection sort
    selectionSort(arr, SIZE);
    printf("Selection Sort: ");
    printArray(arr, SIZE);

    return 0;
}