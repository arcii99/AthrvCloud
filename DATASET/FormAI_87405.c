//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void print_array(int *arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int max_val = arr[0];
    for (int i=1; i<size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_count = (max_val / BUCKET_SIZE) + 1;
    int **buckets = malloc(bucket_count * sizeof(int *));
    for (int i=0; i<bucket_count; i++) {
        buckets[i] = malloc(BUCKET_SIZE * sizeof(int));
    }

    for (int i=0; i<bucket_count; i++) {
        int bucket_index = 0;
        for (int j=0; j<size; j++) {
            if ((arr[j] / BUCKET_SIZE) == i) {
                buckets[i][bucket_index++] = arr[j];
            }
        }

        // Sort the bucket
        for (int j=1; j<bucket_index; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = key;
        }
    }

    // Merge the buckets back into the original array
    int index = 0;
    for (int i=0; i<bucket_count; i++) {
        for (int j=0; j<BUCKET_SIZE; j++) {
            if (buckets[i][j] != 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free the memory used by the buckets
    for (int i=0; i<bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = {39, 60, 25, 68, 40, 86, 54, 7, 70, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}