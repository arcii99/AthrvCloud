//FormAI DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Define size of array
#define MAX_VALUE 100 // Maximum value of array elements

void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void quickSort(int arr[], int start, int end);

int main()
{
    int arr[SIZE]; // Declare array of size SIZE
    int i;

    srand(time(NULL)); // Initialize random number generator

    // Populate array with random numbers between 0 and MAX_VALUE
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    printf("Original Array:\n");
    printArray(arr, SIZE);

    bubbleSort(arr, SIZE);

    printf("\nSorted Array (Bubble Sort):\n");
    printArray(arr, SIZE);

    quickSort(arr, 0, SIZE - 1);

    printf("\nSorted Array (Quick Sort):\n");
    printArray(arr, SIZE);

    return 0;
}

void bubbleSort(int arr[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end) {
        return;
    }

    int pivot = arr[end];
    int i = start - 1;
    int j;

    for (j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap pivot with i+1
    int temp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = temp;

    quickSort(arr, start, i);
    quickSort(arr, i + 2, end);
}

void printArray(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}