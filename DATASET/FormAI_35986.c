//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each bucket
typedef struct {
    int count;
    int* values;
} Bucket;

// Define the bucket sort function
void bucket_sort(int arr[], int n, int num_buckets) {
    int i, j, k;
    int bucket_size = n / num_buckets;

    // Create an array of buckets
    Bucket* buckets = (Bucket*)malloc(sizeof(Bucket) * num_buckets);

    // Initialize each bucket
    for (i = 0; i < num_buckets; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * bucket_size);
    }

    // Distribute the elements of the array into the buckets
    for (i = 0; i < n; i++) {
        j = arr[i] / bucket_size;
        if (j >= num_buckets) {
            j = num_buckets - 1;
        }
        buckets[j].values[buckets[j].count++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < num_buckets; i++) {
        for (j = 1; j < buckets[i].count; j++) {
            k = j;
            while (k > 0 && buckets[i].values[k] < buckets[i].values[k - 1]) {
                int temp = buckets[i].values[k];
                buckets[i].values[k] = buckets[i].values[k - 1];
                buckets[i].values[k - 1] = temp;
                k--;
            }
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].values[j];
        }
    }

    // Free the memory allocated for the buckets
    for (i = 0; i < num_buckets; i++) {
        free(buckets[i].values);
    }
    free(buckets);
}

int main() {
    int arr[] = { 42, 17, 81, 33, 69, 24, 75, 10, 67 };
    int n = sizeof(arr) / sizeof(int);
    int num_buckets = 3;

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n, num_buckets);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}