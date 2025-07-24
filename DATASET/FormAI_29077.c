//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to perform the bucket sort
void bucketSort(int array[], int n) {

    // Create an array of buckets
    int bucket[n];

    // Initialize all elements of the bucket array to 0
    for(int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Increment the count of each element in the input array
    for(int i = 0; i < n; i++) {
        bucket[array[i]]++;    
    }

    // Traverse the bucket array and sort each bucket using insertion sort
    for(int i = 0, j = 0; i < n; i++) {
        while(bucket[i] > 0) {
            array[j++] = i;
            bucket[i]--;
        }
    }
}

// Function to display the elements of an array
void display(int array[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Driver code to test the bucket sort function
int main() {
    int array[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Input array: ");
    display(array, n);
    bucketSort(array, n);
    printf("Sorted array: ");
    display(array, n);
    return 0;
}