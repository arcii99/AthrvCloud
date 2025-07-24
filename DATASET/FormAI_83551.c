//FormAI DATASET v1.0 Category: Benchmarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void fillArray(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

void bubbleSort(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *arr, int size) {
    int j, temp;
    for (int i = 1; i < size; i++) {
        j = i - 1;
        while (j >= 0 && arr[j] > arr[i]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[i];
    }
}

void selectionSort(int *arr, int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[ARRAY_SIZE];

    fillArray(arr, ARRAY_SIZE);

    clock_t start = clock();
    bubbleSort(arr, ARRAY_SIZE);
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort time taken: %f seconds\n", elapsed_time);

    fillArray(arr, ARRAY_SIZE);

    start = clock();
    insertionSort(arr, ARRAY_SIZE);
    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort time taken: %f seconds\n", elapsed_time);

    fillArray(arr, ARRAY_SIZE);

    start = clock();
    selectionSort(arr, ARRAY_SIZE);
    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Selection sort time taken: %f seconds\n", elapsed_time);

    return 0;
}