//FormAI DATASET v1.0 Category: Sorting ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // size of the array to be sorted

void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);

int main() {
    srand(time(NULL)); // initialize random seed
    int arr[SIZE]; // declare array to be sorted
    int i;

    // populate array with random numbers
    printf("Unsorted array: ");
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // generate random number between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // sort array using bubble sort
    printf("Sorting array using bubble sort...\n");
    bubbleSort(arr, SIZE);
    printf("Sorted array: ");
    printArray(arr, SIZE);
    printf("\n");

    // sort array using selection sort
    printf("Sorting array using selection sort...\n");
    selectionSort(arr, SIZE);
    printf("Sorted array: ");
    printArray(arr, SIZE);
    printf("\n");

    // sort array using insertion sort
    printf("Sorting array using insertion sort...\n");
    insertionSort(arr, SIZE);
    printf("Sorted array: ");
    printArray(arr, SIZE);
    printf("\n");

    return 0;
}

// print the contents of an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

// sort an array using bubble sort
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// sort an array using selection sort
void selectionSort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size-1; i++) {
        // find the minimum element in the unsorted array
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // swap elements
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// sort an array using insertion sort
void insertionSort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        // shift elements greater than key to the right
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}