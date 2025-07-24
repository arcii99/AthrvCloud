//FormAI DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

// Function to print the array
void printArray(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform selection sort
void selectionSort(int arr[]) {
    int min_idx;
    
    for (int i = 0; i < SIZE - 1; i++) {
        min_idx = i;
        
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
         
        // Swap the minimum element with the first unsorted element
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int arr[SIZE] = {12, 5, 10, 7, 8, 2};
    
    // Print the original array
    printf("Original array: ");
    printArray(arr);
    
    // Perform selection sort on the array
    selectionSort(arr);
    
    // Print the sorted array
    printf("\nSorted array: ");
    printArray(arr);
    
    return 0;
}