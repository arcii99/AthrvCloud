//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the number of buckets to use 
#define NUM_BUCKETS 10

// Define the function that performs bucket sort
void bucketSort(int arr[], int n) 
{ 
    int i, j;
    // Create an array of buckets
    int buckets[NUM_BUCKETS]; 
  
    // Initialize all buckets to zero
    for (i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = 0; 
    }
    
    // Count the number of times each element appears in the array
    for (i = 0; i < n; i++) {
        (buckets[arr[i]])++; 
    }
    
    // Sort the array using the bucket counts
    for (i = 0, j = 0; j < NUM_BUCKETS; j++) {
        while(buckets[j] > 0) {
            arr[i++] = j; // Append the element to the sorted array
            (buckets[j])--; // Decrement the count for that element
        } 
    } 
} 

int main() 
{ 
    int arr[] = {23, 45, 12, 78, 90, 34, 56, 34, 99, 8, 11}; 
    int i, n = sizeof(arr)/sizeof(arr[0]); 
    bucketSort(arr, n); 
    printf("Sorted array:\n"); 
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
    return 0; 
}