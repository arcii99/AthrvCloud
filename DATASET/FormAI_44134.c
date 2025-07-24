//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bucket Sort implementation
void bucketSort(int arr[], int n) {
    int i, j;
    int max_val = arr[0];
    for (i = 1; i < n; i++) {
        max_val = (max_val < arr[i]) ? arr[i] : max_val;
    }

    int bucket_size = ((max_val / 10) + 1);
    int buckets[bucket_size][n];
    int bucket_index[bucket_size];

    for (i = 0; i < bucket_size; i++) {
        bucket_index[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int bucket_num = arr[i] / 10;
        buckets[bucket_num][bucket_index[bucket_num]] = arr[i];
        bucket_index[bucket_num]++;
    }

    for (i=0; i<bucket_size; i++) {
        for (j=1; j<bucket_index[i]; j++) {
            int k = j;
            while (k > 0 && buckets[i][k-1] > buckets[i][k]) {
                int temp = buckets[i][k];
                buckets[i][k] = buckets[i][k-1];
                buckets[i][k-1] = temp;
                k--;
            }
        }
    }

    int index = 0;
    for (i = 0; i < bucket_size; i++) {
        for (j = 0; j < bucket_index[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];

    // Generate random numbers and fill array
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array: ");
    printArray(arr, ARRAY_SIZE);

    bucketSort(arr, ARRAY_SIZE);

    printf("Sorted array: ");
    printArray(arr, ARRAY_SIZE);

    return 0;
}