//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int min_val = arr[0], max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_count = (max_val - min_val) / BUCKET_SIZE + 1; // Determine bucket count

    int** buckets = (int**)malloc(bucket_count * sizeof(int*)); // Allocate memory for each bucket
    for (i = 0; i < bucket_count; i++) {
        buckets[i] = (int*)malloc(BUCKET_SIZE * sizeof(int));
    }

    int* bucket_lengths = (int*)calloc(bucket_count, sizeof(int)); // Initialize each bucket length to zero

    for (i = 0; i < n; i++) { // Distribute values into buckets
        int bucket_index = (arr[i] - min_val) / BUCKET_SIZE;
        if (bucket_lengths[bucket_index] == BUCKET_SIZE) { // If a bucket is full, resize its memory
            buckets[bucket_index] = (int*)realloc(buckets[bucket_index], 2 * BUCKET_SIZE * sizeof(int));
        }
        buckets[bucket_index][bucket_lengths[bucket_index]] = arr[i];
        bucket_lengths[bucket_index]++;
    }

    k = 0;
    for (i = 0; i < bucket_count; i++) { // Sort each bucket
        for (j = 1; j < bucket_lengths[i]; j++) {
            int temp = buckets[i][j];
            k = j - 1;
            while (k >= 0 && buckets[i][k] > temp) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }

    k = 0;
    for (i = 0; i < bucket_count; i++) { // Merge all buckets into original array
        for (j = 0; j < bucket_lengths[i]; j++) {
          arr[k] = buckets[i][j];
          k++;
        }
        free(buckets[i]); // Free each bucket
    }
    free(buckets); // Free the array of buckets
    free(bucket_lengths); // Free the array of bucket lengths
}

int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n); // Perform bucket sort

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}