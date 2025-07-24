//FormAI DATASET v1.0 Category: Sorting ; Style: retro
// Retro C Sorting Program
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100 // Define the size of the array

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
    printf("Retro C Sorting Program\n");
    srand(time(NULL));
    int array[ARRAY_SIZE];

    // Fill the array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Perform Bubble Sort and print the sorted array
    printf("\nBubble Sort:\n");
    bubbleSort(array, ARRAY_SIZE);
    printArray(array, ARRAY_SIZE);

    // Perform Selection Sort and print the sorted array
    printf("\nSelection Sort:\n");
    selectionSort(array, ARRAY_SIZE);
    printArray(array, ARRAY_SIZE);

    // Perform Insertion Sort and print the sorted array
    printf("\nInsertion Sort:\n");
    insertionSort(array, ARRAY_SIZE);
    printArray(array, ARRAY_SIZE);

    return 0;
}

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int temp, minIndex;
    for (int i = 0; i < n-1; i++) {
        minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the elements
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}