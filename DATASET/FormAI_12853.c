//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the bucket sort function 
void bucketSort(float arr[], int n) {
    // Create empty buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; ++i) {
        count[i] = 0;
    }

    // Add elements into the buckets
    for (i = 0; i < n; ++i) {
        ++count[(int) arr[i]];
    }

    // Sort the elements within each bucket
    for (i = 0; i < n; ++i) {
        for (j = 0; j < count[i]; ++j) {
            printf("%f ", (float)i);
        }
    }
}

// Main function
int main(int argc, char const *argv[]) {
    float arr[] = {2.4, 1.4, 3.5, 0.5, 2.7, 2.9};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    for(int i = 0; i < n; ++i) {
        printf("%f ", arr[i]);
    }
    printf("\nSorted array: ");
    bucketSort(arr, n);
    return 0;
}