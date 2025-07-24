//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void selectionSort(int arr[], int size) {
    int minIndex;
    for (int i = 0; i < size-1; i++) {
        minIndex = i;
        for (int j = i+1; j < size; j++) {
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
    int arr[ARRAY_SIZE];
    printf("Unsorted array: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
    printArray(arr, ARRAY_SIZE);
    selectionSort(arr, ARRAY_SIZE);
    printf("Sorted array: ");
    printArray(arr, ARRAY_SIZE);
    return 0;
}