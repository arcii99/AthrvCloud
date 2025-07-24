//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value of the array to be sorted
#define MAX_VALUE 100

// Function that implements Bucket Sort
void bucket_sort(int arr[], int n) {
    // Create the buckets with dynamic memory allocation
    int* bucket_arr[MAX_VALUE];
    
    // Initialize the buckets with 0
    for(int i=0; i<MAX_VALUE; i++) {
        bucket_arr[i] = calloc(n, sizeof(int));
    }
    
    // Initialize the index array with 0
    int index_arr[MAX_VALUE] = {0};
    
    // Distribute the array elements into buckets
    for(int i=0; i<n; i++) {
        int bucket_index = arr[i] / MAX_VALUE;
        bucket_arr[bucket_index][index_arr[bucket_index]++] = arr[i];
    }
    
    // Sort each bucket individually using Insertion Sort
    for(int i=0; i<MAX_VALUE; i++) {
        for(int j=1; j<index_arr[i]; j++) {
            int current = bucket_arr[i][j];
            int k = j-1;
            while(k >= 0 && bucket_arr[i][k] > current) {
                bucket_arr[i][k+1] = bucket_arr[i][k];
                k--;
            }
            bucket_arr[i][k+1] = current;
        }
    }
    
    // Concatenate all buckets into the original array
    int index = 0;
    for(int i=0; i<MAX_VALUE; i++) {
        for(int j=0; j<index_arr[i]; j++) {
            arr[index++] = bucket_arr[i][j];
        }
        // Free the memory allocated for each bucket
        free(bucket_arr[i]);
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    printf("[");
    for(int i=0; i<n; i++) {
        printf("%d", arr[i]);
        if(i < n-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Main function
int main() {
    int arr[] = {23, 4, 56, 12, 78, 95, 32, 68, 88, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before sorting: ");
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("After sorting: ");
    print_array(arr, n);
    return 0;
}