//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Structure to hold each bucket
typedef struct bucket {
    int size;
    int* elements;
} Bucket;

// Bucket sort implementation
void BucketSort(int array[], int size, int num_buckets) {
    // Find the maximum value in the array
    int maxVal = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    // Calculate the range of each bucket
    double range = (double)(maxVal + 1) / (double)num_buckets;

    // Create the buckets
    Bucket buckets[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].size = 0;
        buckets[i].elements = NULL;
    }

    // Assign each element to its corresponding bucket
    for (int i = 0; i < size; i++) {
        int bucketNum;
        if (array[i] == maxVal) {
            bucketNum = num_buckets - 1;
        } else {
            bucketNum = (int)(array[i] / range);
        }

        if (buckets[bucketNum].elements == NULL) {
            // First element in the bucket
            buckets[bucketNum].elements = (int*) malloc(sizeof(int));
            buckets[bucketNum].elements[0] = array[i];
            buckets[bucketNum].size = 1;
        } else {
            // Add to the end of the bucket
            buckets[bucketNum].elements = (int*) realloc(buckets[bucketNum].elements, sizeof(int) * (buckets[bucketNum].size + 1));
            buckets[bucketNum].elements[buckets[bucketNum].size] = array[i];
            buckets[bucketNum].size++;
        }
    }

    // Sort each individual bucket
    for (int i = 0; i < num_buckets; i++) {
        if (buckets[i].elements != NULL && buckets[i].size > 1) {
            int bucketSize = buckets[i].size;
            int* bucketArray = buckets[i].elements;

            // Perform insertion sort on the bucket
            for (int j = 1; j < bucketSize; j++) {
                int key = bucketArray[j];
                int k = j - 1;
                while (k >= 0 && bucketArray[k] > key) {
                    bucketArray[k + 1] = bucketArray[k];
                    k--;
                }
                bucketArray[k + 1] = key;
            }
        }
    }

    // Copy the elements back into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        if (buckets[i].elements != NULL) {
            for (int j = 0; j < buckets[i].size; j++) {
                array[index] = buckets[i].elements[j];
                index++;
            }
            free(buckets[i].elements);
        }
    }
}

// Test the implementation
int main() {
    int size = 20;
    int array[20] = {84, 33, 67, 21, 45, 99, 60, 27, 92, 12, 75, 51, 36, 71, 18, 4, 42, 81, 55, 38};

    // Print out the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    BucketSort(array, size, 5);

    // Print out the sorted array
    printf("Sorted array:   ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}