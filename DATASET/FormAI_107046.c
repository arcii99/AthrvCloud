//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
// Welcome to the Bucket Sort Implementation program!
// This program takes an array of integers and sorts them using the Bucket Sort algorithm.
// Let's get started!

#include <stdio.h>
#include <stdlib.h>

// Define constants for the program
#define SIZE 10    // Size of the array
#define BUCKET_SIZE 5   // Number of buckets

// Function to sort the array using the Bucket Sort algorithm
void bucket_sort(int arr[], int n) {
    int i,j,k;
    int bucket[BUCKET_SIZE];

    // Initialize all the buckets to 0
    for(i=0; i<BUCKET_SIZE; i++) {
        bucket[i] = 0;
    }

    // Count the number of elements in each bucket
    for(i=0; i<n; i++) {
        bucket[arr[i]/BUCKET_SIZE]++;
    }

    // Sort the individual buckets using Insertion Sort
    for(i=0; i<BUCKET_SIZE; i++) {
        for(j=0; j<bucket[i]; j++) {
            // Find the correct position for the element in the sorted array
            for(k=j+1; k<bucket[i]; k++) {
                if(arr[i*BUCKET_SIZE+j] > arr[i*BUCKET_SIZE+k]) {
                    int temp = arr[i*BUCKET_SIZE+j];
                    arr[i*BUCKET_SIZE+j] = arr[i*BUCKET_SIZE+k];
                    arr[i*BUCKET_SIZE+k] = temp;
                }
            }
        }
    }
}

int main() {
    // Create an array of integers
    int arr[SIZE] = {23, 42, 12, 8, 55, 67, 90, 15, 26, 75};

    // Print the unsorted array
    printf("Unsorted array: ");
    for(int i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // Sort the array using Bucket Sort
    bucket_sort(arr, SIZE);

    // Print the sorted array
    printf("\nSorted array: ");
    for(int i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}