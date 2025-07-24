//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

// Function to perform Bucket Sort
void bucketSort(int arr[], int n) {
    int i, j;
    int *count = calloc(n, sizeof(int)); // Initially all elements of count are 0
    
    // Increment the values in count array based on the values in input array
    for(i=0; i<n; i++) {
        count[arr[i]]++;
    }
    
    // Copy the sorted elements into the original array
    for(i=0, j=0; i<n; i++) {
        while(count[i] > 0) {
            arr[j++] = i;
            count[i]--;
        }
    }
    free(count); // Free the memory allocated to count array
}

// Function to print the array
void printArray(int arr[], int n) {
    printf("Sorted array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test the Bucket Sort function
int main() {
    int arr[] = {1, 9, 2, 5, 7, 3, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printArray(arr, n);
    return 0;
}