//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define number of buckets
#define MAX_BUCKET 10

// Define range of numbers in input array
#define MAX_VALUE 100

// Function to sort individual buckets using insertion sort
void insertion_sort(int *bucket, int size) {
    int i, j, temp;
    for (i = 1; i < size; i++) {
        temp = bucket[i];
        j = i - 1;
        while (temp < bucket[j] && j >= 0) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = temp;
    }
}

// Function to perform bucket sort
void bucket_sort(int *arr, int size) {
    int i, j, index;
    int buckets[MAX_BUCKET][size];
    int bucket_sizes[MAX_BUCKET] = {0};

    // Distribute elements into buckets
    for (i = 0; i < size; i++) {
        index = arr[i] / (MAX_VALUE / MAX_BUCKET + 1);
        buckets[index][bucket_sizes[index]] = arr[i];
        bucket_sizes[index]++;
    }

    // Sort individual buckets using insertion sort
    for (i = 0; i < MAX_BUCKET; i++) {
        if (bucket_sizes[i] > 0) {
            insertion_sort(buckets[i], bucket_sizes[i]);
        }
    }

    // Merge the sorted buckets back into the original array
    index = 0;
    for (i = 0; i < MAX_BUCKET; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

// Function to print array
void print_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {23, 56, 12, 76, 34, 89, 100, 45, 67, 21};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    print_array(arr, size);
    bucket_sort(arr, size);
    printf("Sorted array: ");
    print_array(arr, size);
    return 0;
}