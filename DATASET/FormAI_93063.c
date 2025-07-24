//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

// Bucket struct with dynamic array and count
struct bucket {
    int* arr;
    int count;
};

// Helper function to create new bucket
struct bucket* create_bucket(int count) {
    struct bucket* bkt = malloc(sizeof(struct bucket));
    bkt->arr = malloc(count * sizeof(int));
    bkt->count = 0;
    return bkt;
}

// Bucket sort function
void bucket_sort(int* arr, int size) {
    if (size <= 0)
        return;

    // Find maximum value in array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create buckets
    struct bucket** buckets = malloc(max * sizeof(struct bucket*));
    for (int i = 0; i < max; i++) {
        buckets[i] = create_bucket(size);
    }

    // Add elements to buckets
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - 1);
        buckets[index]->arr[buckets[index]->count++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < max; i++) {
        int j = 0;
        while (j < buckets[i]->count) {
            int min = j;
            for (int k = j + 1; k < buckets[i]->count; k++) {
                if (buckets[i]->arr[k] < buckets[i]->arr[min])
                    min = k;
            }
            int temp = buckets[i]->arr[j];
            buckets[i]->arr[j] = buckets[i]->arr[min];
            buckets[i]->arr[min] = temp;
            j++;
        }
    }

    // Reconstruct array
    int index = 0;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < buckets[i]->count; j++) {
            arr[index++] = buckets[i]->arr[j];
        }
    }

    // Free memory
    for (int i = 0; i < max; i++) {
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[ARRAY_SIZE] = { 8, 4, 2, 6, 7, 1, 3, 6, 9, 5 };
    printf("Before Sorting: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, ARRAY_SIZE);

    printf("After Sorting: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}