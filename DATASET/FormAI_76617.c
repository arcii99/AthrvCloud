//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value
#define MAX_VALUE 100

// Define the bucket structure
struct Bucket {
    int count;
    int* value;
};

// Function to implement bucket sort
void bucket_sort(int arr[], int size) {
    // Create an array of bucket structures
    struct Bucket buckets[MAX_VALUE];

    // Initialize each bucket with zero values
    for (int i = 0; i < MAX_VALUE; i++) {
        buckets[i].count = 0;
        buckets[i].value = NULL;
    }

    // Distribute the elements into their respective buckets
    for (int i = 0; i < size; i++) {
        struct Bucket* bucket = &buckets[arr[i]];
        bucket->count++;
        bucket->value = realloc(bucket->value, bucket->count * sizeof(int));
        bucket->value[bucket->count - 1] = arr[i];
    }

    // Sort each bucket individually using the insertion sort algorithm
    for (int i = 0; i < MAX_VALUE; i++) {
        struct Bucket* bucket = &buckets[i];
        for (int j = 1; j < bucket->count; j++) {
            int k = bucket->value[j];
            int l = j - 1;
            while (l >= 0 && bucket->value[l] > k) {
                bucket->value[l + 1] = bucket->value[l];
                l--;
            }
            bucket->value[l + 1] = k;
        }
    }

    // Concatenate the sorted elements from each bucket
    int i = 0;
    for (int j = 0; j < MAX_VALUE; j++) {
        struct Bucket* bucket = &buckets[j];
        for (int k = 0; k < bucket->count; k++) {
            arr[i] = bucket->value[k];
            i++;
        }
        free(bucket->value);
    }
}

// Driver code to test the function
int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int size = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}