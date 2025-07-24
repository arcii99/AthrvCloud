//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n, int num_buckets) {
    int i, j;
    // Create buckets
    int **buckets = (int **)malloc(num_buckets * sizeof(int *));
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    // Distribute array elements into buckets based on their range
    int max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    float range = (float)(max_val + 1) / num_buckets;
    for (i = 0; i < n; i++) {
        int bucket_index = (int)(arr[i] / range);
        buckets[bucket_index][i] = arr[i];
    }
    
    // Sort individual buckets using Insertion Sort
    for (i = 0; i < num_buckets; i++) {
        for (j = 1; j < n; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = key;
        }
    }

    // Merge all the buckets into a single array
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int arr[] = {54, 46, 83, 66, 95, 92, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n, 5);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}