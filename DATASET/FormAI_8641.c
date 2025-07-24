//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to initialize an array with random values
void init_array(int arr[], int size) {
    srand(time(NULL)); // Seed the random number generator
    for(int i=0; i<size; i++) {
        arr[i] = rand() % size; // Assign a random value between 0 and size-1
    }
}

// Function to perform bubble sort on an array
void bubble_sort(int arr[], int size) {
    int temp;
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) { // If adjacent elements are in the wrong order
                // Swap them
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    init_array(arr, ARRAY_SIZE);
    printf("Initial array:\n");
    for(int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSorting array...\n\n");
    bubble_sort(arr, ARRAY_SIZE);
    printf("Sorted array:\n");
    for(int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}