//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort on an array
void bucketSort(int arr[], int n) {
    // Find the maximum value in the array
    int max = findMax(arr, n);
    
    // Create buckets and initialize them with 0
    int *bucket = (int*) calloc(max+1, sizeof(int));
    if(bucket == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    
    // Add elements to the respective bucket based on their value
    for(int i=0; i<n; i++) {
        bucket[arr[i]]++;
    }
    
    // Traverse each bucket and place the elements in the original array
    int index = 0;
    for(int i=0; i<=max; i++) {
        while(bucket[i] > 0) {
            arr[index++] = i;
            bucket[i]--;
        }
    }
    
    // Free the dynamically allocated memory
    free(bucket);
}

int main() {
    // Example array to be sorted using bucket sort
    int arr[] = {3, 1, 6, 9, 2, 4, 7, 5, 10, 8};
    
    // Size of the array
    int n = sizeof(arr)/sizeof(int);
    
    // Print the unsorted array
    printf("Unsorted array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Sort the array using bucket sort
    bucketSort(arr, n);
    
    // Print the sorted array
    printf("\nSorted array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}