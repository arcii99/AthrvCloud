//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 1000
#define NUM_BUCKETS 10

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int min_val = arr[0];
    int max_val = arr[0];

    // Find minimum and maximum values in array
    for (i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Determine bucket size and number of buckets
    double range = (double)(max_val - min_val) / NUM_BUCKETS;
    int bucket_sizes[NUM_BUCKETS] = {0};
    int *buckets[NUM_BUCKETS];
    for (i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = malloc(sizeof(int) * ARRAY_SIZE);
    }

    // Assign elements to buckets
    for (i = 0; i < n; i++) {
        int bucket_idx = (int)((arr[i] - min_val) / range);
        buckets[bucket_idx][bucket_sizes[bucket_idx]++] = arr[i];
    }

    // Sort each bucket and re-assign to original array
    k = 0;
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            int temp = buckets[i][j];
            int l = j - 1;
            while (l >= 0 && buckets[i][l] > temp) {
                buckets[i][l + 1] = buckets[i][l];
                l--;
            }
            buckets[i][l + 1] = temp;
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }

}

int main() {
    int arr[ARRAY_SIZE];

    // fill array with random integers from 0 to 99
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, ARRAY_SIZE);

    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}