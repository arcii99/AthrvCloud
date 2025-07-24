//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

/* Bucket structure definition */
struct Bucket {
    int size;
    int *values;
};

/* Function to insert a value into the bucket */
void insertValue(struct Bucket *bucket, int value) {
    int i;

    /* Allocate memory for a new value */
    bucket->values = realloc(bucket->values, (bucket->size + 1) * sizeof(int));

    if (bucket->values == NULL) {
        printf("Allocation error.\n");
        exit(1);
    }

    /* Insert the value at the end of the bucket */
    bucket->values[bucket->size] = value;
    bucket->size++;

    /* Sort the values in the bucket */
    for (i = 0; i < bucket->size - 1; i++) {
        int j, temp;

        for (j = i + 1; j < bucket->size; j++) {
            if (bucket->values[i] > bucket->values[j]) {
                temp = bucket->values[i];
                bucket->values[i] = bucket->values[j];
                bucket->values[j] = temp;
            }
        }
    }
}

/* Bucket sort function */
void bucketSort(int *array, int size) {
    int i, j, minValue, maxValue;
    struct Bucket *buckets = NULL;

    /* Find the minimum and maximum values in the array */
    minValue = maxValue = array[0];

    for (i = 1; i < size; i++) {
        if (array[i] < minValue) {
            minValue = array[i];
        } else if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    /* Allocate memory for the buckets */
    buckets = calloc(BUCKET_SIZE, sizeof(struct Bucket));

    if (buckets == NULL) {
        printf("Allocation error.\n");
        exit(1);
    }

    /* Distribute the values into buckets */
    for (i = 0; i < size; i++) {
        int bucketIndex = (int)((array[i] - minValue) / ((float)(maxValue - minValue) / (BUCKET_SIZE - 1)));

        insertValue(&buckets[bucketIndex], array[i]);
    }

    /* Concatenate the values in the buckets into the array */
    for (i = 0, j = 0; i < BUCKET_SIZE; i++) {
        int k;

        for (k = 0; k < buckets[i].size; k++) {
            array[j] = buckets[i].values[k];
            j++;
        }

        /* Free the memory used by this bucket */
        free(buckets[i].values);
    }

    /* Free the memory used by the buckets */
    free(buckets);
}

/* Main function */
int main() {
    int array[] = { 5, 9, 3, 1, 8, 6, 4, 2, 7 };
    int size = sizeof(array) / sizeof(int);
    int i;

    printf("Original array: ");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    /* Sort the array using bucket sort */
    bucketSort(array, size);

    printf("\nSorted array: ");

    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}