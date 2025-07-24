//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int n) {
    // Create buckets based on the range of values in the array
    int max_val = array[0];
    int min_val = array[0];

    for (int i = 1; i < n; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }

    int bucket_count = (max_val - min_val) / 10 + 1;
    int* buckets[bucket_count];
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = NULL;
    }

    // Distribute array elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (array[i] - min_val) / 10;
        
        // If a bucket is empty, create a new node
        if (buckets[bucket_index] == NULL) {
            buckets[bucket_index] = malloc(sizeof(int));
            *buckets[bucket_index] = array[i];
        }
        // Otherwise, insert the element into the last position of the bucket
        else {
            int* current = buckets[bucket_index];
            while (*current != -1) {
                if (*(current+1) == -1) {
                    *(current+1) = array[i];
                    break;
                }
                current++;
            }
        }
    }

    // Sort the elements within each bucket and store them back in the array
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        if (buckets[i] != NULL) {
            int* current = buckets[i];
            while (*current != -1) {
                array[index] = *current;
                current++;
                index++;
            }
        }
    }

    // Free the memory used by the buckets
    for (int i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
}

int main() {
    int array[] = {33, 11, 45, 67, 88, 26, 98, 55, 5, 76};
    int n = sizeof(array) / sizeof(int);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bucket_sort(array, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}