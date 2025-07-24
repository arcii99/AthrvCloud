//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_BUCKETS 10

void bucket_sort(int arr[], int n) {
    int i, j, k, max_val = INT_MIN;
    int buckets[NUM_BUCKETS][n];

    // Find the maximum element in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Initialize all buckets to 0
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < n; j++) {
            buckets[i][j] = 0;
        }
    }

    // Add elements to the appropriate buckets
    for (i = 0; i < n; i++) {
        int bucket_num = (arr[i] * NUM_BUCKETS) / (max_val + 1);
        for (j = 0; j < n; j++) {
            if (buckets[bucket_num][j] == 0) {
                buckets[bucket_num][j] = arr[i];
                break;
            }
        }
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 1; j < n && buckets[i][j] != 0; j++) {
            int key = buckets[i][j];
            k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Copy the elements back to the original array
    for (i = 0, j = 0; i < NUM_BUCKETS; i++) {
        for (k = 0; k < n && buckets[i][k] != 0; k++) {
            arr[j++] = buckets[i][k];
        }
    }
}

int main() {
    int arr[] = {8, 2, 6, 4, 1, 9, 5, 3, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}