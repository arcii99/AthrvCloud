//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEFAULT_BUCKET_SIZE 10
#define DEFAULT_ARRAY_SIZE 50

typedef struct {
    int size;
    int *arr;
} Bucket;

Bucket **create_buckets(int bucket_size) {
    Bucket **buckets = malloc(bucket_size * sizeof(Bucket*));
    for (int i = 0; i < bucket_size; i++) {
        buckets[i] = malloc(sizeof(Bucket));
        buckets[i]->size = 0;
        buckets[i]->arr = malloc(DEFAULT_ARRAY_SIZE * sizeof(int));
    }
    return buckets;
}

void free_buckets(Bucket **buckets, int bucket_size) {
    for (int i = 0; i < bucket_size; i++) {
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_buckets(Bucket **buckets, int bucket_size) {
    for (int i = 0; i < bucket_size; i++) {
        Bucket *bucket = buckets[i];
        printf("Bucket %d (size %d): ", i, bucket->size);
        print_array(bucket->arr, bucket->size);
    }
}

void sort(int *arr, int size, int max_value) {
    int bucket_size = DEFAULT_BUCKET_SIZE;
    Bucket **buckets = create_buckets(bucket_size);

    // placing values in buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / max_value * (bucket_size - 1);
        Bucket *bucket = buckets[bucket_index];
        bucket->arr[bucket->size++] = arr[i];
    }

    // sorting each individual bucket
    for (int i = 0; i < bucket_size; i++) {
        Bucket *bucket = buckets[i];
        for (int j = 0; j < bucket->size - 1; j++) {
            for (int k = j + 1; k < bucket->size; k++) {
                if (bucket->arr[j] > bucket->arr[k]) {
                    int temp = bucket->arr[j];
                    bucket->arr[j] = bucket->arr[k];
                    bucket->arr[k] = temp;
                }
            }
        }
    }

    // concatenating sorted buckets
    int index = 0;
    for (int i = 0; i < bucket_size; i++) {
        Bucket *bucket = buckets[i];
        for (int j = 0; j < bucket->size; j++) {
            arr[index++] = bucket->arr[j];
        }
    }

    free_buckets(buckets, bucket_size);
}

int main() {
    int array[] = {8, 3, 5, 1, 9, 2, 4, 7, 6, 0};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Before sorting: ");
    print_array(array, size);

    // getting maximum value in array to use for bucket placement
    int max_value = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    sort(array, size, max_value);

    printf("After sorting: ");
    print_array(array, size);

    return 0;
}