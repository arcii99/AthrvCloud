//FormAI DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10 // define the size of the array

void bubbleSort(int arr[], int n); // bubble sort function prototype

int main() {
    int arr[ARRAY_SIZE]; // declare an array of size ARRAY_SIZE
    int i;

    srand(time(NULL)); // initialize random seed

    // populate the array with random integers between 0 and 100
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 101; // generate a random integer between 0 and 100
    }

    printf("Original Array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]); // print the original array
    }
    printf("\n");

    bubbleSort(arr, ARRAY_SIZE); // sort the array

    printf("Sorted Array:\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]); // print the sorted array
    }
    printf("\n");

    return 0;
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j + 1] using temp variable
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}