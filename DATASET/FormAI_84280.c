//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Maximum number of elements that can be sorted using bucket sort
#define MAX_ELEMENTS 1000

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementation of bucket sort
void bucket_sort(int arr[], int n, int num_buckets) {
    int i, j;
    int max_val = arr[0];
    int min_val = arr[0];
    
    // Find the maximum and minimum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    // Create num_buckets empty buckets
    int **buckets = (int **) malloc(num_buckets * sizeof(int *));
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }
    
    // Distribute the elements of the array into buckets
    float range = (float) (max_val - min_val + 1) / (float) num_buckets;
    for (i = 0; i < n; i++) {
        int bucket_index = (int) ((arr[i] - min_val) / range);
        if (buckets[bucket_index] == NULL) {
            buckets[bucket_index] = (int *) malloc(MAX_ELEMENTS * sizeof(int));
            for (j = 0; j < MAX_ELEMENTS; j++) {
                buckets[bucket_index][j] = -1;
            }
        }
        int k = 0;
        while (buckets[bucket_index][k] != -1) {
            k++;
        }
        buckets[bucket_index][k] = arr[i];
    }
    
    // Sort the elements in each bucket
    for (i = 0; i < num_buckets; i++) {
        if (buckets[i] != NULL) {
            int bucket_size = 0;
            while (buckets[i][bucket_size] != -1) {
                bucket_size++;
            }
            for (j = 0; j < bucket_size - 1; j++) {
                int k;
                for (k = 0; k < bucket_size - j - 1; k++) {
                    if (buckets[i][k] > buckets[i][k+1]) {
                        swap(&buckets[i][k], &buckets[i][k+1]);
                    }
                }
            }
        }
    }
    
    // Copy the elements from the buckets back into the original array
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        if (buckets[i] != NULL) {
            int bucket_size = 0;
            while (buckets[i][bucket_size] != -1) {
                arr[index] = buckets[i][bucket_size];
                index++;
                bucket_size++;
            }
        }
    }
}

int main() {
    int arr[] = {29, 25, 3, 49, 37, 21, 43, 17, 11, 14, 9, 22, 39, 48, 33};
    int n = sizeof(arr)/sizeof(int);
    int num_buckets = 4;
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n, num_buckets);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}