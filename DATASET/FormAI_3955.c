//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// This function sorts an array using the Bucket Sort algorithm
void bucket_sort(int arr[], int n, int bucket_size) {
    int i, j, k;
    int min_val = INT_MAX, max_val = INT_MIN;
    int num_buckets = 0;

    // Find the maximum and minimum values in the array
    for(i=0; i<n; i++) {
        if(arr[i] < min_val) {
            min_val = arr[i];
        }
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calculate the number of buckets needed
    num_buckets = (max_val - min_val) / bucket_size + 1;

    // Create the buckets
    int** buckets = (int**) malloc(num_buckets * sizeof(int*));
    for(i=0; i<num_buckets; i++) {
        buckets[i] = (int*) malloc(bucket_size * sizeof(int));
    }

    // Initialize each bucket to 0
    for(i=0; i<num_buckets; i++) {
        for(j=0; j<bucket_size; j++) {
            buckets[i][j] = 0;
        }
    }

    // Insert the values in the array into their respective buckets
    for(i=0; i<n; i++) {
        int bucket_index = (arr[i] - min_val) / bucket_size;
        for(j=0; j<bucket_size; j++) {
            if(buckets[bucket_index][j] == 0) {
                buckets[bucket_index][j] = arr[i];
                break;
            }
        }
    }

    // Sort each bucket using Insertion Sort
    for(i=0; i<num_buckets; i++) {
        for(j=1; j<bucket_size; j++) {
            int key = buckets[i][j];
            k = j - 1;
            while(k >= 0 && buckets[i][k] > key) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = key;
        }
    }

    // Concatenate the sorted buckets back into the original array
    k = 0;
    for(i=0; i<num_buckets; i++) {
        for(j=0; j<bucket_size; j++) {
            if(buckets[i][j] != 0) {
                arr[k++] = buckets[i][j];
            }
        }
    }

    // Free the memory used by the buckets
    for(i=0; i<num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// This function prints an array
void print_arr(int arr[], int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {56, 48, 88, 25, 37, 22, 90, 95, 81, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int bucket_size = 10;

    printf("Original array: ");
    print_arr(arr, n);

    bucket_sort(arr, n, bucket_size);
    printf("Sorted array: ");
    print_arr(arr, n);

    return 0;
}