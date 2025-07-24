//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the number of buckets
#define BUCKET_NUM 10

// Define a structure for each bucket
typedef struct bucket {
    int count;
    int* value;
} Bucket;

// Function to perform Bucket Sort
void bucketSort(int* arr, int size) {
    int i, j, k;
    Bucket buckets[BUCKET_NUM];
    int min = arr[0], max = arr[0], bucket_index;

    for (i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        } else if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Initialize each bucket with zero count and NULL value
    for (i = 0; i < BUCKET_NUM; ++i) {
        buckets[i].count = 0;
        buckets[i].value = NULL;
    }

    // Distribute the elements into the buckets
    for (i = 0; i < size; ++i) {
        bucket_index = ((double)(arr[i] - min) / (max - min + 1)) * BUCKET_NUM;
        buckets[bucket_index].value = (int*)realloc(buckets[bucket_index].value, ++buckets[bucket_index].count * sizeof(int));
        buckets[bucket_index].value[buckets[bucket_index].count - 1] = arr[i];
    }

    // Sort each bucket using Insertion Sort
    for (i = 0; i < BUCKET_NUM; ++i) {
        for (j = 1; j < buckets[i].count; ++j) {
            int temp = buckets[i].value[j];
            k = j - 1;
            while (k >= 0 && buckets[i].value[k] > temp) {
                buckets[i].value[k + 1] = buckets[i].value[k];
                --k;
            }
            buckets[i].value[k + 1] = temp;
        }
    }

    // Concatenate the elements to form the sorted array
    k = 0;
    for (i = 0; i < BUCKET_NUM; ++i) {
        for (j = 0; j < buckets[i].count; ++j) {
            arr[k++] = buckets[i].value[j];
        }
        free(buckets[i].value);
    }
}

// Function to print the array
void printArray(int* arr, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = {9, 3, 7, 1, 2, 8, 6, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);
    
    bucketSort(arr, size);

    printf("\nSorted Array: ");
    printArray(arr, size);
    
    return 0;
}