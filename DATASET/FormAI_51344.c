//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: future-proof
#include <stdio.h>

#define LENGTH 10000000

// An array that will be used in the performance-critical component
int arr[LENGTH];

// A function that will be used to sort the elements in the array
void quicksort(int*, int, int);

int main() {
    
    // Fill the array with random integers between 0 and 99
    for (int i = 0; i < LENGTH; ++i) {
        arr[i] = rand() % 100;
    }
    
    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < LENGTH; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array using quicksort
    quicksort(arr, 0, LENGTH - 1);
    
    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < LENGTH; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j <= high - 1; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        int pi = i + 1;
        
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}