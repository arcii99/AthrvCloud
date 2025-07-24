//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int max_val = arr[0];

    // Find the maximum value in the given array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    // Create an array of buckets
    int *buckets[BUCKET_SIZE];

    // Initialize the buckets to be empty
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int*) malloc(sizeof(int) * n);
    }

    // Calculate the size of each bucket and place elements in them
    for (int i = 0; i < n; i++) {
        int bucket_index = ((float) arr[i]/max_val) * (BUCKET_SIZE - 1);
        int bucket_size = 0;
        while (buckets[bucket_index][bucket_size] != 0) {
            bucket_size++;
        }
        buckets[bucket_index][bucket_size] = arr[i];
    }

    // Sort the individual buckets using insertion sort
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 1; j < n; j++) {
            int val = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > val) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = val;
        }
    }

    // Merge the sorted buckets
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        int j = 0;
        while (buckets[i][j] != 0) {
            arr[index] = buckets[i][j];
            j++;
            index++;
        }
    }

    // Free the memory allocated for the buckets
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted Array: ");
    printArray(arr, 10);

    bucketSort(arr, 10);

    printf("Sorted Array: ");
    printArray(arr, 10);

    return 0;
}