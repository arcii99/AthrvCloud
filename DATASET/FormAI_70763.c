//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100000

// A function for swapping two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A function for performing heapsort algorithm on an array of integers
void heapsort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
  
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A function to heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
  
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Allocate memory for the array
    int *arr = (int *)malloc(MAX_SIZE * sizeof(int));
    
    // Populate the array with random integers
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 10000;
    }
    
    // Perform heapsort algorithm on the array
    heapsort(arr, MAX_SIZE);
    
    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Free the memory used for the array
    free(arr);
    
    return 0;
}