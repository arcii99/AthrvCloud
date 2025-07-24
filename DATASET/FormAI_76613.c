//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
// Ada Lovelace style program for a Performance-Critical Component example in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array to be processed
#define SIZE 1000000

// Function to generate random numbers
int rand_num() {
    return rand() % 1000;
}

// Main function
int main() {
    int i, j, temp;
    clock_t start_time, end_time;
    double total_time;
    
    // Declare the array to be processed
    int arr[SIZE];
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate the random numbers and store them in the array
    for(i=0; i<SIZE; i++) {
        arr[i] = rand_num();
    }
    
    // Print the unsorted array
    printf("\nUnsorted array:\n");
    for(i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    // Sort the array using bubble sort algorithm
    start_time = clock();
    for(i=0; i<SIZE-1; i++) {
        for(j=0; j<SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end_time = clock();
    total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Print the sorted array and the total time taken
    printf("\n\nSorted array:\n");
    for(i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nTotal time taken: %f seconds\n\n", total_time);
    
    return 0;
}