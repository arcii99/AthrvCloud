//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size)
{
    // Initialize buckets
    int buckets[BUCKET_SIZE][size];
    int bucket_counts[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        bucket_counts[i] = 0;
    }

    // Place elements into buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        buckets[bucket_index][bucket_counts[bucket_index]] = arr[i];
        bucket_counts[bucket_index]++;
    }

    // Sort buckets using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 1; j < bucket_counts[i]; j++) {
            int current = buckets[i][j];
            int k;
            for (k = j - 1; k >= 0 && buckets[i][k] > current; k--) {
                buckets[i][k + 1] = buckets[i][k];
            }
            buckets[i][k + 1] = current;
        }
    }

    // Merge buckets
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucket_counts[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main()
{
    int arr[] = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("After sorting: ");
    print_array(arr, size);

    return 0;
}