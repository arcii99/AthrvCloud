//FormAI DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000 // Size of the array for benchmarking purposes

/* Function to generate random integers between 1 and 100 */
int randomInt() {
    return (rand() % 100 + 1);
}

/* Function to fill an array with random integers */
void fillArray(int arr[]) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = randomInt();
    }
}

/* Function to print the contents of an array */
void printArray(int arr[]) {
    int i;
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* Function to perform bubble sort on an array */
void bubbleSort(int arr[]) {
    int i, j, temp;
    for (i = 0; i < (ARRAY_SIZE - 1); i++) {
        for (j = 0; j < (ARRAY_SIZE - i - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Function to perform selection sort on an array */
void selectionSort(int arr[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < (ARRAY_SIZE - 1); i++) {
        min_idx = i;
        for (j = i + 1; j < ARRAY_SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
   
    // Create an array
    int arr[ARRAY_SIZE];
    
    // Fill the array with random integers
    fillArray(arr);
    
    // Print the original array
    printf("Original array:\n");
    printArray(arr);
    
    // Start the timer for bubble sort
    clock_t start_bubble_sort = clock();

    // Perform bubble sort on the array
    bubbleSort(arr);
    
    // Stop the timer for bubble sort
    clock_t end_bubble_sort = clock();
    
    // Print the sorted array
    printf("Array after bubble sort:\n");
    printArray(arr);
    
    // Calculate the time taken for bubble sort
    double time_taken_bubble_sort = (double)(end_bubble_sort - start_bubble_sort) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %f seconds\n", time_taken_bubble_sort);
    
    // Fill the array with random integers again
    fillArray(arr);
    
    // Print the original array
    printf("Original array:\n");
    printArray(arr);
    
    // Start the timer for selection sort
    clock_t start_selection_sort = clock();

    // Perform selection sort on the array
    selectionSort(arr);
    
    // Stop the timer for selection sort
    clock_t end_selection_sort = clock();
    
    // Print the sorted array
    printf("Array after selection sort:\n");
    printArray(arr);
    
    // Calculate the time taken for selection sort
    double time_taken_selection_sort = (double)(end_selection_sort - start_selection_sort) / CLOCKS_PER_SEC;
    printf("Time taken for selection sort: %f seconds\n", time_taken_selection_sort);
    
    return 0;
}