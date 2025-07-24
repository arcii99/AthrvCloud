//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 15
#define BUCKET_SIZE 5

void print_array(int arr[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void bucket_sort(int arr[], int size) {
    int i, j, k;

    // Determine the range of values in the array
    int min_value = arr[0];
    int max_value = arr[0];
    for(i = 1; i < size; i++) {
        if(arr[i] < min_value) {
            min_value = arr[i];
        }
        if(arr[i] > max_value) {
            max_value = arr[i];
        }
    }

    // Calculate the number of buckets required
    int bucket_count = (max_value - min_value) / BUCKET_SIZE + 1;

    // Create an array to hold the buckets
    int **buckets = (int **)malloc(sizeof(int *) * bucket_count);
    for(i = 0; i < bucket_count; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * BUCKET_SIZE);
    }

    // Initialize the buckets
    for(i = 0; i < bucket_count; i++) {
        for(j = 0; j < BUCKET_SIZE; j++) {
            buckets[i][j] = 0;
        }
    }

    // Fill the buckets with the array elements
    for(i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min_value) / BUCKET_SIZE;
        for(j = 0; j < BUCKET_SIZE; j++) {
            if(buckets[bucket_index][j] == 0) {
                buckets[bucket_index][j] = arr[i];
                break;
            }
        }
    }

    // Sort each bucket using bubble sort
    for(i = 0; i < bucket_count; i++) {
        for(j = 0; j < BUCKET_SIZE - 1; j++) {
            for(k = j + 1; k < BUCKET_SIZE; k++) {
                if(buckets[i][j] > buckets[i][k]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
            //printf("Bucket %d: ", i);
            //print_array(buckets[i], BUCKET_SIZE);
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for(i = 0; i < bucket_count; i++) {
        for(j = 0; j < BUCKET_SIZE; j++) {
            if(buckets[i][j] != 0) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }

    // Free the memory used for the buckets
    for(i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[ARRAY_SIZE] = {19, 4, 27, 8, 15, 2, 28, 4, 12, 11, 23, 2, 17, 1, 7};
    printf("Before sorting: ");
    print_array(arr, ARRAY_SIZE);
    bucket_sort(arr, ARRAY_SIZE);
    printf("After sorting: ");
    print_array(arr, ARRAY_SIZE);
    return 0;
}