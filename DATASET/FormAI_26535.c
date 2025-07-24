//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void fillArray(int* arr, int size);
void printArray(int* arr, int size);
void bubbleSort(int* arr, int size);
void insertionSort(int* arr, int size);
void quickSort(int* arr, int left, int right);
void mergeSort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);

int main() {
    int arr[SIZE];

    // fill array with random integers
    fillArray(arr, SIZE);

    printf("Array before sorting:\n");
    printArray(arr, SIZE);

    // benchmark bubble sort
    clock_t start = clock();
    bubbleSort(arr, SIZE);
    clock_t end = clock();
    double timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nBubble sort took %.6f seconds.\n", timeElapsed);

    // refill array with random integers
    fillArray(arr, SIZE);

    // benchmark insertion sort
    start = clock();
    insertionSort(arr, SIZE);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nInsertion sort took %.6f seconds.\n", timeElapsed);

    // refill array with random integers
    fillArray(arr, SIZE);

    // benchmark quick sort
    start = clock();
    quickSort(arr, 0, SIZE-1);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nQuick sort took %.6f seconds.\n", timeElapsed);

    // refill array with random integers
    fillArray(arr, SIZE);

    // benchmark merge sort
    start = clock();
    mergeSort(arr, 0, SIZE-1);
    end = clock();
    timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nMerge sort took %.6f seconds.\n", timeElapsed);

    printf("\nArray after sorting:\n");
    printArray(arr, SIZE);

    return 0;
}

/**
 * Fills an array with random integers.
 * @param arr the array to fill
 * @param size the size of the array
 */
void fillArray(int* arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % SIZE;
    }
}

/**
 * Prints an array to the console.
 * @param arr the array to print
 * @param size the size of the array
 */
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

/**
 * Bubble sorts an array.
 * @param arr the array to sort
 * @param size the size of the array
 */
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/**
 * Insertion sorts an array.
 * @param arr the array to sort
 * @param size the size of the array
 */
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/**
 * Quick sorts an array.
 * @param arr the array to sort
 * @param left the index of the leftmost element
 * @param right the index of the rightmost element
 */
void quickSort(int* arr, int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left-1;
        for (int j = left; j <= right-1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[right];
        arr[right] = temp;

        quickSort(arr, left, i);
        quickSort(arr, i+2, right);
    }
}

/**
 * Merge sorts an array.
 * @param arr the array to sort
 * @param left the index of the leftmost element
 * @param right the index of the rightmost element
 */
void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * Merges two subarrays of an array.
 * @param arr the array to merge
 * @param left the index of the leftmost element
 * @param mid the index of the middle element
 * @param right the index of the rightmost element
 */
void merge(int* arr, int left, int mid, int right) {
    int leftSize = mid-left+1;
    int rightSize = right-mid;

    int leftArr[leftSize], rightArr[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left+i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid+1+j];
    }

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}