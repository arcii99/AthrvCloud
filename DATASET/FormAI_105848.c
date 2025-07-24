//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#define NUM_BUCKETS 10

void bucket_sort(int* arr, int n, int max_val) {
    int i, j;
    int bucket[NUM_BUCKETS];

    for (i = 0; i < NUM_BUCKETS; ++i) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; ++i) {
        ++bucket[arr[i] * NUM_BUCKETS / max_val];
    }

    for (i = 0, j = 0; i < NUM_BUCKETS; ++i) {
        int k;
        for (k = bucket[i]; k > 0; --k) {
            arr[j++] = i * max_val / NUM_BUCKETS;
        }
    }
}

int main() {
    int arr[] = {3, 6, 1, 8, 9, 2, 7, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find max value in array
    int max_val = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    bucket_sort(arr, n, max_val);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}