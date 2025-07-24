//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10
#define BUCKET_SIZE 5

void bucketSort(int *arr, int n) {
    int i, j;
    int min_val = arr[0], max_val = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int num_buckets = ((max_val - min_val) / BUCKET_SIZE) + 1;

    int **buckets = (int **) malloc(num_buckets * sizeof(int *));
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = (int *) malloc(BUCKET_SIZE * sizeof(int));
    }

    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            buckets[i][j] = -1;
        }
    }

    int bucket_index;
    for (i = 0; i < n; i++) {
        bucket_index = (arr[i] - min_val) / BUCKET_SIZE;
        j = 0;
        while (buckets[bucket_index][j] != -1) {
            j++;
        }
        buckets[bucket_index][j] = arr[i];
    }

    for (i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i], BUCKET_SIZE);
    }

    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < BUCKET_SIZE; j++) {
            if (buckets[i][j] != -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (i = 0; i < num_buckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int i;
    int arr[ARRAY_SIZE] = {6, 3, 8, 4, 2, 9, 1, 7, 5, 0};

    printf("Original Array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, ARRAY_SIZE);

    printf("Sorted Array: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}