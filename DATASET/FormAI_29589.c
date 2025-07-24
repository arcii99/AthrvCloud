//FormAI DATASET v1.0 Category: Benchmarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void bubbleSort(int arr[]) {
    int temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[]) {
    int key, j;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[]) {
    int minIndex, temp;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void printArray(int arr[]) {
    printf("Sorted Array: \n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL));

    printf("Generating random array...\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }

    printf("Sorting with bubble sort...\n");
    clock_t start = clock();
    bubbleSort(arr);
    clock_t end = clock();
    double timeBubbleSort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorting with insertion sort...\n");
    start = clock();
    insertionSort(arr);
    end = clock();
    double timeInsertionSort = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorting with selection sort...\n");
    start = clock();
    selectionSort(arr);
    end = clock();
    double timeSelectionSort = (double)(end - start) / CLOCKS_PER_SEC;

    printArray(arr);

    printf("Time taken for bubble sort: %f seconds\n", timeBubbleSort);
    printf("Time taken for insertion sort: %f seconds\n", timeInsertionSort);
    printf("Time taken for selection sort: %f seconds\n", timeSelectionSort);

    return 0;
}