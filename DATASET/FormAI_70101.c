//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10
#define MAX_VALUE 100

void printArray(int* array, int size);
void initializeArrayWithRandomValues(int* array, int size);
void bubbleSort(int* array, int size);
int binarySearch(int* array, int left, int right, int searchValue);

int main() {

    int originalArray[MAX_ITEMS];
    int sortedArray[MAX_ITEMS];

    initializeArrayWithRandomValues(originalArray, MAX_ITEMS);

    printf("Original array:\n");
    printArray(originalArray, MAX_ITEMS);

    bubbleSort(originalArray, MAX_ITEMS);

    printf("\nSorted array:\n");
    printArray(originalArray, MAX_ITEMS);

    int searchValue = rand() % MAX_VALUE;
    printf("\nSearching for value %d\n", searchValue);
    int index = binarySearch(originalArray, 0, MAX_ITEMS - 1, searchValue);

    if (index != -1) {
        printf("Value %d found at index %d\n", searchValue, index);
    }
    else {
        printf("Value %d not found in the array\n", searchValue);
    }

    return 0;
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void initializeArrayWithRandomValues(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }
}

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int* array, int left, int right, int searchValue) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (array[mid] == searchValue) {
            return mid;
        }

        if (array[mid] > searchValue) {
            return binarySearch(array, left, mid - 1, searchValue);
        }

        return binarySearch(array, mid + 1, right, searchValue);
    }

    return -1;
}