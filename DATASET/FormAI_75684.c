//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>

void bucketSort(int arr[], int n) {
    int i;
    int min_val = arr[0];
    int max_val = arr[0];

    // Find the minimum and maximum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Calculate the number of buckets required
    int num_buckets = (max_val - min_val)/10 + 1;

    // Create the buckets
    int buckets[num_buckets][n];
    int bucket_size[num_buckets];

    for (i = 0; i < num_buckets; i++) {
        bucket_size[i] = 0;
    }

    // Distribute the elements of the array into the buckets
    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_val)/10;
        buckets[bucket_index][bucket_size[bucket_index]] = arr[i];
        bucket_size[bucket_index]++;
    }

    // Sort each bucket individually
    for (i = 0; i < num_buckets; i++) {
        int j;
        for (j = 0; j < bucket_size[i]; j++) {
            int k;
            int temp = buckets[i][j];

            // Insertion sort on the current bucket
            for (k = j-1; k >= 0 && buckets[i][k] > temp; k--) {
                buckets[i][k+1] = buckets[i][k];
            }
            buckets[i][k+1] = temp;
        }
    }

    // Concatenate the sorted buckets
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        int j;
        for (j = 0; j < bucket_size[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[] = {65, 8, 34, 10, 16, 22, 11, 1, 7, 13};
    int n = sizeof(arr)/sizeof(int);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}