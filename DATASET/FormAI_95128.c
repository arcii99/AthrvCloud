//FormAI DATASET v1.0 Category: Sorting ; Style: modular
#include <stdio.h>

// function prototype for selection sort
void selectionSort(int arr[], int n);

// function prototype for insertion sort
void insertionSort(int arr[], int n);

// function prototype for bubble sort
void bubbleSort(int arr[], int n);

// function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    printf("Original Array: ");
    printArray(arr, n);
  
    selectionSort(arr, n);
    printf("Array after Selection Sort: ");
    printArray(arr, n);

    insertionSort(arr, n);
    printf("Array after Insertion Sort: ");
    printArray(arr, n);
  
    bubbleSort(arr, n);
    printf("Array after Bubble Sort: ");
    printArray(arr, n);

    return 0;
}

// function implementation for selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap the minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// function implementation for insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // move elements greater than key to the right of it
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// function implementation for bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap the elements that are not in order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}