//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n) {
    // Find maximum element in the array
    int max_value = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    
    // Create buckets and initialize them to 0
    int *buckets = calloc(max_value + 1, sizeof(int));
    
    // Add elements to the appropriate bucket
    for (int i = 0; i < n; i++) {
        buckets[array[i]]++;
    }
    
    // Sort each bucket using insertion sort
    for (int i = 0, j = 0; i <= max_value; i++) {
        while (buckets[i] > 0) {
            array[j++] = i;
            buckets[i]--;
        }
    }
    
    // Free dynamically allocated memory
    free(buckets);
}

int main() {
    // Initialize an array and its length
    int array[] = {5, 8, 1, 3, 6, 2, 7, 4};
    int n = sizeof(array) / sizeof(array[0]);
    
    // Perform bucket sort on the array
    bucketSort(array, n);
    
    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}