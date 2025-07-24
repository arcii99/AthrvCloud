//FormAI DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10 // Define the size of the array we'll be sorting

/* This function takes in an integer array and its size, and prints the array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* This function takes in an integer array and its size, and sorts the array in ascending order using bubble sort */
void bubbleSort(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE]; // Declare an integer array
    
    /* Generate an array of random numbers */
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
    }
    
    /* Print the unsorted array */
    printf("Unsorted array:\n");
    printArray(arr, ARRAY_SIZE);
    
    /* Sort the array using bubble sort */
    bubbleSort(arr, ARRAY_SIZE);
    
    /* Print the sorted array */
    printf("Sorted array:\n");
    printArray(arr, ARRAY_SIZE);

    return 0; // Signal that the program has ended successfully
}