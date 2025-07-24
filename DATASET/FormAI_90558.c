//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct Bucket {
    int value;
    struct Bucket* next;
} bucket;

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int* arr, int size) {
    bucket** buckets = (bucket**)malloc(size * sizeof(bucket*));
    for (int i = 0; i < size; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        bucket* newBucket = (bucket*)malloc(sizeof(bucket));
        newBucket->value = arr[i];
        newBucket->next = NULL;

        int index = arr[i] / size;
        if (buckets[index] == NULL) {
            buckets[index] = newBucket;  
        } else {
            bucket* current = buckets[index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newBucket;
        }
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        bucket* current = buckets[i];
        while (current != NULL) {
            arr[j++] = current->value;
            bucket* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int arr[] = {29, 25, 3, 49, 9, 37, 21, 43};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("After sorting: ");
    printArray(arr, size);

    return 0;
}